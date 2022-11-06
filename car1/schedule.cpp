#include "schedule.h"
#include "encoderLED.h"

extern float angle;
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
  
  delta=angle-180;
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

    // step0
    if (c == 0x89)
    {
        open_flash("A");
        setLightMode(7);
        delay(3000);
    }

    // step1
    if (c == 0x90)
    {
      setLightMode(1);
      open_flash('G');
      alongLine(0,0,4000,0);
      setLightMode(4);
      open_flash('H');
      turn(90,0);
      setLightMode(1);
      open_flash('G');
      alongLine(0,0,8000,0);
      setLightMode(4);
      open_flash('L');
      turn(90,0);
      setLightMode(2);
      open_flash('G');
      alongLine(0,0,4000,0);
    }
    // step1.5
    if (c == 0x91)
    {
      setLightMode(1);
      open_flash('H');
      turn(0,0);
    }
    // step2
    if (c == 0x92)
    {
      setLightMode(0);
      open_flash('J');
      alongLine(0,0,2000,0);
      setLightMode(2);
      alongLine(0,0,4000,1);
      setLightMode(0);
      alongLine(0,0,4000,0);
      setLightMode(2);
      alongLine(0,0,2000,1);
    }
    // step2.5
    if (c == 0x93)
    {
      open_flash('H');
<<<<<<< HEAD:car1/schedule.cpp
      setLightMode(1);
      turn(90,1);
      setLightMode(2);
      alongLine(0,0,1000,0);
      setLightMode(1);
      turn(180,1);
=======
      turn(90,1);
      alongLine(0,0,1000,0);
      
>>>>>>> da50a07571e7aef7308c69cd90b0d571efeb6cc1:schedule_car1/openduino/schedule.cpp
      open_flash('K');
      setLightMode(0);
    }
    // step3
    if (c == 0x94)
    {
<<<<<<< HEAD:car1/schedule.cpp
      open_flash('N');
      setLightMode(2);
      alongLine(0,0,2000,0);
      open_flash('K');
      setLightMode(0);
    }
    if (c == 0x95)
    {
      open_flash('A');
=======
      open_flash('K');
      turn(180,1);
      open_flash('N');
      alongLine(0,0,2000,0);
>>>>>>> da50a07571e7aef7308c69cd90b0d571efeb6cc1:schedule_car1/openduino/schedule.cpp
    }
    // step4
    if (c == 0x96)
    {
<<<<<<< HEAD:car1/schedule.cpp
      setLightMode(1);
      turn(70,0);
      setLightMode(2);
      alongLine(0,0,3000,0);
      setLightMode(1);
      turn(160,1);
      setLightMode(0);
    }
    // step5
    if (c == 0x97)
    {
        setLightMode(5);
        open_flash('Q');
        alongLine(0, 0, 3000, 0);
=======
      open_flash('Q');
      turn(70,0);
      alongLine(0,0,3000,0);
      turn(160,1);
      alongLine(0,0,5000,0);
>>>>>>> da50a07571e7aef7308c69cd90b0d571efeb6cc1:schedule_car1/openduino/schedule.cpp
    }
    // 目前用这个0x90作为调试信号，当car5接受到调试信号后，显示5
    /*
    if (c == 0x90){
      analogWrite(screwPin, 120);
      Serial.println("90");
      getEncoder();
      initAngle_ = angle;
      close_flash();
      open_flash('x');
      turn(90, 1);
      turn(90, 1);
      turn(90, 1);
      turn(90, 1);
      setLightMode(1);
      //
      delay(500);
//      digitalWrite(mpin, HIGH);
//      flash(500, 1);
      standBy();
//      analogWrite(screwPin, 0);
    }

    if (c == 0x91){
      Serial.println("91");
      // 主车第一阶段动作
//      digitalWrite(mpin, HIGH);
//      flash(300, 1);
      delay(500);
      alongLine(500, 0);
//      digitalWrite(mpin, LOW);
      standBy();
    }


    if (c == 0x92){
      analogWrite(screwPin, 120);
      Serial.println("92");
//      digitalWrite(mpin, HIGH);
      // 主车第一阶段连接
      turn(180, 1);
      alongLine(500);
//      digitalWrite(mpin, LOW);
      standBy();
    }

    if (c == 0x93){
      Serial.println("93");
      // 主车第二阶段动作
//      digitalWrite(mpin, HIGH);
      getEncoder();
      float angleTemp = angle;
      open_flash('i');
      setLightMode(0);
      delay(1800);
//      alongLine(10000, 0, angleTemp);
//      digitalWrite(mpin, LOW); 
      standBy();
    }

    if (c == 0x94){
      Serial.println("94");
      // 主车第二阶段连接
//      digitalWrite(mpin, HIGH);
      open_flash('A');
      turn(180, 1);
//      digitalWrite(mpin, LOW);
      standBy();
      analogWrite(screwPin, 0);
    }

    if (c == 0x95){
      Serial.println("95");
      // 主车第三阶段动作
//      digitalWrite(mpin, HIGH);
      open_flash('a');
      if(count == 0){
        alongLine(500);
        count ++;
      }
      else{
        initAngle_ = initAngle_ < 180 ? initAngle_ + 180 : initAngle_ - 180;
        alongLine(500, 0, initAngle_);
      }
//      flash(300, 1);
//      digitalWrite(mpin, LOW);
      standBy();
    }

    if (c == 0x96){
//      digitalWrite(mpin, HIGH);
      open_flash('A');
      alongLine(300);
//      digitalWrite(mpin, LOW);
    }

    if (c == 0x97){
//      digitalWrite(mpin, HIGH);
      turn(180, 1);
//      digitalWrite(mpin, LOW);
    }
*/
      
    /*******************************第一阶段***********************************/

}