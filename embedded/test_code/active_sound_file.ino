int buzzerPin = 8;
int buttonPin = 3;
int buttonState;
void setup() {
pinMode(buzzerPin, OUTPUT);
pinMode(buttonPin, INPUT);
Serial.begin(9600);
}

void loop() {
    buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);
    if(buttonState == LOW){
     digitalWrite(buzzerPin, LOW);
    }else{
      digitalWrite(buzzerPin, HIGH);
    }
}
