# Embedded code

## Active buzzer code 
I used the pins from the Arduino to keep track of when the behaviour of the buzzer and button should change. I declared 
first that the buzzer sound will be the output and the button will be the input. I also tracked the state of the button. 
```
int buzzerPin = 8;
int buttonPin = 3;
int buttonState;
int newButtonState;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}
```

I set the buzzer to HIGH, so it would always make a buzzing sound. I then use a while-loop, so I can check when the buzzer
is supposed to stop buzzing. In the while-loop I used an if-statement to check if the button State is LOW, if it is then 
the buzzer should be HIGH. 
```
void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  digitalWrite(buzzerPin, HIGH);
  while (buttonState == LOW) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      digitalWrite(buzzerPin, LOW);
      delay(5);
    }

```

I also added a delay in the while-loop and outside the while-loop, so when you actually 
click on the button, the buzzer stops making a sound. 
```
 delay(1000);
  }
  delay(30);
}
```
[Link to my embedded code](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/individual-project/tiitiizuuxuu49/-/blob/main/embedded/test_code/active-sound-file.ino?ref_type=heads)

## LDR code
I first set the value of the light to 0.
```
int light = 0;
```

In the setup I set pin 13 as my output because that is the pin that I am using. I then assign the converted value to the 
light variable after reading the analog voltage from the light sensor connected to pin A0. I then do a print of the 
light variable, so I can see the current light value in the serial monitor.
```
void  loop() {
    light = analogRead(A0);
    Serial.println(light);
```

Next, I use an if-condition to check the light value. If the light value is larger than 450, then it means that
there's a lot of light and the LED needs to be turned off. 
```
if(light > 450) { // If it is bright...
        Serial.println("It  is quite light!");
        digitalWrite(13, LOW); //turn the LED off 
    }
```

If the light value is between 229 and 450 than there is still light and the LED needs to be turned off.
```
else if(light > 229 && light < 451) { // If  it is average light...
        Serial.println("It is average light!");
       digitalWrite(13, LOW); // turn the LED off
    }
```

Lastly, I do an else that turns the LED on. I added a delay so the program doesn't execute too quickly.
```
else { // If it's dark...
        Serial.println("It  is pretty dark!");
        digitalWrite(13,HIGH); // Turn the LED on
        
    }
    delay(1000); // don't spam the computer!
}
```
[link to my embedded code](https://gitlab.fdmci.hva.nl/IoT/2023-2024-semester-2/individual-project/tiitiizuuxuu49/-/blob/main/embedded/test_code/ldr_led_light.ino?ref_type=heads)



This is not a place to put your code, but to describe the code that you have written. You can describe the code in a general way, but also go into detail on specific parts of the code. You can also refer to the code in your repository. So just add a link to the code in your repository.