#include "led.h"

void LED_Init(void)
{       
    //定义LED的管脚为输出模式
    GPIO_Init(LED_PORT, LED_1, GPIO_MODE_OUT_PP_HIGH_FAST );
}


void LED_Config(GPIO_Pin_TypeDef led, u8 state)
{
    if(ON == state) 
    {
        GPIO_WriteLow(LED_PORT, led);
    }
    else
    {
        GPIO_WriteHigh(LED_PORT, led);
    }
}


void LED_Show(void)
{
    LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
    
     LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
    
     LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
    
     LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
    
     LED_Config(LED_1, OFF);// 亮
    delay_ms(100);
    LED_Config(LED_1, ON);//  灭
    delay_ms(100);
}


/*******************************************************************************
 * 名称: Delay
 * 功能: 简单的延时函数
 * 形参: nCount -> 延时时间数
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/
void Delay(u32 nCount)
{
   u32 i;
   for(i=0;i<nCount;i++);       
}


/*******************************************************************************
 * 名称: delay_ms
 * 功能: 简单的延时函数
 * 形参: ms -> 延时时间数
 * 返回: 无
 * 说明: 无 
 ******************************************************************************/

void delay_ms(u8 ms)
{
    u16 i;
    while(ms--)
    {
    for(i=0;i<500;i++)
    {
      asm("nop");     
      asm("nop");
    }
    }

}

