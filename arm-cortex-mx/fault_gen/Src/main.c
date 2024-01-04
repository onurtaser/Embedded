#include <stdint.h>
#include <stdio.h>


int main(void)
{

	//1. enable all configurable exceptions like usage fault, mem manage fault and bus fault
	uint32_t *pSHCRS = (uint32_t*) 0xE000ED24; // System Handler Control and State Reg.

	*pSHCRS |= (1 << 16); // mem manage fault
	*pSHCRS |= (1 << 17); // bus fault
	*pSHCRS |= (1 << 18); // usage fault

	//3.
	uint32_t *pSRAM = (uint32_t*)0x20000000; //Random SRAM memory address.
	*pSRAM = 0xFFFFFFFF; //Invalid opcode.

	void (*some_address) (void);

	some_address = (void*) 0x20000001;

	some_address();

	//4. analyze the fault

    /* Loop forever */
	for(;;);
}


//2. implement the faulth handlers.

void HardFault_Handler(){
	printf("Exception : Hard Fault\n");
	while(1);
}
void MemManage_Handler(){
	printf("Exception : Mem Manage Fault\n");
	while(1);
}
void BusFault_Handler(){
	printf("Exception : Bus Fault\n");
	while(1);
}
void UsageFault_Handler(){
	uint32_t *pUFSR = (uint32_t*) 0xE000ED2A;
	printf("Exception : Usage Fault\n");
	printf("UFSR = %lx",pUFSR); //It checks the Usage Fault Status Reg.
	while(1);
}
