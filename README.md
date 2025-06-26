## Human Patient Monitoring System ##

**Project Overview**

This **Arduino-based Human Patient Monitoring System** is designed to collect vital health data, including temperature, ECG signals, and heart rate, using various sensors. The collected data is displayed on an LCD screen. While the system is prepared for Wi-Fi transmission using an ESP-01 module, the full implementation for sending data to external platforms will be added in a future phase. This foundational setup allows for local data monitoring and prepares the system for advanced IoT integration.

---

🔍 **How It Works**

1.  **Sensor Data Acquisition**
    - An MLX90614 infrared sensor measures body temperature.
    - An AD8232 ECG sensor captures electrocardiogram signals.
    - A Pulse Sensor detects heart rate (BPM).

2.  **Data Processing & Display**
    - Sensor readings are processed by the Arduino microcontroller.
    - Real-time temperature, ECG values, and heart rate are displayed on a 16x2 LCD screen.
    - Data is also output to the serial monitor for debugging and monitoring.

3.  **Wi-Fi Connectivity (Future Implementation)**
    - An ESP-01 Wi-Fi module is used to establish connection to a specified Wi-Fi network.
    - The module is reset and configured to station mode for network connection.
    - This prepares the system for future functionality, such as sending collected health data to a server or IoT platform, once the necessary code is implemented.

---

🔧 **Key Technologies**

- **Microcontroller**: Arduino
- **Temperature Sensor**: MLX90614 (Infrared)
- **ECG Sensor**: AD8232
- **Heart Rate Sensor**: Pulse Sensor
- **Display**: 16x2 LCD
- **Wi-Fi Module**: ESP-01
- **Communication**: I2C, SoftwareSerial
- **Programming Language**: C++ (Arduino Sketch)

---

📦 **Setup Instructions**

**1. Hardware Connections**  
    - **LCD Connections**:
        - VSS (Pin 1) $\rightarrow$ GND  
        - VDD (Pin 2) $\rightarrow$ 5V  
        - VO (Pin 3) $\rightarrow$ Middle pin of a potentiometer (others to 5V and GND)  
        - RS (Pin 4) $\rightarrow$ Arduino Digital Pin 12  
        - RW (Pin 5) $\rightarrow$ GND  
        - EN (Pin 6) $\rightarrow$ Arduino Digital Pin 11  
        - D4 (Pin 11) $\rightarrow$ Arduino Digital Pin 5  
        - D5 (Pin 12) $\rightarrow$ Arduino Digital Pin 4  
        - D6 (Pin 13) $\rightarrow$ Arduino Digital Pin 3  
        - D7 (Pin 14) $\rightarrow$ Arduino Digital Pin 2  
        - A (Anode, Pin 15) $\rightarrow$ 5V (through a 220-ohm resistor)  
        - K (Cathode, Pin 16) $\rightarrow$ GND  
    - **MLX90614 Sensor**:  
        - VIN $\rightarrow$ 5V  
        - GND $\rightarrow$ GND  
        - SCL $\rightarrow$ Arduino A5  
        - SDA $\rightarrow$ Arduino A4  
    - **AD8232 ECG Sensor**:  
        - Output $\rightarrow$ Arduino Analog Pin A0  
        - GND $\rightarrow$ GND  
        - 3.3V $\rightarrow$ 3.3V  
    - **Pulse Sensor**:  
        - Signal $\rightarrow$ Arduino Analog Pin A1  
        - VCC $\rightarrow$ 5V  
        - GND $\rightarrow$ GND  
    - **Powering the System**:  
        - Sony 6800mAh 18650 Battery: Connect positive terminal to Vin & negative   terminal to GND via a battery holder.  

**2. Software Requirements**
    - Arduino IDE  
    - Libraries (install via Arduino Library Manager):  
        - `Wire.h` (usually built-in)  
        - `Adafruit MLX90614`  
        - `LiquidCrystal` (usually built-in)  
        - `PulseSensorPlayground`  
        - `SoftwareSerial` (usually built-in)  

**3. Configure Wi-Fi Credentials**  
    - Open the Arduino sketch (`.ino` file).  
    - Locate the `ssid` and `password` variables.  
    - Replace `"your_SSID"` and `"your_PASSWORD"` with your actual Wi-Fi network credentials:  

        ```cpp  
        const char* ssid = "Your_WiFi_SSID";  
        const char* password = "Your_WiFi_Password";  
        ```  

**4. Upload Code to Arduino**  
    - Connect your Arduino board to your computer.  
    - Select the correct board and port in the Arduino IDE.  
    - Upload the provided sketch to your Arduino.  

---

⚙️ **Workflow Summary**


                Sensors
                   ↓
         Arduino Microcontroller
                   ↓
              LCD Display
                   ↓
         ESP-01 Wi-Fi Module
                   ↓
           Server/IoT Platform


---

🌟 **Future Enhancements**

- Implement data transmission to a cloud-based IoT platform (e.g., Firebase, AWS IoT, Adafruit IO).
- Develop a mobile application or web dashboard to visualize the collected health data.
- Add alarms or notifications for abnormal readings.
- Incorporate SD card module for local data logging.
- Improve power management for extended battery life.

---

🧪 **Deployment History**

* **Initial Prototype**: Integrated sensors, LCD display, and basic data readings.
* **Wi-Fi Integration Prep**: Added ESP-01 module for network connectivity setup.
* **Code Refinement**: Improved sensor reading logic and initial Wi-Fi connection stability.

---

**This project provides a foundational health monitoring system, ready for further development into a comprehensive IoT solution.**

---

**Author:** Ferdous Hasan  
**Date:** June 24, 2024