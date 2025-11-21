/*********************************************************************/
/* Author		: Ali Morsy 						  			     */
/* Version		: V01                                                */
/* date			: 			 						   				 */
/* Description	: GPIO Module					   				     */
/*********************************************************************/

/*=============================================================================
 *              Section: Includes
 =============================================================================*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "../01-LED/LED_config.h"
#include "../01-LED/LED_interface.h"
#include "../01-LED/LED_private.h"
#include "../02-MCAL/02-GPIO/DIO_interface.h"
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
 * @brief  This function used to initialize a pin as output with default logic state
 * @Author Ali Morsy
 * @version 1.0
 * @param led pointer to the pin configuration @ref led_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR) : the function done  not successfully
 */
Std_ReturnType led_Initialize(const led_t* led)
{
	Std_ReturnType status = OPERATION_SUCCESS;
	pin_config_t Local_pin =  {
			.port 		= led->port_name,
			.pin 		= led->pin,
			.pin_mode 	= OUTPUT_SPEED_10MHZ_PP,
			.logic 	  	= led->led_status };

	if(led != NULL)
	{
		status = MGPIO_SetPinDirection(&Local_pin);
		status = MGPIO_SetPinValue(&Local_pin, Local_pin.logic);
	}
	else
	{
		status = OPERATION_ERROR;
	}
	return status;
}

/**
 * @brief  This function used to turn on a led
 * @Author Ali Morsy
 * @version 1.0
 * @param led pointer to the pin configuration @ref led_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR) : the function done  not successfully
 */
Std_ReturnType led_turn_on(const led_t* led)
{
   Std_ReturnType status = OPERATION_SUCCESS;
	pin_config_t Local_pin =  {
			.port 		= led->port_name,
			.pin 		= led->pin,
			.pin_mode 	= OUTPUT_SPEED_10MHZ_PP,
			.logic 	  	= led->led_status };

   if (led != NULL)
   {
	   status = MGPIO_SetPinValue(&Local_pin, LOGIC_HIGH);
   }
   else
   {
	   status = OPERATION_ERROR;
   }
   return status;
}

/**
 * @brief  This function used to turn off a led
 * @Author  Ali Morsy
 * @version 1.0
 * @param  led pointer to the pin configuration @ref led_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR) : the function done  not successfully
 */
Std_ReturnType led_turn_off(const led_t* led)
{
   Std_ReturnType status = OPERATION_SUCCESS;
	pin_config_t Local_pin =  {
			.port 		= led->port_name,
			.pin 		= led->pin,
			.pin_mode 	= OUTPUT_SPEED_10MHZ_PP,
			.logic 	  	= led->led_status };

   if (led != NULL)
   {
	   status = MGPIO_SetPinValue(&Local_pin, LOGIC_LOW);
   }
   else
   {
	   status = OPERATION_ERROR;
   }
   return status;
}

/**
 * @brief  This function used to turn toggle a led
 * @Author Ali Morsy
 * @version 1.0
 * @param led pointer to the pin configuration @ref led_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR) : the function done  not successfully
 */
Std_ReturnType led_toggle(const led_t* led)
{
   Std_ReturnType status = OPERATION_SUCCESS;
	pin_config_t Local_pin =  {
			.port 		= led->port_name,
			.pin 		= led->pin,
			.pin_mode 	= OUTPUT_SPEED_10MHZ_PP,
			.logic 	  	= led->led_status };

   if (led != NULL)
   {
	   MGPIO_TogglePin(&Local_pin);
   }
   else
   {
	   status = OPERATION_ERROR;
   }
   return status;
}

