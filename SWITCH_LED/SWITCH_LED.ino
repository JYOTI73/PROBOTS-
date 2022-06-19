#define SWITCH_PIN 16

#define LED_PIN 17

#define INPUT_PIN 15

void setup() {

pinMode (SWITCH_PIN, INPUT_PULLUP);
pinMode (LED_PIN, OUTPUT);
pinMode (INPUT_PIN, OUTPUT);
}

void loop(){

digitalWrite(INPUT_PIN, HIGH);

int i = digitalRead(SWITCH_PIN);

digitalWrite(LED_PIN, 1-i);

}
