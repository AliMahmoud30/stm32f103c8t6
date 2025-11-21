/*********************************************************************/
/* Author	: Ali Morsy 				                       		 */
/* Version  : V01                                                    */
/* date  		: 					    					     	 */
/* Description : SEVEN_SEGMENT Module							     */
/*********************************************************************/

/*********************************************************************/
/*  Guard of file will call one time in .c                           */
/*********************************************************************/

#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H

/*=====================================================================================
 *              Section: Includes
 =====================================================================================*/

/*=====================================================================================
 *              Section: Macro Declarations
 =====================================================================================*/

#define SEGMENT_PIN0    (uint8_t)0
#define SEGMENT_PIN1    (uint8_t)1
#define SEGMENT_PIN2    (uint8_t)2
#define SEGMENT_PIN3    (uint8_t)3
#define SEGMENT_PIN4    (uint8_t)4
#define SEGMENT_PIN5    (uint8_t)5
#define SEGMENT_PIN6    (uint8_t)6
#define SEGMENT_DOT   	(uint8_t)7
/*=====================================================================================
 *              Section: Macro Function Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: Data Type Declarations
 =====================================================================================*/
typedef enum
{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE,
}segment_type_t;

typedef struct
{
    pin_config_t      segment_pins[7];
    segment_type_t    segment_type;
}seven_segment_t;

/*=====================================================================================
 *              Section: variables Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: Function Declarations
 =====================================================================================*/
Std_ReturnType seven_segment_initialization(const seven_segment_t* seven_segment_ptr);
Std_ReturnType seven_segment_display(const seven_segment_t* seven_segment_ptr, uint8_t number);





#endif // SEVEN_SEGMENT_INTERFACE_H



