String command;
#define Rled 13
#define Yled 14
#define Gled 15
#define led 16

void setup() {
  Serial1.begin(9600);
  pinMode(Rled,OUTPUT);
  pinMode(Yled,OUTPUT);
  pinMode(Gled,OUTPUT);
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
    else if(command.equals("R"))
    {
      digitalWrite(Rled,HIGH);
     
    }
    else if(command.equals("r"))
    {
      digitalWrite(Rled,LOW);  
    }
     else if(command.equals("Y"))
    {
      digitalWrite(Yled,HIGH);                                 
     
    }
    else if(command.equals("y"))
    {
      digitalWrite(Yled,LOW);
    }
     else if(command.equals("G"))
    {
      digitalWrite(Gled,HIGH);
     
    }
    else if(command.equals("g"))
    {
      digitalWrite(Gled,LOW);
    }
    else
    {
      Serial1.println("bad command");
    }
    Serial1.print("command :");
    Serial1.println(command);
}
}
