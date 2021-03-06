/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define RCC_BASE_ADDR		0x40023800UL
#define GPIOA_BASE_ADDR		0x40020000UL
#define RCC_CFGR_REG_OFFSET	0x08UL
#define RCC_CFGR_REG_ADDR	(RCC_BASE_ADDR + RCC_APB2_ENR_OFFSET)
#define RCC_AHB1_ENR_OFFSET 0x30UL
#define RCC_AHB1_ENR_ADDR	(RCC_BASE_ADDR + RCC_AHB1_ENR_OFFSET)
#define GPIOA_BASE_ADDR		0x40020000UL
#define GPIOA_MODE_OFFSET	0x00UL
#define GPIOA_MODE_REG_ADDR	(GPIOA_BASE_ADDR + GPIOA_MODE_OFFSET)
#define GPIOA_AFHR_OFFSET	0x24UL
#define GPIOA_AFHR_ADDR		(GPIOA_BASE_ADDR + GPIOA_AFHR_OFFSET)

int main(void)
{
	uint32_t volatile *const pRccCfgrReg			= (uint32_t *)(RCC_CFGR_REG_ADDR);
	uint32_t volatile *const pRccAhb1Enr 			= (uint32_t *)(RCC_AHB1_ENR_ADDR);
	uint32_t volatile *const pGpioaModeReg			= (uint32_t *)(GPIOA_MODE_REG_ADDR);
	uint32_t volatile *const pGpioaAltFunHighReg	= (uint32_t *)(GPIOA_AFHR_ADDR);

	// 1. Clear 21 and 22 bit positions of RCC_CFGR register to set MCO1 to HSI as clock source
	*pRccCfgrReg &= ~(0x3 << 21);

	// 2. Configure PA8(from alternate function table) to AF0 to behave as MCO1 signal
	*pRccAhb1Enr |= (0x1 << 0); // a. Enable clock for gpioa

	// b. configure gpioa for output
	*pGpioaModeReg &= ~(0x3 << 16); // clear
	*pGpioaModeReg |= (0x2 << 16); // set

	// c. set alt function high reg to 0x0000 for AF0 mode
	*pGpioaAltFunHighReg &= ~(0xf << 0);


	// 3. Configure MCO1 pre-scalar in configuration register (bit 24, 25 and 26) to adjust signal according to hardware capacity of analyzer





    /* Loop forever */
	for(;;);
}
