## Code for the LCD-display, Active buzzer and Push button

// @author Sara Benali
// This section of the program retrieves saved appointments and presents them on the LCD-display. It monitors local time
// to trigger the buzzer alarm and provides functionality to stop the buzzer with a button press.
// License type: MIT License

```
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define WIFI_SSID "iotroam"
#define WIFI_PASSWORD "LXfu9HZkNP"

DynamicJsonDocument jsonBuffer(1024);
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

// set the LCD number of columns and rows
// set LCD address, number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

int buzzerPin = 16;
int buttonPin = 14;
int buttonState;
int ORG_X = 0;
int ORG_Y = 0;

int currentIndex = 0;

int serialStartNumber = 9600;
int initializationDelay = 1000;
int smallDelay = 10;
int dataUpdateDelay = 30000;
int connectionRetryDelay = 5000;

int lcdCol = 5; 
int lcdRow = 4;
int timeOffset = 3600;

int maxTime = 60000;


void setup() {
  // Initialize the Serial-connection on a speed of 115200 b/s
  Serial.begin(serialStartNumber);

  // Your WeMos tries to connect to your Wi-fi network
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Keep the while-statement alive as long as we are NOT connected to the Wi-fi network.
  while (WiFi.status() != WL_CONNECTED) {
    delay(initializationDelay);
  }

  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // initialize LCD
  lcd.begin(lcdCol, lcdRow);
  lcd.init();

  // turn on LCD backlight
  lcd.backlight();

  timeClient.begin();
  timeClient.setTimeOffset(timeOffset);
}

void loop() {
  makeSound();
}


void makeSound() {
  // Initialize a wi-fi client & http client
  WiFiClient client;
  HTTPClient httpClient;

  // Set the URL of where the call should be made to.
  httpClient.begin(client, "http://benalis2.loca.lt/get_date.php");

  // Make the GET-request, this returns the HTTP-code.
  int httpCode = httpClient.GET();

  // Check if the response is fine.
  if (httpCode == HTTP_CODE_OK) {  // HTTP_CODE_OK == 200

    String payload = httpClient.getString();
    deserializeJson(jsonBuffer, payload);

    String appointmentDateTime = jsonBuffer[currentIndex]["date_time_appointment"];
    String appointmentName = jsonBuffer[currentIndex]["name"];

    for (int i = 0; i <= jsonBuffer.size(); i++) {
      timeClient.update();
      String appointmentTime = jsonBuffer[i]["date_time_appointment"];
      String currentTime = timeClient.getFormattedTime();

      int indexDate = appointmentTime.indexOf(" ");
      String date = appointmentTime.substring(indexDate + 1);

      int indexTime = date.indexOf(":");
      int appointmentHour = date.substring(0, indexTime).toInt();
      int appointmentMinute = date.substring(indexTime + 1, indexTime + 3).toInt();

      // Compare the appointment time with the current time
      if (timeClient.getHours() == appointmentHour - 1 && timeClient.getMinutes() == appointmentMinute) {
        digitalWrite(buzzerPin, HIGH);
        Serial.println("It's time");

        // Keep the buzzer on for 60 seconds or until the button is pressed
        unsigned long startTime = millis();      // Record the start time
        while (millis() - startTime < maxTime) {   // Keep looping for 60 seconds
          buttonState = digitalRead(buttonPin);  // Check the button state

          // If the button is pressed, turn off the buzzer and exit the loop
          if (buttonState == HIGH) {
            digitalWrite(buzzerPin, LOW); 
            break;                         
          }

          // Add a small delay to avoid excessive CPU usage
          delay(smallDelay);
        }
      }
    }
    lcd.clear();

    lcd.setCursor(ORG_X, ORG_Y);
    lcd.print(appointmentDateTime);

    lcd.setCursor(ORG_X, ORG_X + 1);
    lcd.print(appointmentName);
    
    currentIndex = (currentIndex + 1) % jsonBuffer.size();

    delay(dataUpdateDelay);  
    
  } else {
    Serial.println("Unable to connect :(");
  }
  delay(connectionRetryDelay );
}
```

## Code for the LDR and the LED

// @author Sara Benali
// This program segment measures the light level in a room using an LDR sensor and activates the LED based on the measured value.
// License type: MIT License

```
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define WIFI_SSID "iotroam"
#define WIFI_PASSWORD "LXfu9HZkNP"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

int light = 0;  // store the current light value
int pinNumber = 13;
int maxLight = 451;
int minLight = 229;
int midLight = 450;
int serialStartNumber = 9600;
int initializationDelay = 1000;
void setup() {

  //configure  serial to talk to computer
  Serial.begin(serialStartNumber);
  // Your WeMos tries to connect to your Wi-fi network
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Keep the while-statement alive as long as we are NOT connected to the Wi-fi network.
  while (WiFi.status() != WL_CONNECTED) {
    delay(initializationDelay);
  }
  pinMode(pinNumber, OUTPUT);  // configure digital pin 13 as an output

}

void loop() {
  regulateLight();
}

void regulateLight() {
  light = analogRead(A0);  // read and save value from PR

  Serial.println(light);  // print current light value

  if (light > midLight) {  // If it is bright...
    Serial.println("It  is quite light!");
    digitalWrite(pinNumber, LOW);  //turn the LED off

  } else if (light > minLight && light < maxLight) {  // If  it is average light...
    Serial.println("It is average light!");
    digitalWrite(pinNumber, LOW);  // turn the LED off

  } else if (light < minLight) {  // If it's dark...
    Serial.println("It  is pretty dark!");
    digitalWrite(pinNumber, HIGH);  // Turn the LED on
    
    WiFiClient client;
    HTTPClient httpClient;
    httpClient.begin(client, "http://benalis2.loca.lt/insert_sensor_data.php");
    httpClient.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "light=" + String(light);
    int httpResponseCode = httpClient.POST(httpRequestData);
    Serial.println(httpResponseCode);

    if (httpResponseCode == HTTP_CODE_OK) {
      String payload = httpClient.getString();
      Serial.println(payload);
    } else {
      Serial.println("Unable to connect :(");
    }

  }
  delay(initializationDelay);  // don't spam the computer!
    
  }


```