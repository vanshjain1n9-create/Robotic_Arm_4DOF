# 4-DoF Robotic Arm Controller 🤖

A 4-Degree-of-Freedom (4-DoF) robotic arm control system built using an Arduino Uno, an analog potentiometer array, and externally powered SG90 micro servos. This repository contains the firmware and architectural overview for mapping multi-channel analog inputs to real-time physical articulation.

---

## 🚀 Features
* **4-Axis Control:** Independent manipulation of Base Rotation, Shoulder Joint, Elbow Joint, and Gripper mechanics.
* **Isolated Power Architecture:** Separate logic and motor power rails to avoid voltage sags and microcontroller brownouts.
* **Unified Dual-Power Rail:** The system uses a single high-quality 5V external power supply to drive both the servos and the Arduino safely via the `VIN` pin.

---

## 🛠️ Hardware Requirements

| Component | Quantity | Description |
| :--- | :--- | :--- |
| **Arduino Uno** | 1 | Microcontroller (SMD CH340 or standard) |
| **TowerPro SG90** | 4 | 9g Micro Servo Motors |
| **10kΩ Potentiometer** | 4 | Rotary Analog Inputs (Wiper-style) |
| **External Power Supply** | 1 | 5V Supply capable of handling ≥ 2A peak current |
| **Breadboard & Jumpers** | — | For prototyping and distributing rails |
| **Robotic Arm structure** | 1 | I particularly used this :- https://amzn.in/d/0eyU1rfa (non-sponsored), you can also consider another options also.

---

## ⚡ Circuit Topology & Pin Mapping

To ensure electrical stability under load, the servos are isolated onto an external power rail, while sharing a **Common Ground** reference and a unified supply link with the Arduino via the power distribution bus.

### 1. Power Supply Bus Connections
* **External 5V Positive ($+$) Output:** Tied directly to the **Breadboard Power Rail ($+$)**.
* **External Negative ($-$ / GND) Output:** Tied directly to the **Breadboard Ground Rail ($-$)**.
* **Arduino VIN Pin:** Tied directly to the **Breadboard Power Rail ($+$)** to power the board from the external source.
* **Arduino GND Pin:** Tied directly to the **Breadboard Ground Rail ($-$)** to create a mandatory common ground path.

### 2. Actuator Output (Servos)
* **VCC (Red Wires):** Connected to the Breadboard Power Rail ($+$).
* **GND (Brown Wires):** Connected to the Breadboard Ground Rail ($-$).
* **Signal (Orange Wires):** Connected to Arduino Digital PWM Pins:
  * **Servo 1 (Base):** Pin 9
  * **Servo 2 (Shoulder):** Pin 5
  * **Servo 3 (Elbow):** Pin 11
  * **Servo 4 (Gripper):** Pin 6

### 3. Control Input (Potentiometers)
* **Pin 1 (Left):** Connected to Arduino GND (or the shared Ground Rail).
* **Pin 2 (Middle/Wiper):** Connected to Arduino Analog Pins:
* **Pin 3 (Right):** Connected to Arduino 5V output pin.
  * **Pot 1:** Pin A0
  * **Pot 2:** Pin A1
  * **Pot 3:** Pin A2
  * **Pot 4:** Pin A3

> ⚠️ **CRITICAL NOTE ON POWERING VIA VIN:** When powering the Arduino Uno via its `VIN` pin using an external supply, ensure your supply delivers a regulated 5V. Because this bypasses the standard DC barrel jack regulator, a stable, smooth input voltage is necessary to protect the logic circuits from voltage spikes.

---
