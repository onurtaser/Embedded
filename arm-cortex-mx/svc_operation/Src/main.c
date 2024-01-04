#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//SVC 36 = ADD, SVC 37 = SUB, SVC 38 = MUL, SVC 39 = DIV

int32_t add_numbers(int32_t x, int32_t y){

	int32_t res;

	__asm volatile("SVC #36"); //If it is 36 then add the numbers.
	__asm volatile("MOV %0,R0":"=r"(res):);
	return res;
}

int32_t sub_numbers(int32_t x, int32_t y){

	int32_t res;

	__asm volatile("SVC #37");
	__asm volatile("MOV %0,R0":"=r"(res):);
	return res;
}

int32_t mul_numbers(int32_t x, int32_t y){

	int32_t res;

	__asm volatile("SVC #38");
	__asm volatile("MOV %0,R0":"=r"(res):);
	return res;
}

int32_t div_numbers(int32_t x, int32_t y){

	int32_t res;

	__asm volatile("SVC #39");
	__asm volatile("MOV %0,R0":"=r"(res):);
	return res;
}

int main(void)
{
	uint32_t res;

	res = add_numbers(40, -90);
	printf("Add result = %ld\n", res);

	res = sub_numbers(25, 150);
	printf("Sub result = %ld\n", res);

	res = mul_numbers(374, 890);
	printf("Mul result = %ld\n", res);

	res = div_numbers(67, -3);
	printf("Div result = %ld\n", res);

	for(;;);
}

__attribute__ ((naked)) void SVC_Handler(){

	__asm("MRS R0,MSP");
	__asm("B SVC_Handler_c");

}

void SVC_Handler_c(uint32_t *pBaseOfStackFrame){

	uint32_t arg0, arg1, res;

	uint32_t *pReturn_addr = (uint32_t*) pBaseOfStackFrame[6];

	//Decrement the return address by 2 to point to
	//opcode of the SVC instruction in the program memory
	pReturn_addr-=2;

	//Extract the SVC number (LSByte of the opcode)
	uint32_t svc_number = (uint32_t) pReturn_addr;
	printf("Svc number is : %lx\n",svc_number);

	arg0 = pBaseOfStackFrame[0]; // arg0 equals to R0
	arg1 = pBaseOfStackFrame[1]; // arg1 equals to R1   Procedure Call Standart for ARM

	switch(svc_number){
	case 36:
		res = arg0 + arg1;
		break;
	case 37:
		res = arg0 - arg1;
		break;
	case 38:
		res = arg0 * arg1;
		break;
	case 39:
		res = arg0 / arg1;
		break;
	default:
		printf("Invalid SVC code.\n");
	}

	pBaseOfStackFrame[0] = res;

}
