#include "GPIO.h"
#include "RCC.h"


void func_RCC_config(void);
void func_GPIO_config(void);


int main(void){
	func_RCC_config();
	func_GPIO_config();
	
	
	while(1){
		
		if(uGPIORead(GPIOA,0)==0){
		vGPIOSetReset(GPIOG,13,Set);
		vGPIOSetReset(GPIOG,14,Reset);
		}
		else{
		vGPIOSetReset(GPIOG,13,Reset);
		vGPIOSetReset(GPIOG,14,Set);
		
    }
		
		
	}
	
	
}


void func_RCC_config(){
	vRCC_SetSYSCLK(HSE,HSE_Crystal,PLL_HSE, AHB_Pre1, APB1_Pre2, APB2_Pre1);
	vRCC_setPLLCFGR(PLLM_option4,PLLN_option72,PLLP_option2 ,PLLQ_option4);
	vRCC_EnPerClk(AHB1,GPIOGEN);
	vRCC_EnPerClk(AHB1,GPIOAEN);
	
}

void func_GPIO_config(){
	
	
	vGPIOConfig(GPIOG,13,Output);
	vGPIOConfig(GPIOG,14,Output);
	vGPIOConfig(GPIOA,0,Input);
	
	vOutputConfig(GPIOG,13,Push_pull,Low_Speed);
	vOutputConfig(GPIOG,14,Push_pull,Low_Speed);
	
	
}

