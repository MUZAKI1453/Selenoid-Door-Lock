int relay = 4;

void setup() {
pinMode(relay,OUTPUT);
digitalWrite(relay,HIGH);
}

void loop() {
digitalWrite(relay,LOW);
delay(5000);
digitalWrite(relay,HIGH);
delay(5000);
}
