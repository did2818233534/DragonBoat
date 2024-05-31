#include "DJ_bsp.h"
#include "usart.h"


void Motor_Send_CMD(uint16_t ID, uint16_t command, float DATA)
{
	uint8_t DATA_T[8] = {0};
	CAN_TxHeaderTypeDef Can_Tx;
	uint32_t pTxMailbox=0;
	
	Can_Tx.IDE=CAN_ID_STD;
	Can_Tx.RTR=CAN_RTR_DATA;
	Can_Tx.DLC=0x08;
	Can_Tx.StdId=ID << 8 | command;	
	 
	*(float*)DATA_T = DATA;
	
	HAL_UART_Transmit(&huart1, DATA_T, 8, 0xff);
	HAL_CAN_AddTxMessage(&hcan,&Can_Tx,DATA_T,&pTxMailbox);
}

