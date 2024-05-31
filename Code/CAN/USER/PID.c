#include "PID.h"

struct PID_Val
{
	float err;
	float err_last;
	float integral;
	float Current_set;
}PID_Val = {0,0,0,0};


struct PID_Angle
{
	float err;
	float err_last;
	float integral;
	float val_set;
	float Current_set;
}PID_Angle = {0,0,0,0,0};

struct PID_Torque
{
	float err;
	float err_last;
	float integral;
	float Current_set;
}PID_Torque={0,0,0,0};



float pid_Speed(float val_expect, int16_t val_now,
								float kpV, float kiV, float kdV)
{
	
	PID_Val.err = val_expect-val_now;
	PID_Val.integral += PID_Val.err;
	PID_Val.Current_set = kpV * PID_Val.err + kiV * PID_Val.integral + kdV *(PID_Val.err-PID_Val.err_last);
	PID_Val.err_last = PID_Val.err;
	
	return PID_Val.Current_set;
}


float pid_Angle(float angle_expect, int16_t angle_now, int16_t val_now,
								float kpA, float kiA, float kdA,
								float kpV, float kiV, float kdV)
{
	PID_Angle.err = angle_expect-angle_now;
	PID_Angle.integral += PID_Angle.err;
	PID_Angle.val_set = kpA * PID_Angle.err + kiA * PID_Angle.integral + kdA *(PID_Angle.err-PID_Angle.err_last);
	PID_Val.Current_set = pid_Speed(PID_Angle.val_set, val_now, kpV, kiV, kdV);
	PID_Angle.err_last = PID_Angle.err;
	
	return PID_Val.Current_set;
}


float pid_Torque(float TorqueCurrent_expect, int16_t TorqueCurrent_now,
									float kpC, float kiC, float kdC)
{

	PID_Torque.err = TorqueCurrent_expect-TorqueCurrent_now;
	PID_Torque.integral += PID_Torque.err;
	PID_Torque.Current_set = PID_Torque.Current_set + kpC * PID_Torque.err + kiC * PID_Torque.integral + kdC *(PID_Torque.err-PID_Torque.err_last);
	PID_Torque.err_last = PID_Torque.err;
	if(PID_Torque.Current_set > 16384) PID_Torque.Current_set = 16384;
	if(PID_Torque.Current_set < -16384) PID_Torque.Current_set = -16384;
	
	return PID_Torque.Current_set;
}


