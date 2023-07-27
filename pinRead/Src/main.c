#include <stdint.h>

//on STM32F103C8T6 output data register must be LOW which means 0. You can access this information from schematic of the MCU.

int main(void)
{

	uint32_t *pClkCtrlReg = (uint32_t*) 0x40021018;
	uint32_t *pPortCModeReg = (uint32_t*) 0x40011004;
	uint32_t *pPortCOutReg = (uint32_t*) 0x4001100C;
	uint32_t *pPortCInReg = (uint32_t*) 0x40011008;


	//enable the clock for GPIOC peripheral in the APB2ENR
	*pClkCtrlReg |= (1 << 4);

	*pPortCOutReg |= (1 << 13);

	//clear the 20th, 21th, 22th and 23th bit positions (CLEAR) (P13)
	*pPortCModeReg &= 0x0F0FFFFF;

	//make 20th and 21th bit positions as 1 (SET)
	*pPortCModeReg |= (3 << 20);
	//set for P15
	*pPortCModeReg |= (1 << 31);

	while(1){
		//read the pin status
		uint32_t pinStatus = (*pPortCInReg & 0x8000); //zero out all other bits except bit 15

		if(pinStatus){
			//Turn on the LED
			*pPortCOutReg &= ~(1 << 13);
		}else{
			//Turn off the LED
			*pPortCOutReg |= (1 << 13);
		}
	}
}


