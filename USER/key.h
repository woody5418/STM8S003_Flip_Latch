#ifndef __KEY_H
#define __KEY_H

#include "stm8s.h"

#define KEY_1               GPIO_PIN_2
#define KEY_PORT_1          GPIOD      //°´¼ü  PD2


extern u8 KEY_S1;
extern u8 KEY_S2;
extern u8 _FLAG_1;
extern u8 _FLAG_2;


void KEY_Init(void);
void KEY_Scan(void);

#endif