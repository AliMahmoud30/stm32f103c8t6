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

#include "../02-GPIO/DIO_config.h"
#include "../02-GPIO/DIO_interface.h"
#include "../02-GPIO/DIO_private.h"

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
 * @brief  This function used to initialize a pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
Std_ReturnType MGPIO_SetPinDirection(const pin_config_t* _pin_config)
{
	Std_ReturnType status = OPERATION_SUCCESS;
	if(_pin_config == NULL)
	{
		status = OPERATION_ERROR;
	}
	else
	{
		switch(_pin_config->port)
		{
		case GPIOA:
			MGPIO_Set_PORTA_Pin_Mode_Configuration(_pin_config->pin, _pin_config->pin_mode);
			break;

		case GPIOB:
			MGPIO_Set_PORTB_Pin_Mode_Configuration(_pin_config->pin, _pin_config->pin_mode);
			break;

		case GPIOC:
			MGPIO_Set_PORTC_Pin_Mode_Configuration(_pin_config->pin, _pin_config->pin_mode);
			break;

		default : status = OPERATION_ERROR; break;
		}
	}
	return status;
}


/**
 * @brief  This function used to initializea port mode configuration.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
Std_ReturnType MGPIO_SetPORTDirection(const pin_config_t* _pin_config)
{
	Std_ReturnType status = OPERATION_SUCCESS;
	if(_pin_config == NULL)
	{
		status = OPERATION_ERROR;
	}
	else
	{
		switch(_pin_config->port)
		{
		case GPIOA:
			for(uint8_t indx=0; indx<16; indx++)
			{
				MGPIO_Set_PORTA_Pin_Mode_Configuration(indx, _pin_config->pin_mode);
			}
			break;

		case GPIOB:
			for(uint8_t indx=0; indx<16; indx++)
			{
				MGPIO_Set_PORTB_Pin_Mode_Configuration(indx, _pin_config->pin_mode);
			}
			break;

		case GPIOC:
			for(uint8_t indx=0; indx<16; indx++)
			{
				MGPIO_Set_PORTC_Pin_Mode_Configuration(indx, _pin_config->pin_mode);
			}
			break;

		default : status = OPERATION_ERROR;		break;
		}
	}
	return status;
}          
		  
/**
 * @brief  This function used to initialize the most eight pins mode configuration.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
Std_ReturnType MGPIO_SetHighPinsDirection(const pin_config_t* _pin_config)
{
	Std_ReturnType status = OPERATION_SUCCESS;
	if(_pin_config == NULL)
	{
		status = OPERATION_ERROR;
	}
	else
	{
		switch(_pin_config->port)
		{
		case GPIOA:
			for(uint8_t indx=8; indx<16; indx++)
			{
				MGPIO_Set_PORTA_Pin_Mode_Configuration(indx, _pin_config->pin_mode);
			}
			break;

		case GPIOB:
			for(uint8_t indx=8; indx<16; indx++)
			{
				MGPIO_Set_PORTB_Pin_Mode_Configuration(indx, _pin_config->pin_mode);
			}
			break;

		case GPIOC:
			for(uint8_t indx=8; indx<16; indx++)
			{
				MGPIO_Set_PORTC_Pin_Mode_Configuration(indx, _pin_config->pin_mode);
			}
			break;

		default :  status = OPERATION_ERROR;	break;
		}
	}
	return status;
}		
		  
/**
 * @brief  This function used to initialize the least eight pins mode configuration
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
Std_ReturnType MGPIO_SetLowPinsDirection(const pin_config_t* _pin_config)
{
	Std_ReturnType status = OPERATION_SUCCESS;
	if(_pin_config == NULL)
	{
		status = OPERATION_ERROR;
	}
	else
	{
		switch(_pin_config->port)
		{
		case GPIOA:
			for(uint8_t indx=0; indx<8; indx++)
			{
				MGPIO_Set_PORTA_Pin_Mode_Configuration(indx, _pin_config->pin_mode);
			}
			break;

		case GPIOB:
			for(uint8_t indx=0; indx<8; indx++)
			{
				MGPIO_Set_PORTB_Pin_Mode_Configuration(indx, _pin_config->pin_mode);
			}
			break;

		case GPIOC:
			for(uint8_t indx=0; indx<8; indx++)
			{
				MGPIO_Set_PORTC_Pin_Mode_Configuration(indx, _pin_config->pin_mode);
			}
			break;

		default :  status = OPERATION_ERROR;	break;
		}
	}
	return status;
}		

/**
 * @brief  This function used to write a logic value on a specific pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param  _pin_config pointer to the pin configuration @ref pin_config_t
 * @param  copy_logic_val logic value to write it on the pin @ref gpio_logic_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
Std_ReturnType MGPIO_SetPinValue(const pin_config_t* _pin_config , gpio_logic_t copy_logic_val )
{
	Std_ReturnType status = OPERATION_SUCCESS;
	gpio_reg_def_type_t* Local_port_address = NULL;
	if(_pin_config == NULL)
	{
		status = OPERATION_ERROR;
	}
	else
	{
		switch(_pin_config->port)
		{
		case GPIOA:	Local_port_address = GPIO_PORTA_REGS;	break;
		case GPIOB: Local_port_address = GPIO_PORTB_REGS;	break;
		case GPIOC:	Local_port_address = GPIO_PORTC_REGS;	break;
		default	  : status = OPERATION_ERROR;				break;
		}

		if(status == OPERATION_SUCCESS)
		{
			if(copy_logic_val == LOGIC_HIGH)
			{
				Local_port_address->GPIO_BSR = (1 << _pin_config->pin);  // SET BIT by BSRR (Atomic operation)
				//			SET_BIT(Local_port_address->GPIO_ODR, _pin_config->pin);    // Write HIGH on ODR
			}
			else if(copy_logic_val == LOGIC_LOW)
			{
				Local_port_address->GPIO_BRR = (1 << _pin_config->pin); 	// RESET BIT by BRR
				//			CLR_BIT(Local_port_address->GPIO_ODR, _pin_config->pin);    	// Write LOW on ODR
			}
		}
	}
	return status;
}
/**
 * @brief   This function used to write a value on specific port.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param   copy_port_index Port index @ref gpio_port_index_t
 * @param   copy_port_Value value to write it on the port
 * @return NONE
*/
void MGPIO_SetPORTValue(gpio_port_index_t copy_port_index, uint16_t copy_port_Value )
{
	switch(copy_port_index)
	{
	case GPIOA:
		GPIO_PORTA_REGS->GPIO_ODR = copy_port_Value;
		break;
	case GPIOB:
		GPIO_PORTB_REGS->GPIO_ODR = copy_port_Value;
		break;
	case GPIOC:
		GPIO_PORTC_REGS->GPIO_ODR = copy_port_Value;
		break;
	default:
		break;
	}
}

