typedef unsigned int u32;

#define GPIOC_BASE    0x40011000
#define PERPIH_BASE   0x40000000
#define APB2_BASE     (PERPIH_BASE+0x10000)
#define AHB_BASE      (PERPIH_BASE+0x20000)
#define RCC_BASE      (AHB_BASE+0x1000)
#define RCC_APB2ENR   (RCC_BASE+0x18)

#define GPOIX_CRH_OFF 0x0004
#define GPIOX_ODR_OFF 0x000C
#define GPIO_CRH      (GPIOC_BASE+GPOIX_CRH_OFF)//400110040
#define GPIO_ODR      (GPIOC_BASE+GPIOX_ODR_OFF) //4001100C 

void delay(u32 x){
	u32 i = 0;
	
	while(x--){
		i = 10000000;
		while(i--);

	}	
}


int main(void){
	
	*((u32 *)RCC_APB2ENR) |= 0x00000010;
	//先清除寄存器相应位的值
	*((u32 *)GPIO_CRH) &= 0xff0fffff;
	
	//然后在进行相应位的复赋值
	*((u32 *)GPIO_CRH) |= 0x00300000;
	
	//*((unsigned int *)GPIO_ODR) &= ~(1<<13);
	//*((unsigned int *)GPIO_ODR) |= 0x00000000;
	
	//闪烁
	while(1){
		//亮
		*((u32 *)GPIO_ODR) &= ~(1<<13);
		*((u32 *)GPIO_ODR) |= 0x00000000;
		//延迟一段时间
		delay(1);
		//灭	
		*((u32 *)GPIO_ODR) &= ~(1<<13);
		*((u32 *)GPIO_ODR) |= 0x00002000;
		//延迟一段时间
		delay(1);
	}
		
	return 0;
}
