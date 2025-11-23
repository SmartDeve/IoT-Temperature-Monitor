
# Esp8266 Based Temperature Monitor

In this project, we develop an IoT Temperature Monitoring System using the ESP8266 NodeMCU microcontroller. The system reads real-time temperature data from the surrounding environment and uploads it to Adafruit IO, a cloud-based IoT platform.

The ESP8266 connects to a Wi-Fi network and continuously sends sensor data to the internet, where it can be visualized through dashboards, gauges, or charts on Adafruit IO. This enables remote monitoring of temperature from anywhere in the world.

This project forms the foundation for wireless temperature-sensing applications, which play an important role in both home automation and industrial environments. Examples include:

* Smart home climate control

* Server room temperature monitoring

* Industrial process supervision

* Greenhouse environment management

* Food storage and cold-chain monitoring

By integrating low-cost hardware with powerful online IoT services, this project demonstrates how simple embedded systems can be enhanced with cloud connectivity to build scalable and real-time monitoring solutions.



## ESP8266 (NodeMCU)

The ESP8266 is a low-cost Wi-Fi microchip by Espressif Systems, commonly used for Internet of Things (IoT) projects. It features a 32-bit processor and includes a full TCP/IP stack for Wi-Fi connectivity. The ESP8266 is popular for its affordability, compact size, and ability to run self-contained applications or act as a Wi-Fi bridge to other microcontrollers.
## DHT11 Temperature Sensor

DHT11 is a low-cost digital sensor for sensing temperature and humidity.  This sensor can be easily interfaced with any micro-controller such as Arduino, Raspberry Pi etc… to measure humidity and temperature instantaneously.

DHT11 humidity and temperature sensor is available as a sensor and as a module. The difference between this sensor and module is the pull-up resistor and a power-on LED. DHT11 is a relative humidity sensor.  To measure the surrounding air this sensor uses a thermistor and a capacitive humidity sensor.

DHT11 sensor consists of a capacitive humidity sensing element and a thermistor for sensing temperature.  The humidity sensing capacitor has two electrodes with a moisture holding substrate as a dielectric between them. Change in the capacitance value occurs with the change in humidity levels. The IC measure, process this changed resistance values and change them into digital form.


## Installation

Install the following softwares and drivers for this project.

- Arduino IDE
- CH340C driver
- Install ESP8266 Board in the Arduino IDE
- Install Adafruit Sensor Library


    
## Hardware 

- NodeMcu V3 (ESP8266MOD)
- Arduino UNO
- DHT 11 Sensor Module
- Jumper Wires
- Breadboard
- 3 LEDs (Red, Yellow And Blue)
## Circuit Diagram

<img width="600" height="533" alt="circuit_image (5)" src="https://github.com/user-attachments/assets/9563b533-0789-46d4-a0dd-ad5a0f5e8b55" /><br>

The above circuit diagram shows the hardware setup used to build the IoT Temperature Monitor. The DHT11 sensor is connected to the NodeMCU through its data and ground pins, while the Arduino Uno is used only as a stable 5V power source for the sensor, since the NodeMCU’s 3.3V output is not sufficient to power the DHT11 reliably.

Three LEDs are included in the circuit to visually indicate the system’s status:

* **Red LED**

    This LED turns ON when the system is powered, but not connected to the internet.

* **Yellow LED**

    This LED indicates that the NodeMCU is successfully connected  to Wi-Fi and Adafruit IO.

* **Blue LED**

    This LED confirms that the DHT11 sensor is working properly and blinks every time data is uploaded to the Adafruit IO feed.




## Documentation

- [ESP8266WiFi Library](<https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html>)
- [DHT Library](<https://www.arduinolibraries.info/libraries/dht-sensor-library>)
- [AdaFruit MQTT Library](<https://github.com/adafruit/Adafruit_MQTT_Library>)



## API Reference

- [AdaFruit IO](<https://io.adafruit.com/>)
- [Board Manager for ESP8266](<http://arduino.esp8266.com/stable/package_esp8266com_index.json>)

#### Get Your AdaFruit Credentials

| Parameter | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `User Name` | `string` | **Required**. Your User Name |
| `Active Key` | `string` | **Required**. Your API key |
| `Feed Key` | `string` | **Required**. Your Feed key |

You will find these in your AdaFruit IO Dashboard once you sign up! We will learn that step by step in the next section.


## Setup Circuit and AdaFruit IO

- Create the hardware setup using the given ciruit diagram.
- Sign up on AdaFruit IO.
- Create a feed on the platform. 
- Create a new sketch in Arduino IDE and paste the code from *iot_sketch_esp* uploaded in this repository

Retieve the AdaFruit Username and AIO_KEY and paste it in these variables in the code file.

```
#define AIO_USERNAME "<Your Username>"
#define AIO_KEY "<Your Key>"

```

Replace the WiFi Authentication with yours.

```
WiFi.begin("<SSID>", "<Passworrd>"); // SSID and Password

```
Make sure to put the right PIN details.

```
#define DHTPIN <Your DHT PIN> // Example D1, D2 etc.
const int red_led =<RED LED PIN>;
const int blue_led = <BLUE LED PIN>;
const int yellow_led = <YELLOW LED PIN>;
```

- Now go to **File->Preferences** and paste the given ESP8266 Board Manager URL in previous section in ***Additonal board managers URLs*** 

- Select the **Port** and **Board** (NodeMCU 1.0) through Tools and then Click **Upload**!

Note: To find your COM Port, Open **Device Manager** and Under **Ports (COM and LPT)**, you will see something like this..

<img width="300" height="183" alt="Screenshot 2025-11-22 095510" src="https://github.com/user-attachments/assets/1d76803c-4e99-4e3f-aa84-b735b8079b51" />

<br>
<br>

### Here is the final setup:

<br>

<img width="500" height="283" alt="Screenshot 2025-11-22 095510" src="https://github.com/user-attachments/assets/0069c00a-e2d1-4373-8dce-3ba118f70b71" />
<br>

**Not Connected to the Internet**

<br>
<br>
<img width="500" height="283" alt="Screenshot 2025-11-22 095510" src="https://github.com/user-attachments/assets/e141e281-05d5-4783-a5c7-4da49d08dc78" /><br>

**Connected to the Internet and Sending Data**

<br>

<img width="1000" height="509" alt="AdaFruit Graph" src="https://github.com/user-attachments/assets/467e104a-db73-40e9-8461-5fe2b8a03781" />

**Live Data Graph**

<br>

<img width="900" height="460" alt="AdaFruit Live Data" src="https://github.com/user-attachments/assets/7b530054-9e9f-4b17-b41a-f2b323dc9985" />

**Live Data Graph**

## Appendix

- <https://ieeexplore.ieee.org/abstract/document/8502562>
- <https://ieeexplore.ieee.org/abstract/document/8728426>
