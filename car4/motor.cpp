#include "motor.h"
#include "math.h"
#include "encoderLED.h"

Servo motorL, motorR;
int sideChoose = 0; // 选择一边做为基准边，0为左，1为右
float leftVoltage = 0, rightVoltage = 0;      // 左右舵机的电压
float sideSpeed;
extern float angle;
extern int sideLength;
long int initLength;
long int record[5];
int initVoltage = 0;
int initSpeed = 40;

float temp_angle,e,temp,aim_angle;

void motorInit() {

  // attach函数，设定舵机的接口
  motorL.attach(pinR); //motor.h中已经定义了 pinL 为7  pinR 为8
  motorR.attach(pinL);

  //writeMicroseconds函数的取值是1000-2000,1500为静止,2000全速向前，1000全速向后
  motorL.writeMicroseconds(1500);
  motorR.writeMicroseconds(1500);
  
}

void walk(float left_speed, float right_speed)
{
  //骅哥采取的代码是,左轮在1500的基础上减，右轮在1500的基础上加，这样就是后驱
////////////////////////  adjust  //////////////////////////////////
  left_speed *= 1.18;
  right_speed *= 1.18;
////////////////////////////////////////////////////////////////////
  left_speed = min(left_speed, 400);
  right_speed = min(right_speed, 400);
  motorL.writeMicroseconds(1500+left_speed);
  motorR.writeMicroseconds(1500-right_speed);
}


void standBy()
{
  motorL.writeMicroseconds(1500);
  motorR.writeMicroseconds(1500);
}


//转弯函数
void turn(float angletoturn, int mode, bool smoothTurn = false)
{
    // angleTurn为需要转到的角度，mode为左右转变量， smoothTurn为是否只动一个轮
    getEncoder();
    temp_angle = angle;
    // mode 是一个判断左转还是右转的标志变量，1为右转，0为左转
    if (mode)
    {
      /*右转*/
      aim_angle = temp_angle - angletoturn;
      if (aim_angle < -1e-7)
      {
        aim_angle += 360;
      }
//      Serial.println(aim_angle);
        while (1)
        {
            getEncoder();
            
              //Serial.print("angle:");
              //Serial.println(angle);
            if(fabs(aim_angle - angle) < 0.4){
            break;
            }
            float leftCoef, rightCoef;
            float temp = fabs(aim_angle - angle);
            if(temp > 180)
                temp = fabs(temp - 360);
            float temp_1 = fabs(angletoturn - temp);
            temp = temp < temp_1 ? temp : temp_1;
    ////////////////////////  adjust  //////////////////////////////////
            leftCoef = pow(temp/fabs(angletoturn), 0.6);       
            rightCoef = pow(temp/fabs(angletoturn), 0.6);
            if(!smoothTurn)
                walk( 55 * leftCoef + 5,-55 * rightCoef -10);
            else
                walk( 55 * leftCoef + 5,5);
////////////////////////////////////////////////////////////////////
        }
    }
    else
    {
      /*左转*/
      aim_angle = temp_angle + angletoturn;
      if (aim_angle >= 360)
      {
        aim_angle -= 360;
      }

        while (1)
        {      
          
            getEncoder();
            if(fabs(aim_angle - angle) < 0.4){
            break;
            }
            float leftCoef, rightCoef;
            float temp = fabs(aim_angle - angle);
            if(temp > 180)
            temp = fabs(temp - 360);
            float temp_1 = fabs(angletoturn - temp);
            temp = temp < temp_1 ? temp : temp_1;
////////////////////////  adjust  //////////////////////////////////
            leftCoef = pow(temp/fabs(angletoturn), 0.6);       
            rightCoef = pow(temp/fabs(angletoturn), 0.6);
            if(!smoothTurn)
                walk( -55 * rightCoef -10,55 * leftCoef + 5);
            else
                walk( 5,55 * leftCoef + 5);
////////////////////////////////////////////////////////////////////
        }
    }
    
  standBy();
}




