
#include "key.h"
#include "led.h"


u8 KEY_S1=0;
u8 KEY_S2=0;
u8 _FLAG_1=0;
u8 _FLAG_2=0;
u8 FLAG_FLAG1=0;
u8 FLAG_FLAG2=0;

void KEY_Init(void)
{       
    //定义KEY的管脚为输入模式
    GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_IN_PU_NO_IT);
}

void KEY_Scan(void)
{
//    if(GPIO_ReadInputPin(KEY_PORT_1, KEY_1) == 1)
//    {
//       delay_ms(10);
//       if(GPIO_ReadInputPin(KEY_PORT_1, KEY_1) == 1) //1 LED灭
//       {
//         KEY_S1=1;
//         KEY_S2=0;
//
//       } 
//     }
   if(GPIO_ReadInputPin(KEY_PORT_1, KEY_1) == 0)  //0 
     {
        delay_ms(10);
        if(GPIO_ReadInputPin(KEY_PORT_1, KEY_1) == 0) //0
        {
          KEY_S1=0;
          KEY_S2=1;
          _FLAG_2=0;
          FLAG_FLAG1 =0;
          if(FLAG_FLAG2==0)
          {
             FLAG_FLAG2=1;
             LED_Config(LED_1, ON);
          }
        }
     } 
   else 
   {
     delay_ms(10);
     if(GPIO_ReadInputPin(KEY_PORT_1, KEY_1)) //1
     {
        KEY_S1=1;
        KEY_S2=0;
        FLAG_FLAG2=0;
      if(FLAG_FLAG1 == 0)
      {
        _FLAG_1=0;
        FLAG_FLAG1=1;
        LED_Config(LED_1, ON);
      } 
     }
   }
}




