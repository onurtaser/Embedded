
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{

	int control_reg;

	//Read CONTROL register to control_reg
	__asm volatile("MRS %0,CONTROL": "=r"(control_reg));


    /* Loop forever */
	for(;;);
}
