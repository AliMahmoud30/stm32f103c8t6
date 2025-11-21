/*********************************************************************/
/* Author: Ali Morsy 											     */
/* Version : V01                                                     */
/* date  :  													     */
/* Description : NVIC MODULE									     */
/*********************************************************************/

/*=============================================================================
 *              Section: Includes
 =============================================================================*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/*=====================================================================================
 *              Section: Macro Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: Macro Function Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: Data Type Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: variables Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: Function Implementation
 =====================================================================================*/


/**
 * @brief  	This function used to initialize the NVIC Peripheral .
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param 	NONE
 * @return 	NONE
*/
void MNVIC_voidInit(void)
{
	#define SCB_AIRCR	*((uint32_t*)(0xE000ED0C))
	SCB_AIRCR= NVIC_GROUP_SUB_DISTRIBUTION;
}

/**
 * @brief  This function used to initialize a pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
void MNVIC_voidSetPriority(uint8_t copy_u8PeripheralIdx, uint8_t copy_u8priority)
{
	if(copy_u8PeripheralIdx <60)
	{
		NVIC_IPR[copy_u8PeripheralIdx]=copy_u8priority;
	}
	else
	{
		/* Report Error*/
	}
}

/**
 * @brief  This function used to initialize a pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
void MNVIC_voidEnableInterrupt(NVIC_IRQn_Type copy_irq_position)
{
	if(copy_irq_position<=31)
	{
		NVIC_ISER0	=	(1<<copy_irq_position);
	}
	else if(copy_irq_position <= 59)
	{
		copy_irq_position -= 32;
		NVIC_ISER1	=	(1<<copy_irq_position);
	}
	else
	{
		/*Return Error */
	}
}


/**
 * @brief  This function used to initialize a pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
void MNVIC_voidDisableInterrupt(NVIC_IRQn_Type copy_irq_position)
{
	if(copy_irq_position<=31)
	{
		NVIC_ICER0=(1<<copy_irq_position);
	}
	else if(copy_irq_position<=59)
	{
		copy_irq_position-=32;
		NVIC_ICER1=(1<<copy_irq_position);
	}
	else
	{
		/*Return Error */
	}
	
	
}

/**
 * @brief  This function used to initialize a pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
void MNVIC_voidSetPendingFlag(NVIC_IRQn_Type copy_irq_position)
{
	if(copy_irq_position<=31)
	{
		NVIC_ISPR0=(1<<copy_irq_position);
	}
	else if(copy_irq_position<=59)
	{
		copy_irq_position-=32;
		NVIC_ISPR1=(1<<copy_irq_position);
	}
	else
	{
		/*Return Error */
	}
	
	
}

/**
 * @brief  This function used to initialize a pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
void MNVIC_voidClearPendingFlag(NVIC_IRQn_Type copy_irq_position)
{
	if(copy_irq_position<=31)
	{
		NVIC_ICPR0=(1<<copy_irq_position);
	}
	else if(copy_irq_position<=59)
	{
		copy_irq_position-=32;
		NVIC_ICPR1=(1<<copy_irq_position);
	}
	else
	{
		/*Return Error */
	}
	
	
}

/**
 * @brief  This function used to initialize a pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
uint8_t MNVIC_voidGetActiveFlag(NVIC_IRQn_Type copy_irq_position)
{
	uint8_t Local_Result=0;
	if(copy_irq_position<=31)
	{
		Local_Result=GET_BIT(NVIC_IABR0,copy_irq_position);
	}
	else if(copy_irq_position<=59)
	{
		copy_irq_position-=32;
		Local_Result=GET_BIT(NVIC_IABR1,copy_irq_position);
	}
	else
	{
		/*Return Error */
	}
	
	return Local_Result;
}


/**
 * @brief  This function used to initialize a pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
// void MNVIC_voidSetPrioriy(s8 copy_s8IntID, u8 copy_u8GroupPrioriy,u8 copy_u8Subpriority, u32 copy_u32Group)
// {
	// /*                      0x05FA0400-0x05FA0300)/256 >> 1 */
	// u8 local_u8prioriy = copy_u8Subpriority|(copy_u8GroupPrioriy<<((copy_u32Group-0x05FA0300)/256));
	// /* Core Peripheral*/
	// /*
		// delayed
	// */
	
	// /* External Peripheral*/
	// if(copy_s8IntID>=0)
	// {
		// NVIC_IPR[copy_s8IntID]=local_u8prioriy<<4;
	// }
	
	// SCB_AIRCR = copy_u32Group;
// }
