#ifndef __DJ_bsp_h__
#define __DJ_bsp_h__

#include "main.h"
#include "can.h"
#include "pid.h"


void Motor_Send_CMD(uint16_t ID, uint16_t command, float DATA);

#endif

