String command;
#define led 16

void setup() {
  Serial1.begin(9600);
  pinMode(led,OUTPUT);
  delay(200);

   Serial1.println("type on or off");
}

void loop() {
  if(Serial1.available()){
    command= Serial1.readStringUntil('\n');
     command.trim();
    if(command.equals("on"))
    {
      digitalWrite(led,HIGH);
    }
    else if(command.equals("off"))
    {
      digitalWrite(led,LOW);
    }
    else
    {
      Serial1.println("bad command");
    }
    Serial1.print("command :");
    Serial1.println(command);
}
}
