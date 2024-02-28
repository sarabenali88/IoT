int buzzerPin = 8;
int buttonPin = 3;
int buttonState;
int newButtonState;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  digitalWrite(buzzerPin, HIGH);
  while (buttonState == HIGH) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
      digitalWrite(buzzerPin, LOW);
      delay(10);
    }
    delay(2000);
  }
}
