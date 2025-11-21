/***************************************************************************************/
/* Author     : ALi Morsy													   	       */
/* Version    :  V01													 		       */
/* Date	     :  			                      							           */
/***************************************************************************************/

#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Register Definitions */
/*
#define RCC_CR             *((volatile u32*)0x40021000)
#define RCC_CFGR           *((volatile u32*)0x40021004)
#define RCC_CIR            *((volatile u32*)0x40021008)
#define RCC_APB2RSTR       *((volatile u32*)0x4002100C)
#define RCC_APB1RSTR       *((volatile u32*)0x40021010)
#define RCC_AHBENR         *((volatile u32*)0x40021014)
#define RCC_APB2ENR        *((volatile u32*)0x40021018)
#define RCC_APB1ENR        *((volatile u32*)0x4002101C)
#define RCC_BDCR           *((volatile u32*)0x40021020)
#define RCC_CSR            *((volatile u32*)0x40021024)
*/

/*!
 this struct define the all RCC Registers
*/
typedef struct
{
	uint32_t RCC_CR;
	uint32_t RCC_CFGR;
	uint32_t RCC_CIR;
	uint32_t RCC_APB2RSTR;
	uint32_t RCC_APB1RSTR;
	uint32_t RCC_AHBENR;
	uint32_t RCC_APB2ENR;
	uint32_t RCC_APB1ENR;
	uint32_t RCC_BDCR;
	uint32_t RCC_CSR;
}RCC_Reg_Def_t;
#define RCC_PER_BASE_ADDRESS		(uint32_t)0x40021000
#define RCC_Reg_Def					((volatile RCC_Reg_Def_t*)RCC_PER_BASE_ADDRESS)


/*!
 Clock control register (RCC_CR) bit definition
*/

#define RCC_HSI_ON					(uint32_t)0x00000001
#define RCC_HSI_RDY					(uint32_t)0x00000002
#define RCC_HSE_ON					(uint32_t)0x00010000
#define RCC_HSE_RDY					(uint32_t)0x00020000
#define RCC_HSE_BYPS				(uint32_t)0x00040000
#define RCC_HSE_CSSON				(uint32_t)0x00080000
#define RCC_PLLON					(uint32_t)0x01000000
#define RCC_PLLRDY					(uint32_t)0x02000000

/*!
 Clock configuration register (RCC_CFGR) bit definition
*/

// System clock switch (Bits 1:0)
#define RCC_HSI_SYS_CLOCK					(uint32_t)0x00000000
#define RCC_HSE_SYS_CLOCK					(uint32_t)0x00000001
#define RCC_PLL_SYS_CLOCK					(uint32_t)0x00000002

// HPRE: AHB prescaler (Bits 7:4 )
#define AHB_PRESCLAER_SYSCLK_NOT_DIV		(uint32_t)0x00000000
#define AHB_PRESCLAER_SYSCLK_DIV_BY_2		(uint32_t)0x00000080
#define AHB_PRESCLAER_SYSCLK_DIV_BY_4		(uint32_t)0x00000090
#define AHB_PRESCLAER_SYSCLK_DIV_BY_8		(uint32_t)0x000000A0
#define AHB_PRESCLAER_SYSCLK_DIV_BY_16		(uint32_t)0x000000B0
#define AHB_PRESCLAER_SYSCLK_DIV_BY_64		(uint32_t)0x000000C0
#define AHB_PRESCLAER_SYSCLK_DIV_BY_128		(uint32_t)0x000000D0
#define AHB_PRESCLAER_SYSCLK_DIV_BY_256		(uint32_t)0x000000E0
#define AHB_PRESCLAER_SYSCLK_DIV_BY_512		(uint32_t)0x000000F0

//  PPRE1: APB low-speed prescaler (APB1) Bits 10:8
#define APB1_PRESCLAER_AHB_NOT_DIV			(uint32_t)0x00000000
#define APB1_PRESCLAER_AHB_DIV_BY_2			(uint32_t)0x00000400
#define APB1_PRESCLAER_AHB_DIV_BY_4			(uint32_t)0x00000500
#define APB1_PRESCLAER_AHB_DIV_BY_8			(uint32_t)0x00000600
#define APB1_PRESCLAER_AHB_DIV_BY_16		(uint32_t)0x00000700

//  PPRE2: APB high-speed prescaler (APB2) Bits 13:11
#define APB2_PRESCLAER_AHB_NOT_DIV			(uint32_t)0x00000000
#define APB2_PRESCLAER_AHB_DIV_BY_2			(uint32_t)0x00002000
#define APB2_PRESCLAER_AHB_DIV_BY_4			(uint32_t)0x00002800
#define APB2_PRESCLAER_AHB_DIV_BY_8			(uint32_t)0x00003000
#define APB2_PRESCLAER_AHB_DIV_BY_16		(uint32_t)0x00003800

//  ADCPRE: ADC prescaler Bits (Bits 14:14 )
#define PLCK2_DIV_BY_2						(uint32_t)0x00000000
#define PLCK2_DIV_BY_4						(uint32_t)0x00004000
#define PLCK2_DIV_BY_6						(uint32_t)0x00008000
#define PLCK2_DIV_BY_8						(uint32_t)0x0000C000


/*! CLOCK_TYPES */
#define RCC_HSE_CRYSTAL   0
#define RCC_HSE_RC        1
#define RCC_HSI           2
#define RCC_PLL           3


/*! PLL Options */
#define RCC_PLL_IN_HSI_DIV_2   0
#define RCC_PLL_IN_HSE_DIV_2   1
#define RCC_PLL_IN_HSE         2


#define RCC_ENABLE_OPTION			uint8_t(1)
#define RCC_DISABLE_OPTION			uint8_t(0)

#endif