/**
 * @brief   This function used to write a value on specific port for the most 8-pins.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param   copy_port_index Port index @ref gpio_port_index_t
 * @param   copy_port_Value value to write it on the port
 * @return NONE
*/
void MGPIO_SetHighPinsValue(gpio_port_index_t copy_port_index, uint8_t copy_port_Value )
{
	uint16_t Local_port_value = ((uint16_t)copy_port_Value << 8);
	switch(copy_port_index)
	{
	case GPIOA:
		GPIO_PORTA_REGS->GPIO_ODR &= 0x000000FF;         			// Reset ODR before Write The Value
		GPIO_PORTA_REGS->GPIO_ODR ^= (uint32_t)Local_port_value;    // Write  Value
		break;
	case GPIOB:
		GPIO_PORTB_REGS->GPIO_ODR &= 0x000000FF;        			// Reset ODR before Write The Value
		GPIO_PORTB_REGS->GPIO_ODR ^= (uint32_t)Local_port_value;    // Write  Value
		break;
	case GPIOC:
		GPIO_PORTC_REGS->GPIO_ODR &= 0x000000FF;         			// Reset ODR before Write The Value
		GPIO_PORTC_REGS->GPIO_ODR ^= (uint32_t)Local_port_value;    // Write  Value
		break;
	default:		break;
	}
}
/**
 * @brief   This function used to write a value on specific port for the least 8-pins.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param   _copy_port_index Port index @ref gpio_port_index_t
 * @param   copy_port_Value value to write it on the port
 * @return NONE
*/
void MGPIO_SetLowPinsValue(gpio_port_index_t copy_port_index, uint8_t copy_port_Value)
{
	switch(copy_port_index)
	{
	case GPIOA:
		GPIO_PORTA_REGS->GPIO_ODR &= 0x0000FF00;                   // Reset ODR before Write The Value
		GPIO_PORTA_REGS->GPIO_ODR ^= (uint32_t)((uint32_t)copy_port_Value & 0x000000FF);    // Write  Value
		break;
	case GPIOB:
		GPIO_PORTB_REGS->GPIO_ODR &= 0x0000FF00;           		    // Reset ODR before Write The Value
		GPIO_PORTB_REGS->GPIO_ODR ^= (uint32_t)((uint32_t)copy_port_Value & 0x000000FF);       		// Write  Value
		break;
	case GPIOC:
		GPIO_PORTC_REGS->GPIO_ODR &= 0x0000FF00;            		// Reset ODR before Write The Value
		GPIO_PORTC_REGS->GPIO_ODR ^= (uint32_t)((uint32_t)copy_port_Value & 0x000000FF);      		    // Write  Value
		break;
	default:		break;
	}
}

