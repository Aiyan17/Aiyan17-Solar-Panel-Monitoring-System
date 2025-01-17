# Solar Panel Monitoring System

This repository contains the design, code, and documentation for the **Solar Panel Monitoring System** project, which monitors key performance metrics of a solar panel in real time. It measures and displays **voltage**, **current**, and **power output**, providing insights into the solar panel's performance.

## Features
- **Real-Time Monitoring**: Displays voltage (V), current (mA), and power (mW) on a 16x2 LCD screen.
- **Arduino Integration**: Powered by an Arduino Uno for processing and data handling.
- **Precision Measurement**: Uses a voltage divider and op-amp circuit for accurate readings.
- **Debugging**: Outputs detailed performance metrics to the serial monitor.

## How It Works
The system consists of:
- A **voltage divider** circuit to measure the solar panel's output voltage.
- An **op-amp circuit** with a shunt resistor to measure current.
- The Arduino Uno processes these inputs and calculates the power output.
- Data is displayed on an LCD and logged to the serial monitor for analysis.

### Circuit Schematic
The circuit schematic is included in the repository as `SchematicSPMS.pdf`. This document details the connections and components used in the project.

## Components
- **Arduino Uno**
- Resistors (R1, R2, Rf, Ri, Rsh)
- 16x2 LCD Display
- Op-amp
- Shunt resistor
- Breadboard and jumper wires

## Code
The Arduino code (`SolarPanelMonitoringSystem.ino`) is written to:
1. Read voltage and current inputs.
2. Calculate the power output.
3. Display the results on the LCD.
4. Log data to the serial monitor for debugging purposes.

## Setup
1. Assemble the circuit as shown in `SchematicSPMS.pdf`.
2. Upload the `SolarPanelMonitoringSystem.ino` code to the Arduino Uno using the Arduino IDE.
3. Power the Arduino and connect the solar panel.
4. View the data on the LCD and serial monitor.

## Usage
- Monitor solar panel performance in real time.
- Use serial output for detailed analysis and debugging.
