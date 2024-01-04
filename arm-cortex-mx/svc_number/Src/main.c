#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	__asm ("SVC #8"); //This causing SVC exception.

	uint32_t data;
	__asm volatile("MOV %0,R0": "=r"(data) ::);

	printf("Data : %ld\n",data);
    /* Loop forever */
	for(;;);
}

__attribute__ ((naked)) void SVC_Handler(){

	__asm("MRS R0,MSP");
	__asm("B SVC_Handler_c");

}

void SVC_Handler_c(uint32_t *pBaseOfStackFrame){

	//Get the value of the MSP

	uint32_t *pReturn_addr = (uint32_t*) pBaseOfStackFrame[6];

	//Decrement the return address by 2 to point to
	//opcode of the SVC instruction in the program memory
	pReturn_addr-=2;

	//Extract the SVC number (LSByte of the opcode)
	uint32_t svc_number = (uint32_t) pReturn_addr;
	printf("Svc number is : %lx\n",svc_number);

	svc_number+=4; //We incremented the svc_number by 4

	pBaseOfStackFrame[0] = svc_number; // And now sending the svc_number to the thread mode from handler mode.



}
