 # Smart Mailbox System

This project aims to build a smart mailbox system that can detect the presence of mail and notify the user via a web interface. The system utilizes an ESP8266 Wi-Fi module for wireless communication, an IR sensor to detect mail, and a servo motor to open and close the mailbox.

## Hardware Connections

The hardware connections for the smart mailbox system are as follows:

- IR Sensor: Connect the IR sensor to pin D3 of the ESP8266.
- Servo Motor: Connect the servo motor to pin D4 of the ESP8266.

## Software Setup

### Libraries

The following libraries are required for this project:

- `ESP8266WiFi`: This library provides support for connecting the ESP8266 to a Wi-Fi network.
- `Servo`: This library provides support for controlling servo motors.

### Code Overview

The `setup()` function initializes the ESP8266, connects to the Wi-Fi network, and starts the web server. It also initializes the servo motor and the IR sensor.

The `loop()` function continuously checks for incoming clients on the web server. If a client is connected, it sends a simple HTML response with the number of mails detected so far.

The `loop()` function also checks the status of the IR sensor. If mail is detected, it increments the mail count, opens the mailbox, waits for a few seconds, and then closes the mailbox.

## Usage

To use the smart mailbox system, follow these steps:

1. Connect the ESP8266 to your Wi-Fi network.
2. Open a web browser and navigate to the IP address of the ESP8266.
3. The web interface will display the number of mails detected so far.

## Troubleshooting

If you are experiencing issues with the smart mailbox system, here are a few things to check:

- Make sure that the ESP8266 is properly connected to the Wi-Fi network.
- Make sure that the IR sensor is properly connected to pin D3 of the ESP8266.
- Make sure that the servo motor is properly connected to pin D4 of the ESP8266.
- Make sure that the code is uploaded correctly to the ESP8266.

## Conclusion

The smart mailbox system is a simple and effective way to monitor your mailbox for mail. It can be easily customized to meet

