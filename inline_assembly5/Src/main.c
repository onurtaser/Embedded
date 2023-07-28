
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{

	int p1, *p2;

	p2 = (int*) 0x20000008;

	//Copy the content of 'C' pointer variable data to 'C' variable.
	__asm volatile("LDR %0,[%1]": "=r"(p1): "r"(p2));


    /* Loop forever */
	for(;;);
}
