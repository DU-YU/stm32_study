#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
//pc13
int main(void){
	GPIO_InitTypeDef led;
	led.GPIO_Pin = GPIO_Pin_13;
	led.GPIO_Mode = GPIO_Mode_Out_OD;
	led.GPIO_Speed = GPIO_Speed_50MHz;
	//打开APB2总线
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	//gpio初始化
	GPIO_Init(GPIOC, &led);
	//将高位设置为1 为灭灯
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
	return 0;
}
