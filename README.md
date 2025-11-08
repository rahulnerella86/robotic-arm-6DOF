# 🦾 Arduino-Based 6DOF Robotic Arm Using Rotary Encoder

This project demonstrates a low-cost, Arduino-controlled 6 Degrees of Freedom (6DOF) robotic arm that uses a rotary encoder and three push buttons for manual servo control. Each servo represents a robotic joint, and users can switch between servos and adjust their angles precisely using the encoder interface.

---

## ⚙️ Features
- Control six servo motors individually via an encoder and three buttons  
- Rotary encoder adjusts the servo angle precisely  
- Buttons select next/previous servo and modify angles  
- Encoder push-button resets servo angle to 1°  
- Compact, low-cost, and ideal for learning and research projects  

---

## 🧠 System Overview
The robotic arm replicates human-like motion using six servo motors controlled by an Arduino microcontroller.  
A rotary encoder changes the servo angle, while three push buttons handle servo selection and control mode switching.

---

## 🧩 Components Used
| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno / Nano | 1 | Main controller |
| Servo Motors | 6 | Arm joints |
| Rotary Encoder | 1 | For angle control |
| Push Buttons | 3 | For servo selection and control |
| Power Supply | 1 | 5V or 9V regulated |
| Jumper Wires | — | Connections |

---

## 🔌 Pin Connections
| Component | Arduino Pin |
|------------|--------------|
| Encoder CLK | D2 |
| Encoder DT | D4 |
| Encoder SW | D12 |
| Button 1 (Next Servo) | D7 |
| Button 2 (Previous Servo) | D8 |
| Button 3 (Angle Adjust) | D13 |
| Servo 1 | D3 |
| Servo 2 | D5 |
| Servo 3 | D6 |
| Servo 4 | D9 |
| Servo 5 | D10 |
| Servo 6 | D11 |
---

## 🚀 Working Principle
- Rotate the **encoder** → changes the current servo’s angle  
- Press **Button 1** → move to next servo  
- Press **Button 2** → move to previous servo  
- Press **Button 3** → apply angle change  
- Press **encoder button** → reset servo angle to 1°  

---

## 🧾 Objectives
1. Develop a 6DOF robotic arm using Arduino and servo control  
2. Implement encoder-based manual angle control  
3. Create intuitive button navigation for joint selection  
4. Achieve precise, stable, and cost-effective operation  
5. Provide an open-source design for education and prototyping  

---

## 🧩 Block Diagram
                +----------------------+
                 |   ROTARY ENCODER     |
                 +----------+-----------+
                            |
                            v
                      +-----+-----+
                      |   ARDUINO  |
                      +-----+-----+
                            |
        +-------------------+-------------------+
        |                                       |
        v                                       v
 +---------------+                     +----------------+
 |    BUTTONS    |                     |  POWER SUPPLY  |
 +---------------+                     +----------------+
        |                                       |
        v                                       v
                      +----------------+
                      |  DRIVER CIRCUIT |
                      +--------+--------+
                               |
                               v
                 +---------------------------+
                 |     6DOF ROBOTIC ARM       |
                 +---------------------------+


## 🔬 Tests Conducted
- Servo angle accuracy and range test  
- Encoder pulse and debounce validation  
- Response time and stability under load  
- Power supply and servo heat test  
- Continuous operation endurance test  

---

## 📊 Results and Observations
- Stable servo control with minimal jitter  
- Accurate angle adjustment per encoder step  
- Smooth transitions between servos  
- System performed reliably under continuous load  

---

## 📚 References
Publications

Tan Yiwen, Zhang Xiaoping, and Li Yifan, “Control method of low ripple adjustable DC regulated power supply based on Buck-Boost inverter circuit,” Journal of Electronic Measurement and Instrumentation, vol. 6, pp. 204–212, 2024.

Zhang S., Hanx W., and Lir P., “Improved remote regulated power supply control scheme in improved flyback converter,” Journal of Beijing University of Aeronautics and Astronautics, vol. 50, no. 4, pp. 1229–1239, 2024. (in Chinese) doi: 10.13700/j.bh.1001-5965.2022.0458.

Liang Y., Li A.Z., and Chen W.H., “Design of a downhole high-power voltage-regulated power supply system for logging-while-drilling systems based on PWM,” Applied Geophysics, vol. 20, pp. 1–8, 2023. https://doi.org/10.1007/s11770-022-0959-x
.

Chen Haiqing, Chen Wencong, Zhang Renxing, “A Linear Regulated Power Supply for Piezoelectric Ceramic Driving Circuit,” Sichuan Institute of Piezoelectric and Acoustooptic Technology, 2021. doi: 10.11977/j.issn.1004-2474.2021.05.017.

Cabrera-Peña J.M., Leon R., Ortega S., Fabelo H., Quevedo E., and Callico G.M., “Regulated power supply with high power factor for hyperspectral imaging applications,” Applied Sciences (Basel, Switzerland), vol. 15, no. 3, p. 1093, 2025. https://doi.org/10.3390/app15031093
.
---

## 👨‍💻 Contributors
- **Rahul Nerella (24BEC0071)
