
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define ALIAS_BASE 0x22000000U
#define BITBAND_BASE 0x20000000U

int main(void)
{

	uint8_t *ptr = (uint8_t*) 0x20000200;


	*ptr = 0xff;

	//normal method
	//Clearing 7th bit position
	*ptr &= ~(1 << 7);

	//reset to 0xff
	*ptr = 0xff;

	//bit banding method
	uint8_t *alias_addr = (uint8_t*) (ALIAS_BASE+(32*(0x20000200 - BITBAND_BASE)) + 7 * 4); //General formula of bit banding

	//Clearing 7th bit of address
	*alias_addr = 0;

	for(;;);
}