//这个是小车的最核心函数，建议仔细研究
void alongLine(int setDistance, int mode = 0, int setTime = 10000, int reverse = 0, float setAngle = -1, float setBias = 0, float angleToTurn = 0)
{
    // mode 用来控制小车的启动停止速度，用来控制动作的衔接
    // 0：缓入缓出
    // 1：直入缓出
    // 2：缓入直出
    // 3：直入直出
    // reverse 控制车辆行驶方向，0为前进，1为后退
    // setAngle 用来设置小车的初始角度，默认值为-1
    // setBias 是陀螺仪调整直线的偏差量，为0则走直线，否则走弧线，建议范围+-0.2
    // setBias 在alongLine中只保留接口，为防止歧义不应该直接修改，而是在alongCurve中修改

    volatile float errorA;
    bool stopSequence = false;
    volatile float leftSpeed = 0, rightSpeed = 0;
    int len = 0;
    float countAngle = 0;
    int timer_1, timer_2, timer;
    timer_1 = millis();
    float sumErrorA = 0;                 // PID中积分累加项
    float lastErrorA = 0;                // PID中微分前项
    float totalA = 0;                    // PID总和
    float K_p = 300, K_i = 1, K_d = 1;   // PID中三项的系数

    float init_angle;
    if(setAngle < 0){
        getEncoder();
        init_angle = angle;
        setAngle = init_angle; 
    }       
    else
        init_angle = setAngle;
    initLength = sideLength;
    
    delay(100);
    int first = 0;
    int index = 0;
    while(1){
        getEncoder();

        if(countAngle > angleToTurn)
            setBias = 0;
        else{
            init_angle += setBias;
            countAngle += setBias;
            if(init_angle > 360) 
                init_angle -= 360;
        }
        temp_angle = angle;
        

        errorA = temp_angle - init_angle;

        if(errorA > 300) {//对超过360°（0°）界限时进行修正
            errorA -= 360; 
        }
        if(errorA < -300){
            errorA += 360;
        }
        float tempErrorA = lastErrorA - errorA;
        if(sumErrorA + errorA > 10 || sumErrorA + errorA < -10){
          sumErrorA += 0;
        }
        else
          sumErrorA += errorA;
////////////////////////  adjust  //////////////////////////////////
        // 一般当小车大幅度抖动甚至转圈时，需要调整此中参数，或者可以加入更多分段
        if(errorA < 1){ // error较小表明小车无较大偏差
          K_p = 150;
          K_i = 0;
          K_d = 0;
        }
        else if(errorA < 3){
          K_p = 70;
          K_i = 0;
          K_d = 30;
        }
        else{ // 否则小车偏差较大，需要调整
          K_p = 50;
          K_i = 10;
          K_d = 10;;
        } 
  /*    if(errorA < 2){ // error较小表明小车无较大偏差
          K_p = 100;
          K_i = 0;
          K_d = 0;
        }
        else{ // 否则小车偏差较大，需要调整
          K_p = 30;
          K_i = 10;
          K_d = 60;;
        }*/
////////////////////////////////////////////////////////////////////

        totalA = K_p * errorA + K_i * sumErrorA + K_d * tempErrorA;
////////////////////////  adjust  //////////////////////////////////
        totalA *= 0.10;
////////////////////////////////////////////////////////////////////

        lastErrorA = errorA;

// ====================================================================
         if (!reverse){
          leftSpeed = 100 + totalA;
          rightSpeed = 100 - totalA;
         }
         else{
          leftSpeed = -100 + totalA;
          rightSpeed = -100 - totalA;
         }
// ====================================================================
        
        
        
        len = sideLength - initLength;
        timer_2 = millis();
        timer = timer_2 - timer_1;
        // 时序启动
        if(timer < 2000 && mode%2 == 0 && first == 0){
            double xtime = timer / 1000.0;
            float k = 1 / (1 + 0.1*exp(-xtime*2 + 4));
            //Serial.print("k: ");
            //Serial.println(k);
            leftSpeed *= k;
            rightSpeed *= k;
        }
        
        // 控停
        
        if((len > setDistance || timer_2 - timer_1 > setTime || stopSequence) && mode < 2){
            //Serial.println("stop");
            stopSequence = true;
            if(first == 0){
                first = 1;
                timer_1 = timer_2;
                timer = 0;
            }
            double xtime = timer / 1000.0;
            float k = 1 - 1 / (1 + 0.1*exp(-xtime*2 + 4));
            if(timer > 2000)
                break;
            else{
                int leftSpeedTemp = leftSpeed;
                int rightSpeedTemp = rightSpeed;
                leftSpeedTemp *= k;
                rightSpeedTemp *= k;
                leftSpeed = leftSpeed ? leftSpeedTemp : abs(leftSpeed) < abs(leftSpeedTemp);
                rightSpeed = rightSpeed ? rightSpeedTemp : abs(rightSpeed) < abs(rightSpeedTemp);
            }
        }
        else if((len > setDistance || timer_2 - timer_1 > setTime || stopSequence) && mode >1){
            break;
        }
         
        walk(leftSpeed, rightSpeed);
        delay(55);
    }
    standBy();
}


