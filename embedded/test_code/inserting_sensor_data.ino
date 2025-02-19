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

