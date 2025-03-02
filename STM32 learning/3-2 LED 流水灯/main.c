#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //一般用推挽就可
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2; //将定义中十六进制换为二进制按位或，就会是0000 0000 0000 0111,故可一次性设置多个引脚
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
//	GPIO_ResetBits(GPIOA, GPIO_Pin_0); //输出低电平
//	GPIO_SetBits(GPIOA, GPIO_Pin_0);
//	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
//	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
	
	while(1)
	{
		GPIO_Write(GPIOA, ~0x0001);  //0000 0000 0000 0001 分别对应PA0~PA15十六个端口 C语言不支持二进制，要转为十六进制 因为低电平驱动，故加~（按位取反）
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0002);  //0000 0000 0000 0010
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0004);  //0000 0000 0000 0100
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0008);  //0000 0000 0000 1000
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0010);  //0000 0000 0001 0000
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0020);  //0000 0000 0010 0000
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0040);  //0000 0000 0100 0000
		Delay_ms(100);
		GPIO_Write(GPIOA, ~0x0080);  //0000 0000 1000 0000 
		Delay_ms(100);
		
	}
}

