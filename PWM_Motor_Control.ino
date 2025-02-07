#define speedControlResistor      A2   
#define currentSensor             A3
#define motorONLED                8
#define faultLED                  9
#define startButton               10
#define motorEN                   6
#define motorOut                  5

// SYSTEM VARIABLES
int PWM =                         0;
int resistance =                  0;
int currentSamples =              10;
int currentADC =                  0;
double current =                  0;
bool runMotor =                   false;
float CSvoltage =                 0;
float currentMAX =                15.0;

// CALIBRATION VARIABLES
float sensitivity =               0.066; 
float offsetVoltage =             2.5; 

void setup()
{
  Serial.begin(9600);  
  Serial.println("Initializing...");

  // PIN CONFIGURATION
  pinMode(motorOut, OUTPUT);
  pinMode(motorEN, OUTPUT);
  pinMode(motorONLED, OUTPUT);
  pinMode(faultLED, OUTPUT);
  pinMode(startButton, INPUT);  // Fixed: Internal pull-down

  Serial.println("PWM Motor Control Initialized");
}

void loop()
{
  readStartButton(); 

  Serial.println(runMotor ? "Motor is ON" : "Motor is OFF");

  pwmControl();
  //OCProtection();
  delay(1000);
}

void readStartButton()
{
  if (digitalRead(startButton) == HIGH) {
    runMotor = true;
  } else {
    runMotor = false;
  }
}

void pwmControl() {
  if (runMotor) {
    resistance = analogRead(speedControlResistor);
    PWM = map(resistance, 0, 1023, 0, 255);  // Map to PWM range
    analogWrite(motorEN, PWM);  // Output PWM signal
    digitalWrite(motorOut, HIGH);
    digitalWrite(motorONLED, HIGH);
    Serial.print("PWM Output: ");
    Serial.println(PWM);
  } else {  
    analogWrite(motorEN, 0);  // Turn off PWM
    digitalWrite(motorOut, LOW);
    digitalWrite(motorONLED, LOW);
  }
}

void OCProtection() {
    currentADC = 0; // Fixed: Reset ADC value before averaging

    for (int i = 0; i < currentSamples; i++) {
        currentADC += analogRead(currentSensor);
        delay(1);
    }

    currentADC /= currentSamples;  // Get the average ADC reading
    CSvoltage = (currentADC / 1023.0) * 5.0;  // Convert ADC to voltage
    current = (CSvoltage - offsetVoltage) / sensitivity;  // Convert to current

    Serial.print("Current: ");
    Serial.print(current);
    Serial.println(" A");

    if (current > currentMAX) {
      digitalWrite(faultLED, HIGH);  // Fixed: Turn on fault LED
      runMotor = false;
      analogWrite(motorEN, 0);  // Fixed: Turn off PWM properly
    }
}
