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
  while (buttonState == LOW) {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      digitalWrite(buzzerPin, LOW);
      delay(5);
    }
    delay(1000);
  }
  delay(30);
}