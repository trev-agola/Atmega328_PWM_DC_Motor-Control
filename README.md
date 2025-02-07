### **Arduino PWM Motor Control with L298 (IC) and Overcurrent Protection**  

This project implements **PWM-based DC motor control** using an **Arduino (ATmega328P)**, **L298 dual H-Bridge IC**, **potentiometer**, and **ACS712 current sensor**. The system features:  

✅ **PWM Speed Control** using a potentiometer (0–1023 mapped to 0–255).  
✅ **L298 H-Bridge Motor Driver (IC)** for bidirectional motor control.  
✅ **Overcurrent Protection (OCP)** via ACS712, stopping the motor if current exceeds a set threshold.  
✅ **Start/Stop Button** to toggle motor operation.  
✅ **Status LEDs** for motor ON/OFF and fault detection.  
✅ **Serial Monitoring** for real-time debugging of **PWM values** and **current readings**.  

---

### **Assumptions & Design Considerations**  
- **Motor Rated Voltage:** 12V DC  
- **Motor Rated Current:** ~5A  
- **Maximum Safe Current (currentMAX):** 15A (Protection Threshold)  
- **PWM Frequency:** ~490Hz (Default Arduino PWM)  
- **Power Source:** 12V Battery or DC Supply  

---

### **Components Used**  
- **Arduino (ATmega328P)**  
- **L298 H-Bridge IC (Not Module)**  
- **ACS712 Current Sensor**  
- **Potentiometer (Speed Control)**  
- **Push Button (Start/Stop)**  
- **LED Indicators** (Motor ON, Fault)  
- **12V DC Motor**  

---

### **How It Works**  
1. The **start button** enables the motor.  
2. The **potentiometer adjusts the PWM duty cycle** for speed control.  
3. **L298 controls motor direction** via IN1 and IN2 pins.  
4. **ACS712 monitors current**, stopping the motor if it exceeds `currentMAX`.  
5. **Serial Monitor prints PWM values, current readings, and status updates.**  

---

### **Simulation in Proteus**  
This project is **fully simulated in Proteus**, considering:  
- **L298 IC wired correctly** with IN1/IN2 for direction and EN for PWM control.  
- **ACS712 sensor calibrated** for realistic current readings.  
- **Virtual Terminal for Serial Output** (TX/RX connected to Arduino).  
- **Start button with pull-down resistor** to ensure proper switching.  

---

### **Future Enhancements**  
💡 Implement **soft-start** to prevent sudden surges.  
💡 Add an **LCD or OLED display** for real-time motor data.  
💡 Integrate **Bluetooth/WiFi for remote motor control**.  
💡 Implement **PID control for precision speed regulation**.  

---

📂 **Repository Contents**:  
- `motor_control.ino` → Main Arduino code  
- `Proteus_Simulation.pdsprj` → Proteus simulation file  
- `README.md` → Project documentation  

🔗 **License:** MIT  

🚀 **Contributions are welcome!**
