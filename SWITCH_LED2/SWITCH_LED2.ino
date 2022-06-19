#define SWITCH_PIN 16

#define LED_PIN 17

#define INPUT_PIN 15

void setup() {

pinMode (SWITCH_PIN, INPUT_PULLUP);
pinMode (LED_PIN, OUTPUT);
pinMode (INPUT_PIN, OUTPUT);
}
int state=0;
void loop(){

digitalWrite(INPUT_PIN, HIGH);

int i = digitalRead(SWITCH_PIN);


if(i==0)
{
  state = 1-state;
  delay(250);
}

digitalWrite(LED_PIN, state);

}
