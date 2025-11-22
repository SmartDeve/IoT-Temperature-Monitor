#include <ESP8266WiFi.h>
#include "DHT.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#define DHTPIN D5
#define DHTTYPE DHT11

// Adafruit Setup
#define AIO_SERVER "io.adafruit.com"
#define AIO_SERVERPORT 1883  
#define AIO_USERNAME "adix2303"
#define AIO_KEY "aio_mTof43ZQUSNZszBKHm9dHqdAxGfz"

//LED Setup
const int red_led = D3;
const int blue_led = D1;
const int yellow_led = D2;

WiFiClient client;
// Initialize AdaFruit Client an DHT Client
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish tempSense = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temp-feed");
DHT dht(DHTPIN, DHTTYPE);

void MQTT_connect();

void setup() {
  Serial.begin(115200);
  Serial.println("Testing...");

  // Initalize LEDs
  pinMode(red_led, OUTPUT);
  digitalWrite(red_led, HIGH); // Red LED indicates that nothing is on
  pinMode(blue_led, OUTPUT); // Indicates Sensor connection and data transfer
  pinMode(yellow_led, OUTPUT); // Indicates Network Connection

  WiFi.begin("Parai", "HariBol01#"); // SSID and Password

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  digitalWrite(red_led, LOW);  
  digitalWrite(yellow_led, HIGH); 
  Serial.println(WiFi.localIP());
  dht.begin();
}

void MQTT_connect() {
  int8_t ret;

  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) {  // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    digitalWrite(blue_led, LOW);
    digitalWrite(yellow_led, LOW); 
    digitalWrite(red_led, HIGH); // Indicate that there is issue
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  
        retries--;
    if (retries == 0) {
      while (1);
    }
  }
  Serial.println("Server Connected!");
  digitalWrite(yellow_led, HIGH); 
  digitalWrite(red_led, LOW);
}




void loop() {


  MQTT_connect();
  float t = dht.readTemperature(); // Read Temperature from DHT 11 Sensor
  if (isnan(t)) { // Check if there is valid data
    Serial.println(F("Failed to read from DHT sensor! Retrying after 3 seconds"));
    digitalWrite(blue_led, LOW); //Indicate that DHT 11 is not working
    delay(3000);
     return;
  }

  if (digitalRead(blue_led) == LOW)
    digitalWrite(blue_led, HIGH);

  Serial.print(F("%  Temperature:"));
  Serial.println(t);
  delay(5000);


  if (!tempSense.publish(t)) {
    Serial.println(F("Failed"));
  } else {
    //Blink the blue LED to indicate that data is uploaded
    blinkLed(blue_led);
    Serial.println(F("OK!"));
  }
}

void blinkLed(int pin)
{
  digitalWrite(pin, LOW);
  delay(100); 
  digitalWrite(pin, HIGH);
  delay(100);



}