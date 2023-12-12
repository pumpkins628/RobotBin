#include <Servo.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Setup servo motor and ultrasonic sensor 
Servo myservo;
const int TrigPin = 11;
const int EchoPin = 12;
const int ServoPin = 8;

// Setup DHT22
const int DHTPin = 2;
#define DHTTYPE DHT22
DHT dht(DHTPin, DHTTYPE);

// Setup OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Calculate and return the distance measured by the ultrasonic sensor
float GetUltrasonicDistance() {
    float distance;
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, LOW);
    distance = pulseIn(EchoPin, HIGH) / 58.00;
    return distance;
}

void drawDegreeSymbol(int x, int y) {
    display.drawCircle(x, y, 2, SSD1306_WHITE); // Draw a circle
    display.setCursor(x + 4, y - 3); // Set the position of character 'C'
    display.print("C"); // Draw 'C'
}

void setup() {
    pinMode(TrigPin, OUTPUT);
    pinMode(EchoPin, INPUT);
    pinMode(ServoPin, OUTPUT);
    myservo.attach(ServoPin);
    myservo.write(0);
    delay(10);

    Serial.begin(9600);

    dht.begin();

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
    display.display();
    delay(2000);
    display.clearDisplay();
}

void loop() {
    float UltrasonicDistance = GetUltrasonicDistance();

    Serial.print("Distance: ");
    Serial.print(UltrasonicDistance);
    Serial.println(" cm");

    if(UltrasonicDistance < 14) {
        myservo.write(90);
       // delay(1000);
    } else {
        myservo.write(0);
       // delay(10);
    }
delay(100);
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    String humidityStr = "Hum:" + String(humidity, 1) + " %";
    String tempStr = "Tem:" + String(temperature, 1);

    display.setCursor(5, 0);
    display.print(humidityStr);

    display.setCursor(5, 25);
    display.print(tempStr);

    
    drawDegreeSymbol(109, 28); // The coordinates here need to be adjusted to fix the temperature
  display.display();
  
  delay(5000); // Show 5 seconds

    display.clearDisplay(); // Declare the screen

    // Show  "Feed me!" 
    display.setTextSize(2); // The size of font
    display.setTextColor(SSD1306_WHITE);
    String feedMeStr = "Feed me!";
    int16_t x1, y1;
    uint16_t w, h;
    display.getTextBounds(feedMeStr, 0, 0, &x1, &y1, &w, &h);
    display.setCursor((SCREEN_WIDTH - w) / 2, (SCREEN_HEIGHT - h) / 2);
    display.print(feedMeStr);
    display.display();
     delay(5000); 
}
