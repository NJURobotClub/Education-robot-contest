#ifndef _SCHEDULE5_H
#define _SCHEDULE5_H



#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//#include "encoder.h"
#include "motor.h"
//#include "ult_wall.h"
//#include "compass.h"
#include "xbee.h"
#include "led_matrix.h"
#define screwPin 9
#define mpin 4   //螺旋桨的引脚

void schedule_init();
void schedule();
void command_execute(byte c);//命令执行函数，内部调用
//void flash(int delayTime,int times);


#endif
