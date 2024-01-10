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

Here is a picture for wiring, if you want to check more details ` (See wiring ) ` to get raw file

<img width="888" alt="a49e80fe65d45305544b7690eb4d2cd" src="https://github.com/pumpkins628/RobotBin/assets/146323702/61398654-e4f6-4f0d-a4f9-ebc7880eb914">


**Servo Motor:** Its control pin is connected to digital pin 8 on the Arduino Uno. The servo motor will be used for the automatic opening and closing of the trash bin lid.

**Ultrasonic Sensor:** It utilizes two digital pins. The Trig pin is connected to digital pin 11, responsible for sending out ultrasonic waves, and the Echo pin is connected to digital pin 12, used for receiving the echo. This setup allows the sensor to calculate distances by measuring the time difference between sending and receiving ultrasonic pulses.

**DHT22 Temperature and Humidity Sensor:** This sensor's data pin is connected to digital pin 2 on the Arduino Uno. The DHT22 will provide real-time environmental temperature and humidity readings.

**OLED Display:** The display is connected via I2C communication, using pins A4 (SDA) and A5 (SCL). This connection method simplifies the wiring as it requires only two wires for data and control signal transmission.

It's important to be cautious during the wiring process to avoid incorrect connections of these pins. Such an arrangement ensures that each component can function correctly and communicate with the Arduino Uno for the desired operations of your smart trash bin project.

### Assembly

Drill holes on desktop trash bin to fit my design and place various components in their designated spots, securing them in place. Soldering the components to jumper wires significantly increased the system's stability, preventing malfunctions caused by poor connections.

![598abce3872a138931277ccd697f45c](https://github.com/pumpkins628/RobotBin/assets/146323702/5c542c42-5b90-44b4-bdd3-323df5b14dbf)

Each component needs a power supply, but the Arduino Uno has limited power interfaces, not enough for all components. To solve this, use a small stripboard to extend the power and ground lines from the Arduino Uno and soldered the rest of the components to this board. This ensured that all components received adequate power.

![f5198ffd3fad454602b6a7f4301454b](https://github.com/pumpkins628/RobotBin/assets/146323702/e4c890e8-90ab-4916-99a7-cbd3d640020a)

Next, craft an "arm" mechanism to open the trash bin's lid. Choose two wooden sticks of different lengths and fixed them inside a straw, forming an "L" shape. When the servo's angle changes, the shorter stick moves, acting like a lever at the joint, causing the longer stick to pull the lid open, enabling automatic lid opening.

**The lid is open when the straws and sticks are in the state**

<img width="298" alt="image" src="https://github.com/pumpkins628/RobotBin/assets/146323702/9bc0f6ca-5c7d-43b7-9d7a-a24ed2c0c931">

**The lid is open when the straws and sticks are in the state**

<img width="292" alt="image" src="https://github.com/pumpkins628/RobotBin/assets/146323702/c9f1835e-c4d0-4588-a928-b2283b611eba">

## Coding section

Just check ` (Final_part 2.0) ` for the full code

In the setup() function, all devices and sensors are initialized and set to their appropriate modes (input or output). Specifically, the servo is attached to its pin and assigned to its initial position. Serial communication is also initialized for debugging and data output. This allows us to visually receive data from the sensors and check the serial monitor for correctness when the system isn't functioning as expected.

The ultrasonic sensor first checks the distance in the main loop() function. If the detected distance is less than a set threshold (here, 14cm), the servo is instructed to open the trash bin lid (using my servo. write(0)). Otherwise, it closes. This design allows the trash bin to open automatically when an object approaches, offering convenience and reducing contact.

Additionally, a timer in the code controls the content update of the OLED display. For every specific interval (set here as 5 seconds), the display alternates between "Feed me!" and the readings from the DHT22 sensor. This enhances user interaction and keeps users informed about the environmental conditions around the trash bin.

**The triggering conditions for the servo and the content displayed on the OLED can be customized according to your needs, allowing you to create your intelligent lid-opening trash bin. For example, you could set the system's activation distance threshold to 20cm, keeping the bin lid open longer. You could also change the "Feed me!" display to "Smile" as a personal encouragement.**


# Hope you enjoy thie projct and build your own RobotBin! 
If you want to get more information, please click here.
[Report for CASA0016.pdf](https://github.com/pumpkins628/RobotBin/files/13882155/Report.for.CASA0016.pdf)


