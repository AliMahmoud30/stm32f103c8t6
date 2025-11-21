/*********************************************************************/
/* Author		: Ali Morsy 						  			     */
/* Version		: V01                                                */
/* date			: 			 						   				 */
/* Description	: SEVEN_SEGMENT Module					   			 */
/*********************************************************************/

/*=============================================================================
 *              Section: Includes
 =============================================================================*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "../02-MCAL/02-GPIO/DIO_interface.h"
#include "seven_segment_config.h"
#include "seven_segment_interface.h"
#include "seven_segment_private.h"
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
/*!
 * seven segment common cathode values
 */
static const uint8_t seven_segment_codes[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
/*=====================================================================================
 *              Section: Function Implementation
 =====================================================================================*/
/**
 * @brief  This function used to initialize seven segment pins.
 * @Author Ali Morsy
 * @version 1.0
 * @param btn pointer to the seven segment configuration @ref seven_segment_t
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR) : the function done  not successfully
 */
Std_ReturnType seven_segment_initialization(const seven_segment_t* seven_segment_ptr)
{
    Std_ReturnType ret = OPERATION_SUCCESS;

    if(seven_segment_ptr  == NULL)
    {
        ret = OPERATION_ERROR;
    }
    else
    {
       ret = MGPIO_SetPinDirection(&(seven_segment_ptr->segment_pins[SEGMENT_PIN0]));
       ret = MGPIO_SetPinDirection(&(seven_segment_ptr->segment_pins[SEGMENT_PIN1]));
       ret = MGPIO_SetPinDirection(&(seven_segment_ptr->segment_pins[SEGMENT_PIN2]));
       ret = MGPIO_SetPinDirection(&(seven_segment_ptr->segment_pins[SEGMENT_PIN3]));
       ret = MGPIO_SetPinDirection(&(seven_segment_ptr->segment_pins[SEGMENT_PIN4]));
       ret = MGPIO_SetPinDirection(&(seven_segment_ptr->segment_pins[SEGMENT_PIN5]));
       ret = MGPIO_SetPinDirection(&(seven_segment_ptr->segment_pins[SEGMENT_PIN6]));

    }
    return ret;
}

/**
 * @brief  This function used to display a number on seven segment.
 * @Author Ali Morsy
 * @version 1.0
 * @param  seven_segment_ptr pointer to the seven segment configuration @ref seven_segment_t.
 * @param number display it on seven segment.
 * @return Std_ReturnType status of the function
 *                         (OPERATION_SUCCESS) : the function done successfully
 *                         (OPERATION_ERROR) : the function done  not successfully
 */
Std_ReturnType seven_segment_display(const seven_segment_t* seven_segment_ptr, uint8_t number)
{
    Std_ReturnType ret = OPERATION_SUCCESS;
    uint8_t Local_segment_val = 0x00;

    if(seven_segment_ptr  == NULL)
    {
        ret = OPERATION_ERROR;
    }
    else
    {
    	Local_segment_val = seven_segment_codes[number];
       if(seven_segment_ptr->segment_type == SEGMENT_COMMON_ANODE)
       {
           number = ~number;
       }
       ret = MGPIO_SetPinValue(&(seven_segment_ptr->segment_pins[SEGMENT_PIN0]), ( Local_segment_val     & 0x01) );
       ret = MGPIO_SetPinValue(&(seven_segment_ptr->segment_pins[SEGMENT_PIN1]), ((Local_segment_val>>1) & 0x01) );
       ret = MGPIO_SetPinValue(&(seven_segment_ptr->segment_pins[SEGMENT_PIN2]), ((Local_segment_val>>2) & 0x01) );
       ret = MGPIO_SetPinValue(&(seven_segment_ptr->segment_pins[SEGMENT_PIN3]), ((Local_segment_val>>3) & 0x01) );
       ret = MGPIO_SetPinValue(&(seven_segment_ptr->segment_pins[SEGMENT_PIN4]), ((Local_segment_val>>4) & 0x01) );
       ret = MGPIO_SetPinValue(&(seven_segment_ptr->segment_pins[SEGMENT_PIN5]), ((Local_segment_val>>5) & 0x01) );
       ret = MGPIO_SetPinValue(&(seven_segment_ptr->segment_pins[SEGMENT_PIN6]), ((Local_segment_val>>6) & 0x01) );
    }
    return ret;
}

