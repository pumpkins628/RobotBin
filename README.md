# RobotBin
## Introduction
Trash bins are a vital component of everyday life, tailored for different purposes and environments. Desktop trash bins, a widely used type, are particularly crucial in keeping spaces clean, both at home and in offices. Their frequent use and convenience are especially beneficial for those with conditions like rhinitis or severe colds, as these bins help maintain a clean living environment, directly impacting personal health.

In the wake of the COVID-19 pandemic, the necessity of reducing virus transmission in daily activities has become evident. Traditional desktop trash bins, which require manual lid opening, could pose a risk in this context. Addressing this, I am developing an automatic-lid-opening desktop trash bin. This innovative bin maintains its core purpose while minimizing contact-based virus transmission, enhancing both its functionality and user convenience.

The project integrates additional sensors for environmental temperature and humidity, enhancing the bin's utility and interaction with its surroundings. Its design, inspired by the charming “WALL-E” robot, aligns well with the sensor features and aims to deliver a positive emotional experience. The bin's smart lid opens automatically when an object approaches, thanks to a servo-driven mechanism. After disposing of trash, the lid closes automatically. An OLED display on the lid continuously shows the current temperature and humidity, alternating every five seconds with the playful message "Feed me." This project is not only a response to the heightened hygiene awareness during the pandemic but also a testament to how technological innovation can elevate the quality of daily life. By integrating sensor technology and smart control, this trash bin represents a harmonious blend of modern technology and practicality, potentially catering to a broad market. It's poised to play a significant role in both residential and office settings, contributing to health and environmental monitoring.

![4ef4aa1b4513d19baf69ad6ec973db7](https://github.com/pumpkins628/RobotBin/assets/146323702/cad1a8b9-9130-4985-bf61-2ce48d46104d)

## Hardware section

### Required components
|Hardware |Description |
| --- | --- |
| Desk Trash Bin*1 | The main body of the project, carrying the main functions of the project |
| Arduino Uno *1 | Control of components and data processing capabilities |
| Ultrasonic Distance Sensor*1 | Get distance data |
| DHT22*1 | Get humanity and temperature data |
| OLED*1 | Display data |
| Servo*1 | Provides the power to open the lid |
| Stripboard*1 | Connect each component to ensure simple and neat wiring |
| Stick*2 | Coordinate with servo to pull the lid  |

### Wiring up

Here is a picture for wiring, if you want to check more details ` （See ) ` to get raw file

Servo Motor: Its control pin is connected to digital pin 8 on the Arduino Uno. The servo motor will be used for the automatic opening and closing of the trash bin lid.

Ultrasonic Sensor: It utilizes two digital pins. The Trig pin is connected to digital pin 11, responsible for sending out ultrasonic waves, and the Echo pin is connected to digital pin 12, used for receiving the echo. This setup allows the sensor to calculate distances by measuring the time difference between sending and receiving ultrasonic pulses.

DHT22 Temperature and Humidity Sensor: This sensor's data pin is connected to digital pin 2 on the Arduino Uno. The DHT22 will provide real-time environmental temperature and humidity readings.

OLED Display: The display is connected via I2C communication, using pins A4 (SDA) and A5 (SCL). This connection method simplifies the wiring as it requires only two wires for data and control signal transmission.

It's important to be cautious during the wiring process to avoid incorrect connections of these pins. Such an arrangement ensures that each component can function correctly and communicate with the Arduino Uno for the desired operations of your smart trash bin project.





