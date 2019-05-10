#include "led.h"

void LED_Init(void)
{       
    //����LED�Ĺܽ�Ϊ���ģʽ
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
    LED_Config(LED_1, OFF);// ��
    delay_ms(100);
    LED_Config(LED_1, ON);//  ��
    delay_ms(100);
    
     LED_Config(LED_1, OFF);// ��
    delay_ms(100);
    LED_Config(LED_1, ON);//  ��
    delay_ms(100);
    
     LED_Config(LED_1, OFF);// ��
    delay_ms(100);
    LED_Config(LED_1, ON);//  ��
    delay_ms(100);
    
     LED_Config(LED_1, OFF);// ��
    delay_ms(100);
    LED_Config(LED_1, ON);//  ��
    delay_ms(100);
    
     LED_Config(LED_1, OFF);// ��
    delay_ms(100);
    LED_Config(LED_1, ON);//  ��
    delay_ms(100);
}


/*******************************************************************************
 * ����: Delay
 * ����: �򵥵���ʱ����
 * �β�: nCount -> ��ʱʱ����
 * ����: ��
 * ˵��: �� 
 ******************************************************************************/
void Delay(u32 nCount)
{
   u32 i;
   for(i=0;i<nCount;i++);       
}


/*******************************************************************************
 * ����: delay_ms
 * ����: �򵥵���ʱ����
 * �β�: ms -> ��ʱʱ����
 * ����: ��
 * ˵��: �� 
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

