#include "main.h"

//on STM32F103C8T6 output data register must be LOW which means 0. You can access this information from schematic of the MCU.

	/*uint32_t *pClkCtrlReg = (uint32_t*) 0x40021018;
	uint32_t *pPortCModeReg = (uint32_t*) 0x40011004;
	uint32_t *pPortCOutReg = (uint32_t*) 0x4001100C;*/

int main(void)
{


	RCC_APB2ENR_t volatile *const pClkCtrlReg = (RCC_APB2ENR_t*) 0x40021018; //constant pointer - programmer shouldn't change the value of this pointer.
	GPIOx_CRH_t volatile *const pPortCModeReg = (GPIOx_CRH_t*) 0x40011004;
	GPIOx_ODR_t volatile *const pPortCOutReg = (GPIOx_ODR_t*) 0x4001100C;

	//1.Enable the clock for GPIOC peripheral in the APB2ENR
	pClkCtrlReg -> iopc_en = 1;

	pPortCOutReg -> pin_13 = 1;

	//2.Configure the mode of the IO pin as output.
	//a. clear the 20th, 21th, 22th and 23th bit positions (CLEAR)
	pPortCModeReg -> mode13 = 0;
	pPortCModeReg -> cnf13 = 0;

	//b. make 20th and 21th bit positions as 1 (SET)
	pPortCModeReg -> mode13 = 3;
	pPortCModeReg -> cnf13 = 0;

	while(1){

		pPortCOutReg -> pin_13 = 0;

		for(uint32_t i = 0; i <= 200000; i++); //delay

		pPortCOutReg -> pin_13 = 1;

		for(uint32_t i = 0; i <= 200000; i++); //delay
	}

}
