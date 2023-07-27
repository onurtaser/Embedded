#include "main.h"

//on STM32F103C8T6 output data register must be LOW which means 0. You can access this information from schematic of the MCU.


int main(void)
{


	RCC_APB2ENR_t volatile *const pClkCtrlReg = ADDR_REG_APB2ENR; //constant pointer - programmer shouldn't change the value of this pointer.
	GPIOx_CRH_t volatile *const pPortCModeReg = ADDR_REG_GPIOC_MODE;
	GPIOx_ODR_t volatile *const pPortCOutReg = ADDR_REG_GPIO;

	//1.Enable the clock for GPIOC peripheral in the APB2ENR
	pClkCtrlReg -> iopc_en = CLOCK_ENABLE;

	pPortCOutReg -> pin_13 = MODE_CONF_OUTPUT;

	//2.Configure the mode of the IO pin as output.
	//a. clear the 20th, 21th, 22th and 23th bit positions (CLEAR)
	pPortCModeReg -> mode13 = 0;
	pPortCModeReg -> cnf13 = 0;

	//b. make 20th and 21th bit positions as 1 (SET)
	pPortCModeReg -> mode13 = 3;
	pPortCModeReg -> cnf13 = 0;

	while(1){

		pPortCOutReg -> pin_13 = PIN_STATE_LOW;

		for(uint32_t i = 0; i <= DELAY_COUNT; i++); //delay

		pPortCOutReg -> pin_13 = PIN_STATE_HIGH;

		for(uint32_t i = 0; i <= DELAY_COUNT; i++); //delay
	}

}
