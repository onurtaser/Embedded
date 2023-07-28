
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{


	int val = 50;

	__asm volatile("MOV R0,%0": :"r"(val)); // %0 stands for replace with the first operand.


    /* Loop forever */
	for(;;);
}
