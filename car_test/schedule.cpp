#include "schedule.h"
#include "encoderLED.h"

extern float angle;
float tempangle;
float subangle;
volatile float count = 0;
float delta;
float initAngle_;
int command = 0;

void schedule_init()
{
  //  encoderInit();
  //  motorInit();
  //  ultrasonic_init();
  //  compassInit();
  //  xbee_init();
  led_matrix_init();
  pinMode(screwPin, OUTPUT);
  //  digitalWrite(ledpin, LOW);
  pinMode(mpin, OUTPUT);
  digitalWrite(mpin, LOW);
  close_flash();
  //  open_flash('A');
  getEncoder();

  delta = angle - 180;
}

//void flash(int delayTime, int times)
//{
//  int i;
//  for (i = 0; i < times; i++)
//  {
//    digitalWrite(ledpin, HIGH);
//    Serial.println("high");
//    delay(delayTime);
//    digitalWrite(ledpin, LOW);
//    Serial.println("Low");
//    delay(delayTime);
//  }
//}
void schedule()
{
  byte c = getCommand();

  command_execute(c);
}
// car1
void command_execute(byte c)
{

  //    Serial.print("c: ");
  //    Serial.println(c);
  // step1  入场
  if (c == 0x88)
  {
    alongLine(0, 0, 4000, 0);
    delay(200);
  //  turn(180, 1);
  }
  // step2  花滑
  if (c == 0x89)
  {
    alongCurve(18000, -1, 360);
    delay(200);
//    alongCurve(3800, -1, 360);
//    delay(200);
//    alongCurve(3800, -1, 360);
//    delay(200);
//    alongCurve(3800, -1, 360);
    
    /*
    turn(180, 1);
    delay(500);
    turn(180, 1);
    delay(500);
    turn(180, 1);
    delay(500);
    turn(180, 1);
    */
  }

  // step3 花滑to冰壶
  if (c == 0x90)
  {
 //   turn(180, 1);
    delay(200);
    alongLine(0, 0, 1000, 0);
    delay(200);
    turn(90, 1);
    delay(200);
    alongLine(0, 0, 2500, 0);
    delay(200);
    turn(45, 0);
  }
  // step4 冰壶
  if (c == 0x91)
  {
    delay(5800);
    alongLine(0, 0, 2000, 0);
  }
  // step5 冰壶to冰球
  if (c == 0x92)
  {
    turn(45, 0);
    delay(200);  
    alongLine(0, 0, 1500, 0);
    delay(200);
    turn(90, 0);
    delay(200);
    alongLine(0, 0, 2000, 0);
    delay(200);
    turn(60, 0);
  }
  // step6 冰球-car4向car1移动
  if (c == 0x93)
  {
    delay(1000);
    alongLine(0, 0, 3000, 0);
  }
  // step7 冰球-car4向car3移动
  if (c == 0x94)
  {
    delay(1000);
    turn(150, 1);
    delay(1000);
    alongLine(0, 0, 3000, 0);
  }
  // step8 冰球-car4向car2移动（追球）
  if (c == 0x95)
  {
    alongLine(0, 0, 1000, 0);
    delay(1000);
    turn(90, 1);
    delay(200);
    alongLine(0, 0, 1000, 0);
  }
  // step9 冰球to颁奖
  if (c == 0x96)
  {
    turn(180, 1);
    delay(200);
    alongLine(0, 0, 2000, 0);
    delay(200);
    turn(90, 0);
    delay(200);
    alongLine(0, 0, 3000, 0);
    delay(200);
    turn(180, 1);
  }
  /*if (c == 0x95)
    {
    open_flash('A');
    }*/
  // step10 颁奖
  if (c == 0x97)
  {
    alongLine(0, 0, 4000, 0);
    delay(200);
    /* 
     *  =============
     *  摇旗
     *  =============
     */
  }

    if (c == 0x98)
  {
   /* getEncoder();
    tempangle = angle; */
    turn_test(183, 0);
    delay(2000);
    turn_test(183, 0);
    delay(2000);
    /*getEncoder();
    subangle = angle - tempangle;
    if(subangle>=0)
    {
      turn(subangle ,1);
      }
    else
    {
      turn(fabs(subangle),0);
      }*/
    delay(200);
    /* 
     *  =============
     *  摇旗
     *  =============
     */
  }

}