/**
 * @brief  This function used to read the logic state from a specific pin.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @param _logic_val_returned pointer to return the pin value @ref gpio_logic_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
Std_ReturnType MGPIO_GetPinValue(pin_config_t* _pin_config , gpio_logic_t* logic_val_returned)
{
	Std_ReturnType status = OPERATION_SUCCESS;
	gpio_logic_t Local_pin_value =0;
	if(_pin_config == NULL)
	{
		status = OPERATION_ERROR;
	}
	else
	{
		switch(_pin_config->port)
		{
		case GPIOA: Local_pin_value = GET_BIT(GPIO_PORTA_REGS->GPIO_IDR,_pin_config->pin);	break;
		case GPIOB:	Local_pin_value = GET_BIT(GPIO_PORTB_REGS->GPIO_IDR,_pin_config->pin);	break;
		case GPIOC:	Local_pin_value = GET_BIT(GPIO_PORTC_REGS->GPIO_IDR,_pin_config->pin);	break;
		default	  : status = OPERATION_ERROR;												break;
		}
		*logic_val_returned = Local_pin_value;
	}
	return status;
}

/**
 * @brief  This function used to initializea port mode configuration.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return NONE
*/
void MGPIO_TogglePin(pin_config_t* _pin_config)
{
   switch(_pin_config->port)
   {
   case GPIOA:	TOG_BIT((GPIO_PORTA_REGS->GPIO_ODR),_pin_config->pin);	break;
   case GPIOB:  TOG_BIT(GPIO_PORTB_REGS->GPIO_ODR,_pin_config->pin);	break;
   case GPIOC:	TOG_BIT(GPIO_PORTC_REGS->GPIO_ODR,_pin_config->pin);	break;
   default:																break;
   }
}

