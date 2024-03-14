#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#define WIFI_SSID "iotroam"
#define WIFI_PASSWORD "LXfu9HZkNP"
#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
int currentIndex = 0;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
DynamicJsonDocument jsonBuffer(1024);


void setup() {
  // Initialize the Serial-connection on a speed of 115200 b/s
  Serial.begin(115200);

  // Your WeMos tries to connect to your Wi-fi network
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Keep the while-statement alive as long as we are NOT connected
  // to the Wi-fi network.
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  lcd.begin(5, 4);  // initialize LCD
  lcd.init();
  // turn on LCD backlight
  lcd.backlight();
}

void loop() {
  // Initialize a wi-fi client & http client
  WiFiClient client;
  HTTPClient httpClient;

  // Set the URL of where the call should be made to.
  httpClient.begin(client, "http://benalis2.loca.lt/get_data.php");

  // Make the GET-request, this returns the HTTP-code.
  int httpCode = httpClient.GET();

  // Check if the response is fine.
  if (httpCode == HTTP_CODE_OK) {  // HTTP_CODE_OK == 200
    // Print the body of the GET-request response.
    String payload = httpClient.getString();
    deserializeJson(jsonBuffer, payload);
    currentIndex = (currentIndex + 1) % jsonBuffer.size();
    String appointmentDateTime = jsonBuffer[currentIndex]["date_time_appointment"];
    String appointmentName = jsonBuffer[currentIndex]["name"];


    Serial.println(payload);
    lcd.clear();
    lcd.setCursor(0, 0);

    // print message
    lcd.print(appointmentDateTime);
    lcd.setCursor(0, 1);
    lcd.print(appointmentName);
    delay(1000);
  } else {
    Serial.println("Unable to connect :(");
  }

  delay(5000);
}