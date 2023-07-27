/*
 * main.h
 *
 *  Created on: Jul 23, 2023
 *      Author: Onur
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct{

	uint32_t afio_en:1;
	uint32_t reserved:1;
	uint32_t iopa_en:1;
	uint32_t iopb_en:1;
	uint32_t iopc_en:1;
	uint32_t iopd_en:1;
	uint32_t iope_en:1;
	uint32_t reserved2:2;
	uint32_t adc1_en:1;
	uint32_t adc2_en:1;
	uint32_t tim1_en:1;
	uint32_t spi1_en:1;
	uint32_t reserved3:1;
	uint32_t usart1_en:1;
	uint32_t reserved4:17;

}RCC_APB2ENR_t;

typedef struct{

	uint32_t mode8:2;
	uint32_t cnf8:2;
	uint32_t mode9:2;
	uint32_t cnf9:2;
	uint32_t mode10:2;
	uint32_t cnf10:2;
	uint32_t mode11:2;
	uint32_t cnf11:2;
	uint32_t mode12:2;
	uint32_t cnf12:2;
	uint32_t mode13:2;
	uint32_t cnf13:2;
	uint32_t mode14:2;
	uint32_t cnf14:2;
	uint32_t mode15:2;
	uint32_t cnf15:2;

}GPIOx_CRH_t;

typedef struct{

	uint32_t pin_0:1;
	uint32_t pin_1:1;
	uint32_t pin_2:1;
	uint32_t pin_3:1;
	uint32_t pin_4:1;
	uint32_t pin_5:1;
	uint32_t pin_6:1;
	uint32_t pin_7:1;
	uint32_t pin_8:1;
	uint32_t pin_9:1;
	uint32_t pin_10:1;
	uint32_t pin_11:1;
	uint32_t pin_12:1;
	uint32_t pin_13:1;
	uint32_t pin_14:1;
	uint32_t pin_15:1;
	uint32_t reserved:16;

}GPIOx_ODR_t;

#endif /* MAIN_H_ */