void alongCurve(int setTime, float setBias,  float angleToTurn, int mode = 0){
  alongLine(0, mode, setTime, 0, -1, setBias=setBias, angleToTurn=angleToTurn);
}



void turn_test(float angletoturn, int mode, bool smoothTurn = false) //只考虑360度以内旋转
{
  // angleTurn为需要转到的角度，mode为左右转变量， smoothTurn为是否只动一个轮
  getEncoder();
  temp_angle = angle;
  // mode 是一个判断左转还是右转的标志变量，1为右转，0为左转
  if (mode)
  {
        /*右转*/
        aim_angle = temp_angle - angletoturn;
        if (aim_angle < -1e-7)
        {
            aim_angle += 360;
        }
        //      Serial.println(aim_angle);
        while (1)
        {
            getEncoder();

            // Serial.print("angle:");
            // Serial.println(angle);
            if (fabs(aim_angle - angle) < 0.4)
            {
                break;
            }
            float leftCoef, rightCoef;
            if(angle < aim_angle)
                temp = 360 + angle - aim_angle;
            else
                temp = angle - aim_angle; 
            ////////////////////////  adjust  //////////////////////////////////
            if (temp < 5){
                leftCoef = pow(temp / 5, 0.6);
                rightCoef = pow(temp / 5, 0.6);
            }
            else{
                leftCoef = 1;
                rightCoef = 1;
            }
            if (!smoothTurn)
                walk(55 * leftCoef + 80, -55 * rightCoef + 80);
             //walk(100, 50);
            else
                walk(55 * leftCoef + 5, 5);
            ////////////////////////////////////////////////////////////////////
        }
  }
  else
  {
        /*左转*/
        aim_angle = temp_angle + angletoturn ;
        if (aim_angle >= 360)
        {
            aim_angle -= 360;
        }

        while (1)
        {
            getEncoder();
            int temp1 = 0;
            // Serial.print("angle:");
            // Serial.println(angle);
            if (angle > aim_angle)
                temp = 360 + aim_angle - angle;
            else
                temp = aim_angle - angle;
            if(temp<3)break;
            /*
            if ((temp < 5)&&(5 <aim_angle<355))
            {
                temp1 = angle - aim_angle;
                if(temp1>-1)break;
            }
            if((temp < 5)&&(aim_angle>355)){
                if(355< angle <360)temp1 = angle - aim_angle;
                if(angle <10)temp1 = 360+ angle - aim_angle;
                if(temp1>-1)break;
              }
          */
            float leftCoef, rightCoef;
            
            ////////////////////////  adjust  //////////////////////////////////
            if (temp < 15){
                leftCoef = pow(temp / 15, 0.8);
                rightCoef = pow(temp / 15, 0.8);
            }     
            else {leftCoef = 1;
                  rightCoef = 1;}
            if (angle > aim_angle)
                temp = 360 + aim_angle - angle;
            else
                temp = aim_angle - angle;
            if(temp<1)break;
            if (!smoothTurn)
                walk(60*leftCoef, 180 * rightCoef);
            // walk(100, 50);
            else
                walk(55 * leftCoef + 5, 5);
            /*    
            if (angle > aim_angle)
                temp = 360 + aim_angle - angle;
            else
                temp = aim_angle - angle;
            if(temp<1)break;
            */
            ////////////////////////////////////////////////////////////////////
        }
       
  }

  standBy();
}
