#include <Servo.h> // 建立一個 Servo 物件
Servo myservo; // 旋轉角度
void stopmotion();
void gocycles(int times);
char value = '0';
int index = 0;

void setup()
{ 
  myservo.attach(9);
  stopmotion();
  Serial.begin(9600);
}

void loop()
{ 
  if(!Serial.available()) { stopmotion(); return; }
  value = Serial.read();
  if (value > '5' || value < '0') { return; }
  
  int site = value - '0' - index;
  if (site < 0) site += 6;
  index = value-'0';
  
  switch(site){
    case(0):
      stopmotion();
      break;
    case(1):
      gocycles(1);
      stopmotion();
      break;
    case(2):
      gocycles(2);
      stopmotion();
      break;
    case(3):
      gocycles(3);
      stopmotion();
      break;
    case(4):
      gocycles(4);
      stopmotion();
      break;
    case(5):
      gocycles(5);
      stopmotion();
      break;
    default:
      stopmotion();  
  }
}

void stopmotion() {
  myservo.write(180);
  delay(20);
  myservo.write(0);
  delay(20);
  }

void gocycles(int times) {
  myservo.write(0);
  delay(1500*times);
  }
