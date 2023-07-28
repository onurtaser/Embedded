
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{

	int var1 = 10, var2;

	//Move the 'C' variable data to 'C' variable.
	__asm volatile("MOV %0,%1": "=r"(var2): "r"(var1));


    /* Loop forever */
	for(;;);
}
