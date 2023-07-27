#include <stdint.h>
#include <stdio.h>

void delay(){

	for(uint32_t i = 0; i <= 300000; i++);

}


int main(){

	uint32_t volatile *pClkCtrlReg = (uint32_t*) 0x40021018;
	uint32_t volatile *pPortAOutReg = (uint32_t*) 0x4001080C;
	uint32_t volatile *pPortAInReg = (uint32_t*) 0x40010808;
	uint32_t volatile *pPortAModeReg = (uint32_t*) 0x40010800;

	//Enable the clock register.
	*pClkCtrlReg |= (1 << 2);

	//PA0-PA1-PA2-PA3 pins are should be in output mode.(ROWS)
	*pPortAModeReg &= ~(0xFFFF);
	*pPortAModeReg |= 0x3333;
	//PA4-PA5-PA6-PA7 pins are should be in input mode.(COLUMNS)
	*pPortAModeReg &= ~(0xFFFF << 16);
	*pPortAModeReg |= (0x8888 << 16);

	while(1){

		//Make all row GPIOs HIGH STATE
		*pPortAOutReg |= (15 << 0);
		//Make R1(PA0) Low.
		*pPortAOutReg &= ~(1 << 0);

		//scan the columns
		//Check C1(PA4) low or high
		if(!(*pPortAInReg & (1 << 4))){
			//key is pressed.
			delay();
			printf("1\n");
		}

		//Check C2(PA5) low or high
		if(!(*pPortAInReg & (1 << 5))){
			//key is pressed.
			delay();
			printf("2\n");
		}

		//Check C3(PA6) low or high
		if(!(*pPortAInReg & (1 << 6))){
			//key is pressed.
			delay();
			printf("3\n");
		}

		//Check C4(PA7) low or high
		if(!(*pPortAInReg & (1 << 7))){
			//key is pressed.
			delay();
			printf("A\n");
		}


		//Make R2(PA1) Low.
		*pPortAOutReg |= (15 << 0); //And be sure other rows are high.
		*pPortAOutReg &= ~(1 << 1);

		//Check C1(PA4) low or high
		if(!(*pPortAInReg & (1 << 4))){
			//key is pressed.
			delay();
			printf("4\n");
		}

		//Check C2(PA5) low or high
		if(!(*pPortAInReg & (1 << 5))){
			//key is pressed.
			delay();
			printf("5\n");
		}

		//Check C3(PA6) low or high
		if(!(*pPortAInReg & (1 << 6))){
			//key is pressed.
			delay();
			printf("6\n");
		}

		//Check C4(PA7) low or high
		if(!(*pPortAInReg & (1 << 7))){
			//key is pressed.
			delay();
			printf("B\n");
		}

		//Make R3(PA2) Low.
		*pPortAOutReg |= (15 << 0); //And be sure other rows are high.
		*pPortAOutReg &= ~(1 << 2);

		//Check C1(PA4) low or high
		if(!(*pPortAInReg & (1 << 4))){
			//key is pressed.
			delay();
			printf("7\n");
		}

		//Check C2(PA5) low or high
		if(!(*pPortAInReg & (1 << 5))){
			//key is pressed.
			delay();
			printf("8\n");
		}

		//Check C3(PA6) low or high
		if(!(*pPortAInReg & (1 << 6))){
			//key is pressed.
			delay();
			printf("9\n");
		}

		//Check C4(PA7) low or high
		if(!(*pPortAInReg & (1 << 7))){
			//key is pressed.
			delay();
			printf("C\n");
		}

		//Make R4(PA3) Low.
		*pPortAOutReg |= (15 << 0); //And be sure other rows are high.
		*pPortAOutReg &= ~(1 << 3);

		//Check C1(PA4) low or high
		if(!(*pPortAInReg & (1 << 4))){
			//key is pressed.
			delay();
			printf("*\n");
		}

		//Check C2(PA5) low or high
		if(!(*pPortAInReg & (1 << 5))){
			//key is pressed.
			delay();
			printf("0\n");
		}

		//Check C3(PA6) low or high
		if(!(*pPortAInReg & (1 << 6))){
			//key is pressed.
			delay();
			printf("#\n");
		}

		//Check C4(PA7) low or high
		if(!(*pPortAInReg & (1 << 7))){
			//key is pressed.
			delay();
			printf("D\n");
		}
	}




	return 0;
}

