/*
 * Written by Rohan Aren and Kevin-Huynh Tran
 * Code to test the servos and ir receiver module
 */


#include <Servo.h>
#include <IRremote.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;

int RECV_PIN = 5;

#define SERVO  //uncomment only this to test the ir receiver
//#define RECEIVER  //uncomment only this to TEST the servos

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn();
  myservo1.attach(2);
  myservo2.attach(3);
  myservo3.attach(4);
}

void loop()
{
#ifdef SERVO
  //initialize all servos
  for (int i = 0; i < 180; i++)
  {
    myservo1.write(i);
    myservo2.write(i);
    myservo3.write(i);
    delay(20);
  }
  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  while (1);
#endif
#ifdef RECEIVER
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
#endif
}
