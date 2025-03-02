#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //一般用推挽就可
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;  //若换成开漏输出模式LED不亮，说明开漏输出模式高电平没有输出能力，将LED反置又亮了说明有低电平驱动能力
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
//	GPIO_ResetBits(GPIOA, GPIO_Pin_0); //输出低电平
//	GPIO_SetBits(GPIOA, GPIO_Pin_0);
//	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
//	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
	
	while(1)
	{
//		GPIO_ResetBits(GPIOA, GPIO_Pin_0);  //点亮
//		Delay_ms(500);
//		GPIO_SetBits(GPIOA, GPIO_Pin_0);  //熄灭
//		Delay_ms(500);
		
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET); //点亮LED
//		Delay_ms(400);
//		GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);   //熄灭LED
//		Delay_ms(400);
		
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)0); //点亮LED
		Delay_ms(300);
		GPIO_WriteBit(GPIOA, GPIO_Pin_0, (BitAction)1);   //熄灭LED
		Delay_ms(300);
//将LED正负反置，仍然闪烁，说明推挽模式下，高低电平均具有驱动能力		
	}
}

