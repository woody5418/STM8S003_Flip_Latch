/*************** (C) COPYRIGHT  四维拓智 ***************************************
 * 文件名  ：main.c
 * 描述    ：工程模板    
 * 库版本  ：V1.1.0
 * 开发人员：Woody QQ：2490006131
 * 修改时间：2016-10-14
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "sysclock.h"
#include "tim2.h"
#include "adc.h"
#include "led.h"
#include "key.h"

/*  Defines -----------------------------------------------------------*/


int main(void)
{ 
  u16 ADC_Value; 
  u8 _FLAG_3=0;
  /* 系统时钟初始化 */
  SystemClock_Init(); 
  ADC_Init();    /*ADC始化*/
  LED_Init();    /*LED初始化*/
  KEY_Init();    /*按键初始化*/
  
  LED_Show();
  //enableInterrupts(); 	/* 开启总中断 */
  while (1)
  {   
    KEY_Scan();  //2种模式
    ///////////////////////////
    ADC_Value = ADC1_GetConversionValue();
    if(ADC_Value > 60000) 
    {
      delay_ms(10);
      if(ADC_Value > 60000) 
      {
        if(_FLAG_3 == 0)  
        {
          _FLAG_1++;
          _FLAG_3=1;
        }
      }
    }
   if(ADC_Value < 1000) 
    {
      delay_ms(10);
      if(ADC_Value < 1000) 
      {
        if(_FLAG_3 == 1)  _FLAG_3=0;
      }
    }
//////////////////////////////  翻转
    if((KEY_S1 == 0)&&(KEY_S2 == 1))
    {
      if(_FLAG_1 ==1) 
      {
        LED_Config(LED_1, OFF); //亮
        ///
      }
      if(_FLAG_1 ==2)
      {
         LED_Config(LED_1, ON);  //灭
         _FLAG_1=0;
      }
    }
 //////////////////////////////  锁存
    if((KEY_S1 == 1)&&(KEY_S2 == 0))
    {
      if((_FLAG_2 == 0)&&(_FLAG_1 == 1))  
      {
        LED_Config(LED_1, OFF);
        _FLAG_2 = 1;
      }
      if((_FLAG_2 == 1)&&(_FLAG_1 == 2))   
      {
          LED_Config(LED_1, OFF);
          _FLAG_2=1;
          _FLAG_1=1;
      }
    }
    
    
    
  }
  
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
    
  }
}
#endif






