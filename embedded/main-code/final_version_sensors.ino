#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

#define PHP_URL_GET "http://benalis2.loca.lt/get_date.php"
#define PHP_URL_POST "http://benalis2.loca.lt/insert_sensor_data.php"


// Set web server port number to 80
int portNumber = 80;
WiFiServer server(portNumber);
boolean response;

// Variable to store the HTTP request
String header;

int startNumberBuffer = 1024;
DynamicJsonDocument jsonBuffer(startNumberBuffer);

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
int timeOffset = 7200;

int maxTime = 60000;

int light = 0;  // store the current light value
int pinNumber = 13;
int maxLight = 451;
int minLight = 229;
int midLight = 450;

void setup() {
  Serial.begin(serialStartNumber);

  // Your WeMos tries to connect to your Wi-fi network
  WiFiManager wifiManager;

  // Uncomment and run it once, if you want to erase all the stored information
  response = wifiManager.autoConnect("calendarAP", "password");
  // or use this for auto generated name ESP + ChipID
  //wifiManager.autoConnect();

  if (response) {
    Serial.println("Connected.");
  } else {
    Serial.println("Failed to connect to network.");
  }
  server.begin();


  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // initialize LCD
  lcd.begin(lcdCol, lcdRow);
  lcd.init();

  // turn on LCD backlight
  lcd.backlight();
  pinMode(pinNumber, OUTPUT);


  timeClient.begin();
  timeClient.setTimeOffset(timeOffset);
}

void loop() {
  makeSound();
  regulateLight();
}


void makeSound() {
  // Initialize a wi-fi client & http client
  HTTPClient httpClient;
  WiFiClient client = server.available();

  // Set the URL of where the call should be made to.
  httpClient.begin(client, PHP_URL_GET);

  // Make the GET-request, this returns the HTTP-code.
  int httpCode = httpClient.GET();

  // Check if the response is fine.
  if (httpCode == HTTP_CODE_OK) {  // HTTP_CODE_OK == 200
    String payload = httpClient.getString();
    deserializeJson(jsonBuffer, payload);

    //Deserialize the date/time and name of the appointment
    String appointmentDateTime = jsonBuffer[currentIndex]["date_time_appointment"];
    String appointmentName = jsonBuffer[currentIndex]["name"];

    // If there are no appointments, display "No appointments"
    if (appointmentDateTime == "null" && appointmentName == "null") {
      lcd.clear();
      lcd.setCursor(ORG_X, ORG_Y);
      lcd.print("No appointments");
      return;
    }

    // loop through the list of appointments
    for (int i = 0; i <= jsonBuffer.size(); i++) {
      timeClient.update();
      String appointmentTime = jsonBuffer[i]["date_time_appointment"];
      String currentTime = timeClient.getFormattedTime();

      int indexDate = appointmentTime.indexOf(" ");
      String date = appointmentTime.substring(indexDate + 1);

      // Split the time into hours and minutes
      int indexTime = date.indexOf(":");
      int appointmentHour = date.substring(0, indexTime).toInt();
      int appointmentMinute = date.substring(indexTime + 1, indexTime + 3).toInt();

      // Compare the current time with the appointment time
      if (timeClient.getHours() == appointmentHour - 1 && timeClient.getMinutes() == appointmentMinute) {
        digitalWrite(buzzerPin, HIGH);
        Serial.println("It's time");

        // Keep the buzzer on for 60 seconds or until the button is pressed
        unsigned long startTime = millis();       // Record the start time
        while (millis() - startTime < maxTime) {  // Keep looping for 60 seconds
          buttonState = digitalRead(buttonPin);   // Check the button state

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

    // Display the date and time of the appointment on the first row
    lcd.setCursor(ORG_X, ORG_Y);
    lcd.print(appointmentDateTime);

    // Display the name of the appointment on the second row.
    lcd.setCursor(ORG_X, ORG_X + 1);
    lcd.print(appointmentName);

    currentIndex = (currentIndex + 1) % jsonBuffer.size();

    delay(dataUpdateDelay);

  } else {
    Serial.println("Unable to connect :(");
  }
  delay(connectionRetryDelay);
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

    // Use the wifi-manager
    WiFiClient client = server.available();
    HTTPClient httpClient;

    // Set the url to post data to the database and add the header
    httpClient.begin(client, PHP_URL_POST);
    httpClient.addHeader("Content-Type", "application/x-www-form-urlencoded");

    //Parse the int to a String value
    String httpRequestData = "light=" + String(light);
    
    //Do the POST by using httpClient.POST
    int httpResponseCode = httpClient.POST(httpRequestData);
    Serial.println(httpResponseCode);

    // Check for response
    if (httpResponseCode == HTTP_CODE_OK) {
      String payload = httpClient.getString();
      Serial.println(payload);
    } else {
      Serial.println("Unable to connect :(");
    }
  }
  delay(initializationDelay);  // don't spam the computer!
}