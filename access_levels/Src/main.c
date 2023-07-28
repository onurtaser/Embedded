
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void change_access_level_unpriv(){

	//to make access level privileged to unprivileged you must change the value of CONTROL reg to 1.
	//read
	__asm volatile ("MRS R0,CONTROL");
	//modify the R0, because we can not modify control directly.
	__asm volatile ("ORR R0,R0,0x01"); //ORR is logical OR you can use this to set a bit.
	//write
	__asm volatile ("MSR CONTROL,R0"); //After this code implementation access level was made unprivileged


}

int main(void)
{
    /* Loop forever */
	for(;;);
}
