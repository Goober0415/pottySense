# pottySense
automated potty trainer
# IoT Potty Training Monitor

A smart potty training system using Particle IoT hardware that provides real-time feedback through OLED displays and RGB LEDs.

## Overview

This project creates an interactive potty training system that uses sensor feedback to detect successful attempts and provides encouraging messages through dual OLED displays and color-changing LED indicators. The system is built using Particle IoT hardware and features automatic connectivity management.

## Hardware Requirements

* Particle board (e.g., Photon)
* 2 x OLED displays (128x64 pixels)
* 1 x NeoPixel strip (12 LEDs)
* 1 x LDR/Photocell sensor
* 1 x LED indicator
* Breadboard and jumper wires

## Software Dependencies

* Particle.h
* IoTClassroom_CNM.h
* neopixel.h
* Adafruit_SSD1306.h
* Adafruit_GFX.h

## Features

* Dual OLED display feedback
* Color-coded LED indicators
* Automatic display animations
* Real-time sensor monitoring
* Encouraging messages for successful attempts

## Setup Instructions

1. Connect the hardware according to the pin assignments:
   ```markdown
   Pin Assignments:
   - LAS (LED): D3
   - PHOTO (Sensor): A0
   - OLED Display 1: 0x3C
   - OLED Display 2: 0x3D
   - NeoPixel: SPI1
   ```

2. Install required libraries through the Particle IDE:
   ```bash
   particle library install IoTClassroom_CNM
   particle library install neopixel
   particle library install Adafruit_SSD1306
   particle library install Adafruit_GFX
   ```

3. Flash the code to your Particle device.

## Operation

The system operates in the following modes:

1. **Normal Mode**
   - Displays alternating open/closed animations
   - Monitors sensor readings continuously

2. **Success Detection**
   - When sensor reading > 3:
     * Displays "GOOD JOB WYATT!!!"
     * Shows "WHAT A BIG BOY!"
     * Lights LEDs in yellow

3. **Low Reading**
   - When sensor reading < 3:
     * Lights LEDs in blue

## Technical Details

* Uses SEMI_AUTOMATIC system mode for reliable connectivity
* Implements SYSTEM_THREAD for smooth operation
* Features 1-second animation cycle for display updates
* Includes automatic serial connection handling

## License

This project is licensed under the MIT License.
