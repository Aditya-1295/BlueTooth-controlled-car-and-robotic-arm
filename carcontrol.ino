  #include<Servo.h>
char command;
String string;
Servo a1;
Servo a2;
Servo a3;
Servo a4;

  void setup()
  {
    a1.attach(10);
    a2.attach(11);
    a3.attach(12);
    a4.attach(13);
   
     pinMode(2,OUTPUT);
     pinMode(3,OUTPUT);
     pinMode(4,OUTPUT);
     pinMode(5,OUTPUT);

    Serial.begin(9600);
    
  }

  int length(String str){
    int i=0;
    for(i = 0;str[i]!=NULL;i++);
    return i;
  }

  String get_angle(String str){
    String temp_str="";
    //A-124 , A-90, etc this will return only 124 and 90 respectevely
    for(int i=1;i<length(str);i++){
      temp_str+=str[i];
    }
    return temp_str;
  }

  void loop()
  {
    
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
      if(command == ';')
      {
        break;
      }
      
      else
      {
        string += command;
      }
      
      delay(2);
    }

    if(string=="")return;

   
     
    if(string[0]=='W'){//Servo 1 angle changed
      a1.write(get_angle(string).toInt());
      Serial.println(get_angle(string));
    }

    
    if(string[0]=='X'){//Servo 2 angle changed
      a2.write(get_angle(string).toInt());
      Serial.println(get_angle(string));
    }

    if(string[0]=='Y'){//Servo 3 angle changed
      a3.write(get_angle(string).toInt());
      Serial.println(get_angle(string));
    }

     if(string[0]=='Z'){//Servo 4 angle changed
      a4.write(get_angle(string).toInt());
      Serial.println(get_angle(string));
    }

   

    



    
    
    if(string == "F")//Forward
    {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
       Serial.println(string);
    }
    
    if(string =="B")//Back
    {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
        Serial.println(string);
    }
    
    if(string =="R")//Turn Right
    {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
        Serial.println(string);
    }
    
    if(string =="L")//Turn Left
    {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
        Serial.println(string);
    }
    
    if(string =="S")//Stop
    {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
        Serial.println(string);
    }
    string = "";
 }

 

    