/**
 * @brief  This function used to initializea port mode configuration.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
void MGPIO_SetPullUpDown(pin_config_t* _pin_config, uint8_t copy_u8mode)
{
	switch(_pin_config->port)
	{
	   case GPIOA:
		   switch(copy_u8mode)
		   {
		   case PULLUP	 : SET_BIT(GPIO_PORTA_REGS->GPIO_ODR,_pin_config->pin); break;
		   case PULLDOWN : CLR_BIT(GPIO_PORTA_REGS->GPIO_ODR,_pin_config->pin); break;
		   default : break;
		   }
		   break;
	   case GPIOB:
		   switch(copy_u8mode)
		   {
		   case PULLUP	 : SET_BIT(GPIO_PORTB_REGS->GPIO_ODR,_pin_config->pin); break;
		   case PULLDOWN : CLR_BIT(GPIO_PORTB_REGS->GPIO_ODR,_pin_config->pin); break;
		   default : break;
		   }
		   break;
	   case GPIOC:
		   switch(copy_u8mode)
		   {
		   case PULLUP	 : SET_BIT(GPIO_PORTC_REGS->GPIO_ODR,_pin_config->pin); break;
		   case PULLDOWN : CLR_BIT(GPIO_PORTC_REGS->GPIO_ODR,_pin_config->pin); break;
		   default : break;
		   }
		   break;
	   default:
		   break;
	}
}

/**
 * @brief  This function used to initializea pin mode configuration for PORTA.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return NONE
*/
static void MGPIO_Set_PORTA_Pin_Mode_Configuration(gpio_pin_index_t pin_index, uint8_t copy_u8pin_mode)
{
	if(pin_index <= PIN7)
	{
		// Write on CRL
		GPIO_PORTA_REGS->GPIO_CRL &= ~((0b1111) << (pin_index * 4));      	 		 // Reset  Mode & Config Bits
		GPIO_PORTA_REGS->GPIO_CRL |= ((copy_u8pin_mode)<< (pin_index * 4)); 	     // Write on Mode & Config Bits
	}
	// Write on CRH
	else if(copy_u8pin_mode <= PIN15)
	{
		GPIO_PORTA_REGS->GPIO_CRH &=  ~((0b1111) << ((pin_index-8) * 4));      			// Reset  Mode & Config Bits
		GPIO_PORTA_REGS->GPIO_CRH |=  (((copy_u8pin_mode))<< ((pin_index-8) * 4));      // Write on Mode & Config Bits
	}
}

/**
 * @brief  This function used to initialize pin mode configuration for PORTB.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param  _pin_config pointer to the pin configuration @ref pin_config_t
 * @return NONE
*/
static void MGPIO_Set_PORTB_Pin_Mode_Configuration(gpio_pin_index_t pin_index, uint8_t copy_u8pin_mode)
{
	if(pin_index <= PIN7)
	{
		// Write on CRL
		GPIO_PORTB_REGS->GPIO_CRL &= ~((0b1111) << (pin_index * 4));      	 		 // Reset  Mode & Config Bits
		GPIO_PORTB_REGS->GPIO_CRL |= ((copy_u8pin_mode)<< (pin_index * 4)); 	 // Write on Mode & Config Bits
	}
	// Write on CRH
	else if(copy_u8pin_mode <= PIN15)
	{
		GPIO_PORTB_REGS->GPIO_CRH &=  ~((0b1111) << ((pin_index-8) * 4));      			// Reset  Mode & Config Bits
		GPIO_PORTB_REGS->GPIO_CRH |=  (((copy_u8pin_mode))<< ((pin_index-8) * 4));   // Write on Mode & Config Bits
	}
}
/**
 * @brief  This function used to initialize pin mode configuration for PORTC.
 * @Author  Ali Morsy.
 * @version 1.0.
 * @param _pin_config pointer to the pin configuration @ref pin_config_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR)   : the function done not successfully
*/
static void MGPIO_Set_PORTC_Pin_Mode_Configuration(gpio_pin_index_t pin_index, uint8_t copy_u8pin_mode)
{

	if(pin_index <= PIN7)
	{
		// Write on CRL
		GPIO_PORTC_REGS->GPIO_CRL &= ~((0b1111) << (pin_index * 4));      	 		 // Reset  Mode & Config Bits
		GPIO_PORTC_REGS->GPIO_CRL |= ((copy_u8pin_mode)<< (pin_index * 4)); 	 // Write on Mode & Config Bits
	}
	// Write on CRH
	else if(copy_u8pin_mode <= PIN15)
	{
		GPIO_PORTC_REGS->GPIO_CRH &=  ~((0b1111) << ((pin_index-8) * 4));      			// Reset  Mode & Config Bits
		GPIO_PORTC_REGS->GPIO_CRH |=  (((copy_u8pin_mode))<< ((pin_index-8) * 4));   // Write on Mode & Config Bits
	}
}
