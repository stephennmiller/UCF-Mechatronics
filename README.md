# UCF Mechatronics Projects

## Overview
This repository contains my mechatronics projects from UCF coursework, organized by lab assignments. Each lab folder includes source code and details about the hardware and functionality.

- **Author**: Stephen Miller
- **Updated**: February 25, 2025

## Lab 3: Joystick and Photoresistor Controls

### Description
Lab 3 consists of two Arduino projects:
1. **Joystick Control**: Uses a joystick to adjust a servo angle (X-axis), LED brightness (Y-axis), and toggle a buzzer (switch).
2. **Photoresistor Extra**: Turns an LED on when ambient light drops below a threshold, displaying the light level.

### Created
- February 22-23, 2021 (updated for GitHub in 2025)

### Hardware
- Arduino (any model with PWM pins)
- **Joystick Part**: Joystick module, servo (e.g., SG90), LED, buzzer
- **Photoresistor Part**: Photoresistor (LDR) with 10kΩ pull-down resistor, LED
- Breadboard and jumper wires

### Pin Connections
#### Joystick Control
| Component       | Arduino Pin |
|-----------------|-------------|
| Joystick X      | A0          |
| Joystick Y      | A1          |
| Joystick Switch | 2           |
| Servo           | 9           |
| LED             | 11 (PWM)    |
| Buzzer          | 6           |

#### Photoresistor Extra
| Component    | Arduino Pin |
|--------------|-------------|
| Photoresistor| A0          |
| LED          | 7           |

### Functionality
- **Joystick Control**:
  - X-axis: Servo angle (0-180°).
  - Y-axis: LED brightness (0-255 PWM).
  - Switch: Buzzer on/off (100 Hz).
  - Serial: X-axis and servo voltages.
- **Photoresistor Extra**:
  - LED on if light < 150 (0-1023 range), off otherwise.
  - Serial: Light level reading.

### Setup Instructions
1. **Joystick**: Connect as per table, upload `Lab-3/Lab3_Joystick.ino`, open Serial Monitor (9600 baud).
2. **Photoresistor**: Connect as per table, upload `Lab-3/Lab3_Photoresistor.ino`, open Serial Monitor (9600 baud).

### Files
- `Lab-3/Lab3_Joystick.ino`: Joystick control sketch.
- `Lab-3/Lab3_Photoresistor.ino`: Photoresistor extra sketch.