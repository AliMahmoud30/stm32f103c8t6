/*
 * main.c
 *
 *  Created on:
 *      Author: Ali Morsy
 */

/*=============================================================================
 *              Section: Includes
 =============================================================================*/
/*! Lib */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*! Modules  */
#include "../02-MCAL/01-RCC/RCC_interface.h"
#include "../02-MCAL/02-GPIO/DIO_interface.h"
#include "../03-HAL/01-LED/LED_interface.h"
#include "../03-HAL/02-seven_segment/seven_segment_interface.h"
#include "../02-MCAL/03-NVIC/NVIC_interface.h"
/*=====================================================================================
 *              Section: Macro Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: Macro Function Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: variables Declarations
 =====================================================================================*/

Std_ReturnType  status = OPERATION_SUCCESS;
led_t led_1 =
{
	.port_name  = GPIOA,
	.pin   		= PIN5,
	.led_status = LOGIC_LOW
};

int main(void)
{

	RCC_voidInitSysClock();								/*! Initialize the system clock */
	RCC_voidEnablePeripheralClock(RCC_APB2, IOPAEN);	/*! Enable Peripheral 2 on APB2 bus (GPIOA) */
	RCC_voidEnablePeripheralClock(RCC_APB2, IOPBEN);
	RCC_voidEnablePeripheralClock(RCC_APB2, IOPCEN);


	MNVIC_voidInit();
	MNVIC_voidSetPriority(6,0b01000000);	/*! EXTI0 Group 1, sub 0 */
	MNVIC_voidSetPriority(7,0b00110000); 	/*! EXTI1 Group 0, sub 3 */

	MNVIC_voidEnableInterrupt(NVIC_EXTI0);	/*! Enable EXTI0  */
	MNVIC_voidEnableInterrupt(NVIC_EXTI1);	/*! Enable EXTI1  */

	led_Initialize(&led_1);


	MNVIC_voidSetPendingFlag(NVIC_EXTI0);

	while(1)
	{

		for(uint16_t i = 0; i< 500; i++)
		{
			for(uint16_t j = 0; j< 500; j++)
			{
				asm("NOP");
			}
		}
	}
	return 0;
}


void EXTI0_IRQHandler(void)
{

	led_turn_on(&led_1);
	MNVIC_voidSetPendingFlag(NVIC_EXTI1);	/*! Set Pending flag For EXTI1 */
	//while(1);
	led_toggle(&led_1);

}

void EXTI1_IRQHandler(void)
{
//	MNVIC_voidSetPendingFlag(NVIC_EXTI0);
	led_turn_off(&led_1);
}

