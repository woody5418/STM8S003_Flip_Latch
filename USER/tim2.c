#include "tim2.h"
#include "led.h"


void TIM2_Configuration_set(void)
{
//  TIM2_DeInit();
  /*BaseTime=1/(16000000/16)*(3999+1)=40ms*/ 
  TIM2_TimeBaseInit(TIM2_PRESCALER_16,9999);
  TIM2_PrescalerConfig(TIM2_PRESCALER_16,TIM2_PSCRELOADMODE_IMMEDIATE);
  

  TIM2_ARRPreloadConfig(ENABLE);
  TIM2_ITConfig(TIM2_IT_UPDATE,ENABLE);
  TIM2_Cmd(ENABLE);
 
}





