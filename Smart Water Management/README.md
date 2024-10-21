# Smart Water Management System

## Overview
The **Smart Water Management** system is designed to monitor water usage in real-time. This project leverages an ESP32 microcontroller and a water flow sensor to collect data on water flow and display it on a web-based dashboard hosted directly through the ESP32. This project provides an efficient and low-cost way to track water consumption and detect leaks.

## Features
- **Real-time Monitoring**: Track water flow and usage in real-time.
- **Web Dashboard**: The ESP32 hosts a simple website to display live data.
- **Low Power**: ESP32 is used for its energy-efficient performance and Wi-Fi connectivity.
- **Customizable**: Modify the code to adjust thresholds, display formats, or expand functionality.

## Components Used
1. **ESP32**: Wi-Fi enabled microcontroller.
2. **Water Flow Sensor**: Measures the flow rate of water.
3. **Jumper Wires**: For connections between ESP32 and sensor.
4. **Breadboard**: For easy circuit prototyping.

## How It Works
1. The **Water Flow Sensor** measures the rate of water flow in liters per minute (L/min) by detecting the number of pulses generated.
2. The **ESP32** collects data from the sensor, processes the information, and calculates the amount of water used.
3. The ESP32 then serves a website that can be accessed via a local network, where users can view the real-time data such as flow rate, total water consumption, etc.

## Setup and Installation

### Hardware Connections:
- **ESP32 Pinout**:
  - `5V` -> Water Flow Sensor VCC
  - `GND` -> Water Flow Sensor GND
  - `D2` -> Water Flow Sensor Signal

### Software Setup:
1. **Install Arduino IDE**: Make sure you have the Arduino IDE installed on your system.
2. **ESP32 Board Setup**: Add ESP32 board to your Arduino IDE. You can do this by following [this guide](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/).
3. **Library Installation**: Install the following libraries:
   - `WiFi.h` (for handling Wi-Fi connections)
   - `WebServer.h` (for serving the website)
4. **Upload Code**: Write your ESP32 sketch or use the provided code in this repository and upload it to the ESP32.
5. **Access Dashboard**: After uploading the code, connect to the ESP32's local IP address (displayed in the serial monitor) via a browser to view the real-time data.

## Usage
1. Power the ESP32 using a USB cable or external power supply.
2. Open a browser and connect to the ESP32’s local IP to access the real-time water usage dashboard.
3. Monitor the water flow rate and total consumption from any device connected to the local network.

## Code Structure
- **/src**: Contains the ESP32 code.
- **/web**: HTML and JavaScript files for the web-based interface.
- **/docs**: Documentation on setup and other details.

## Future Enhancements
- **Alert System**: Add notifications or alerts for abnormal water usage or potential leaks.
- **Data Logging**: Store historical data to analyze water usage trends over time.
- **Mobile App Integration**: Create a mobile app for better accessibility.

## License
This project is licensed under the MIT License 

## Team members
- **Rithvik Matta** - [GitHub Profile](https://github.com/rtk5)
- **Rishi A Sheth** - [GitHub Profile](https://github.com/RishiASheth)
- **Rishil** 
- **Rithish Bharath** 



