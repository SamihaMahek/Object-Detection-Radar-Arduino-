# Object Detection Radar System using Arduino
An embedded IoT project that integrates an Arduino micro-controller with an ultrasonic sensor to scan, track, and map physical obstacles in a 180-degree field of view.

---

## 🚀 Project Overview
This project mimics a real-world radar mapping terminal. The system uses a servo motor to sweep an ultrasonic distance sensor across a 180-degree arc. Distance values are processed locally and broadcasted to a host machine via Serial COM communication to render a visual tracking interface.

### Key Features
* **180° Automated Sweep:** Controlled via PWM signals driving a micro-servo motor.
* **Non-Contact Spatial Scanning:** High-frequency ultrasonic sound pulses measure real-time distance obstacles.
* **Serial Telemetry Pipeline:** Transfers raw angle and distance data arrays dynamically over a USB COM interface.
* **Object Mapping Resolution:** Accurately targets obstacles up to 40cm away within a tight 15° sensor cone.

---

## 🛠️ Technology Stack
* **Hardware Core:** Arduino Uno R3, HC-SR04 Ultrasonic Sensor, SG90 Micro Servo, Jumper Wires.
* **Embedded Software:** C / C++ (Arduino IDE Framework)
* **Host Application:** Python 3 (PySerial API for telemetry stream capture)
* **Libraries Used:** `Servo.h` (Hardware abstraction), `pyserial` (Data intake logic)

---

## 📐 Hardware System Pin Mapping
* **HC-SR04 Ultrasonic Sensor:** 
  * `VCC` ➡️ Arduino 5V
  * `GND` ➡️ Arduino GND
  * `Trig` (Trigger Pulse) ➡️ Arduino Digital Pin 10
  * `Echo` (Pulse Measurement) ➡️ Arduino Digital Pin 11
* **SG90 Micro Servo Motor:**
  * `Signal` (PWM Control) ➡️ Arduino Digital Pin 12
  * `VCC` ➡️ Arduino 5V
  * `GND` ➡️ Arduino GND
