#ifndef __LED_H
#define __LED_H



#include "stm8s.h"

#define LED_PORT            GPIOA	 //LED  PA1
#define LED_1               GPIO_PIN_1

#define ON       0		/* ����LED���� -- �͵�ƽ*/
#define OFF      1		/* ����LED���� -- �ߵ�ƽ*/

void LED_Init(void);
void LED_Show(void);
void LED_Config(GPIO_Pin_TypeDef led, u8 state);

void delay_ms(u8 ms);
void Delay(u32 nCount);


#endif