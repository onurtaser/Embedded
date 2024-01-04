
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{

	void (*fun_ptr)(void);//when we are dealing with a function pointer we must be careful of the T-Bit. It should be odd(0th bit is 1). Otherwise it will cause exception.

	//Its going to load the value of function pointer into the Program Counter(PC). Thats how PC jumps to that function.
	//When that happens 0th bit of this function address will be copied to the T-Bit
	fun_ptr = (void*) 0x080001e8; //We hard coded fun_ptr with even number.

	fun_ptr();//After that you can see on fault analyzer it says attempt to switch to invalid state.



	for(;;);
}
