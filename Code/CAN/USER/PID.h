#ifndef __PID_Speed_H__
#define __PID_Speed_H__

#define Speed_pid 6,0.5,10
#define Angle_pid 10,0,0

#include "main.h"

float pid_Speed(float val_expect, int16_t val_now,
								float kpV, float kiV, float kdV);

float pid_Angle(float angle_expect, int16_t angle_now, int16_t val_now,
								float kpA, float kiA, float kdA,
								float kpV, float kiV, float kdV);
								
float pid_Torque(float Torque_expect, int16_t current_now,
									float kpC, float kiC, float kdC);


#endif
