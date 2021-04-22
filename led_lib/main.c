#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
//pc13
int main(void){
	GPIO_InitTypeDef led;
	led.GPIO_Pin = GPIO_Pin_13;
	led.GPIO_Mode = GPIO_Mode_Out_OD;
	led.GPIO_Speed = GPIO_Speed_50MHz;
	//��APB2����
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	//gpio��ʼ��
	GPIO_Init(GPIOC, &led);
	//����λ����Ϊ1 Ϊ���
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);
	return 0;
}
