# Requirements

To build your embedded device you need to have a clear idea of the requirements. On this page you can describe the
requirements of your embedded device. This includes the requirements from DLO, but also your own requirements.

Add some images! 😉

## System requirements table

| **Requirement ID#** | **Requirement**                                                                                                                                                                        | **MoSCoW** | **Compliant** |
|---------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------|---------------|
| EMBRQ#01            | The embedded device acts as a client and sends measured sensor data to the application backend over http or https.                                                                     | MUST       | YES           |
| EMBRQ#02            | The embedded device also acts as a server and receives status messages from the application backend over http or https.                                                                | MUST       | YES           |
| EMBRQ#03            | The embedded device contains at least two types of input sensors (e.g. LDR, buttons, joystick, capacitive touch, etc.).                                                                | MUST       | YES           |
| EMBRQ#04            | The embedded device contains at least two types of visual and/or sensory outputs (e.g. LED, LED Matrix, 7-segment display, motor, servo, actuator, LCD-screen, buzzer, etc.).          | MUST       | YES           |
| EMBRQ#05            | The embedded device uses the WifiManager for configuration of SSID and password (PWD) for connecting to the network.                                                                   | MUST       | NO            |

## EMBRQ #01

I created a POST request from my Wemos by using the Wi-Fi client.
I first check when the value that the LDR detects is smaller than the minimum light value (229). If it's, then I create
a POST request. I use the ```"http://benalis2.loca.lt/insert_sensor_data.php"``` to create the request. I add the
Content-Type
in the header and I set the format. By using the ```"httpClient.POST()"``` the request is executed.

```
else if (light < minLight) {  // If it's dark...
    Serial.println("It  is pretty dark!");
    digitalWrite(pinNumber, HIGH);  // Turn the LED on
    
    WiFiClient client;
    HTTPClient httpClient;
    httpClient.begin(client, "http://benalis2.loca.lt/insert_sensor_data.php");
    httpClient.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "light=" + String(light);
    int httpResponseCode = httpClient.POST(httpRequestData);
```

## EMBRQ #02

I created a GET request to request data from my server. I create a request by using this url
```"http://benalis2.loca.lt/get_date.php"```. I use the ``` "httpClient.GET()"``` to execute the GET request. I check if
the response had the status-code 200 and if it does than I deserialize the data.

```
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
```

## EMBRQ #03

I have two inputs for my device. I have the push button and the LDR.

_**Push button**_

The first input I have is the push button. I am combing this input with the active buzzer output. The push button is used 
to stop the active buzzer from buzzing for when it's time for an appointment. 

I first initialize the pins of the button, buzzer and the state of the button. In the setup I set the buzzer as 
the OUTPUT and the button as the INPUT.

```
int buzzerPin = 16;
int buttonPin = 14;
int buttonState;
pinMode(buzzerPin, OUTPUT);
pinMode(buttonPin, INPUT);
```

I first check the button state. I check if the button state is HIGH and if it is than that means that the button is pressed.
The buzzer is then set to LOW, so it stops buzzing. 
```
   buttonState = digitalRead(buttonPin);  // Check the button state
   // If the button is pressed, turn off the buzzer and exit the loop
   
         if (buttonState == HIGH) {
            digitalWrite(buzzerPin, LOW); 
               break;                         
          }
```

**_LDR**_

The second input I use is the LDR. I am combining this input with the LED. With the LDR I read the light value in the
room. If the LDR detects lots of light then the LED will be turned off and if it doesn't detect any light, the LED will be
turned on.

I first save the numbers I am checking the light value with, I also created a variable called light because here I am
storing the value of the light.
```
int light = 0;  // store the current light value
int pinNumber = 13;
int maxLight = 451;
int minLight = 229;
int midLight = 450;
```

I created a method called regulateLight and I call this method in the loop. With the analogRead I read the light value
that comes from the LDR.
```
void regulateLight() {
  light = analogRead(A0); 
```

The light value is being checked for the minimum and maximum value and based on that the LED will be turned on or off.
```
if (light > midLight) {  // If it is bright...
    Serial.println("It  is quite light!");
    digitalWrite(pinNumber, LOW);  //turn the LED off
    
  } else if (light > minLight && light < maxLight) {  // If  it is average light...
    Serial.println("It is average light!");
    digitalWrite(pinNumber, LOW);  // turn the LED off
    
  }
  else if (light < minLight) {  // If it's dark...
    Serial.println("It  is pretty dark!");
    digitalWrite(pinNumber, HIGH); 
    }
```

## EMBRQ04

I have three outputs: the LDC-display, the LED and the active buzzer.

_**LCD-display**_
 
I wanted the date and time and the name of the appointment to be displayed on the LCD-screen. On the first row the date 
and time and on the second row the name of the appointment.

I set the columns and rows for the LCD-display 

```
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);
```

I deserialized the data I got and I saved the value from the date_time_appointment and the name of the appointment.
```
    String payload = httpClient.getString();
    deserializeJson(jsonBuffer, payload);
    currentIndex = (currentIndex + 1) % jsonBuffer.size();
    String appointmentDateTime = jsonBuffer[currentIndex]["date_time_appointment"];
    String appointmentName = jsonBuffer[currentIndex]["name"];
```

I then print the date/time of the appointment on the first row of the LCD-screen by using 0,0 and the name on the
second row by using 0,1.

```
    lcd.setCursor(ORG_X, ORG_Y);
    lcd.print(appointmentDateTime);
    lcd.setCursor(ORG_X, ORG_X + 1);
    lcd.print(appointmentName);
```

_**LED**_

For the second output I used the LED. The way I wanted this to work was if it's dark then the LED will turn on and a
light will shine and if it's light, then the LED will be turned off.

I initialize the numbers I use to check how strong the light is.

```
int light = 0;  // store the current light value
int pinNumber = 13;
int maxLight = 451;
int minLight = 229;
int midLight = 450;
```

I then do three checks to check how light it is. If it's really light tha the LED will be set on LOW. If it's average
light then the LED will also be set on LOW and if the light is lower than the minimum light than that means that it's dark and
the LED will be set on HIGH.

```
if (light > midLight) {  // If it is bright...
    Serial.println("It  is quite light!");
    digitalWrite(pinNumber, LOW);  //turn the LED off

  } else if (light > minLight && light < maxLight) {  // If  it is average light...
    Serial.println("It is average light!");
    digitalWrite(pinNumber, LOW);  // turn the LED off

  } else if (light < minLight) {  // If it's dark...
    Serial.println("It  is pretty dark!");
    digitalWrite(pinNumber, HIGH);  // Turn the LED on
  }
```

_**Active Buzzer**_

For the third output I have the active buzzer. One hour before the appointment time, the buzzer will go off as a reminder
that the user has an appointment. 

I first initialize the pins of the button, buzzer and the state of the button. In the setup I set the buzzer as
the OUTPUT and the button as the INPUT.

```
int buzzerPin = 16;
int buttonPin = 14;
int buttonState;
pinMode(buzzerPin, OUTPUT);
pinMode(buttonPin, INPUT);

```

One hour before the appointment's time the buzzer will go off. If you click on the button, the buzzer stops. I didn't 
want the buzzer to go off forever, so it goes off for one minute and if you didn't click on the button in that one minute
then it turns off on its own. 

```
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
```