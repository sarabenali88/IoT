# Requirements

To build your embedded device you need to have a clear idea of the requirements. On this page you can describe the requirements of your embedded device. This includes the requirements from DLO, but also your own requirements.

Add some images! 😉

## System requirements table
| **Requirement ID#** | **Requirement**                                                                                                                                                                        | **MoSCoW** | **Compliant** |
|---------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------|---------------|
| EMBRQ#01            | The embedded device acts as a client and sends measured sensor data to the application backend over http or https.                                                                     | MUST       | IN PROGRESS   |
| EMBRQ#02            | The embedded device also acts as a server and receives status messages from the application backend over http or https.                                                                | MUST       | NO            |
| EMBRQ#03            | The embedded device contains at least two types of input sensors (e.g. LDR, buttons, joystick, capacitive touch, etc.).                                                                | MUST       | IN PROGRESS   |
| EMBRQ#04            | The embedded device contains at least two types of visual and/or sensory outputs (e.g. LED, LED Matrix, 7-segment display, motor, servo, actuator, LCD-screen, buzzer, etc.).          | MUST       | IN PROGRESS   |
| EMBRQ#05            | The embedded device uses the WifiManager for configuration of SSID and password (PWD) for connecting to the network.                                                                   | MUST       | IN PROGRESS   |

## EMBRQ03
I have two inputs for my device. I have the push button and the LDR. 

_**First input**_

The first input I have is the push button. I am combing this input with the active buzzer output. I want the active buzzer 
to go off when it's time for an appointment, and when the buzzer goes off it will only be turned off if you click on the 
button. I am not saving the value of this input in the database. 

Below is a code snippet of how I did it: 
```
int buzzerPin = 8;
int buttonPin = 3;
int buttonState;
```

I first initialize the pins of the button, buzzer and the state of the button. 

```
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
```

In the setup I set the buzzer as the OUTPUT and the button as the INPUT.

```
digitalWrite(buzzerPin, HIGH);
  while (buttonState == LOW) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      digitalWrite(buzzerPin, LOW);
      delay(5);
    }
```
For now the buzzer always goes off so the buzzer is set to HIGH. In the code I set the state of the button on LOW, 
and then I read the state of the button. I then check if the button state is HIGH and if it is then the buzzer will 
be set to LOW again. 

**_Second input**_

The second input I use is the LDR. I am combining this input with the LED. With the LDR I read the light value in the room. 
if the LDR detects lots of light then the LED will be turned off and if it doesn't detect any light, the LED will be turned
on. I want to save the value of the LDR into the database. 
Below is code snippet of how I did this: 



## EMBRQ04

I have three outputs: the LDC-screen, the LED and the active buzzer.

_**First output**_

For the first output I wanted the date and time and the name of the appointment to be displayed on the LCD-screen. On the
first row the date and time and on the second row the name of the appointment.

Below is a code snippet of how I did it:

```
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
```

I did a setup of the Wi-Fi and the LCD-screen, so I can make a connection to the WI-Fi and with the LCD-screen.

```
String payload = httpClient.getString();
    deserializeJson(jsonBuffer, payload);
    currentIndex = (currentIndex + 1) % jsonBuffer.size();
    String appointmentDateTime = jsonBuffer[currentIndex]["date_time_appointment"];
    String appointmentName = jsonBuffer[currentIndex]["name"];
```

When I have a connection with the WI-FI I do a request for the appointments with the url and I then decode the requested
data by using the jsonBuffer, so I have the date/time and the name separate.

```
    lcd.setCursor(0, 0);
    lcd.print(appointmentDateTime);
    lcd.setCursor(0, 1);
    lcd.print(appointmentName);
```

I then print the date/time of the appointment on the first row of the LCD-screen by using 0,0 and the name on the
second row by using 0,1.


_**Second output**_

For the second output I used the LED. The way I wanted this to work was if it's dark then the LED will turn on and a light
will shine and if it's light, then the LED will be turned off.

Below is a code snippet of how I did it:
```
int light = 0;  // store the current light value
int pinNumber = 13;
int maxLight = 451;
int minLight = 229;
int midLight = 450;
```

I initialize the numbers I use to check how strong the light is.

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

I then do three checks to check how light it is. If it's really light tha the LED will be set on LOW. If it's average light
then the LED will also be set on LOW and if the light is lower than the minimum light than that means that it's dark and
the LED will be set on HIGH. 


## EMBRQ#05
The device uses the WifiManager for configuration of SSID and password for connecting to the network. I got my password 
my registering my device on the IoTroam. This is how I use the SSID and the password in my code: 

```
#define WIFI_SSID "iotroam"
#define WIFI_PASSWORD "LXfu9HZkNP"
```
I define the SSID and the password at the beginning of my file, and then I try to connect my Wemos to the internet: 

```
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
```

In the loop I initialize the wi-fi client and http client:
```
  WiFiClient client;
  HTTPClient httpClient;
```

I set the url of where I can make a call 
```
  httpClient.begin(client, "http://benalis2.loca.lt/get_data.php");
```

And now I am connected to the network and I can start making requests.