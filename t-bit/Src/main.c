
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{

	void (*fun_ptr)(void);//when we are dealing with a function pointer we must be careful of the T-Bit. It should be odd(0th bit is 1). Otherwise it will cause system fault

	fun_ptr = (void*) 0x080001e8; //We hard coded fun_ptr with even number.

	fun_ptr();



	for(;;);
}
