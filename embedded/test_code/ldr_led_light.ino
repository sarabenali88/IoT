int light = 0; // store the current light value

void setup() {
    Serial.begin(9600); //configure  serial to talk to computer
    pinMode(13, OUTPUT); // configure digital pin  13 as an output
}

void  loop() {
    light = analogRead(A0);  // read and save value from PR
    
    Serial.println(light); // print current light value
 
    if(light > 450) { // If it is bright...
        Serial.println("It  is quite light!");
        digitalWrite(13, LOW); //turn the LED off
        
    }
    else if(light > 229 && light < 451) { // If  it is average light...
        Serial.println("It is average light!");
       digitalWrite(13, LOW); // turn the LED off
    }
    else { // If it's dark...
        Serial.println("It  is pretty dark!");
        digitalWrite(13,HIGH); // Turn the LED on
        
    }
    delay(1000); // don't spam the computer!
}