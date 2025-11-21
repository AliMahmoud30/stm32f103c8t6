/*********************************************************************/
/* Author	: Ali Morsy 				                       		 */
/* Version  : V01                                                    */
/* date  		: 					    						     */
/* Description : GPIO REGISTERS									     */
/*********************************************************************/

/*********************************************************************/
/*  Guard of file will call one time in .c                           */
/*********************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/*=====================================================================================
 *              Section: Includes
 =====================================================================================*/

/*=====================================================================================
 *              Section: Macro Declarations
 =====================================================================================*/

/*   INPUT Modes    */
#define INPUT_ANALOG          0b0000
#define INPUT_FLOATING        0b0100
#define INPUT_PULL_UP_DOWEN   0b1000
/**********************************************/
 /*   OUTPUT Modes    */
  /*   10MHZ SPEED   */
#define OUTPUT_SPEED_10MHZ_PP       0b0001
#define OUTPUT_SPEED_10MHZ_OD       0b0101
#define OUTPUT_SPEED_10MHZ_AFPP     0b1001
#define OUTPUT_SPEED_10MHZ_AFOD     0x1101
  /*   2 MHZ SPEED   */
#define OUTPUT_SPEED_2MHZ_PP        0b0010
#define OUTPUT_SPEED_2MHZ_OD        0b0110
#define OUTPUT_SPEED_2MHZ_AFPP      0b1010
#define OUTPUT_SPEED_2MHZ_AFOD      0b1110

  /*   50 MHZ SPEED   */
#define OUTPUT_SPEED_50MHZ_PP       0b0011
#define OUTPUT_SPEED_50MHZ_OD       0b0111
#define OUTPUT_SPEED_50HZ_AFPP      0b1011
#define OUTPUT_SPEED_50HZ_AFOD      0b1111


/* Pull_UP_Down */
#define PULLUP		1
#define PULLDOWN	0
/*=====================================================================================
 *              Section: Data Type Declarations
 =====================================================================================*/

/*!
 * MCU GPIO pin logic states
 */
typedef enum
{
	LOGIC_LOW  = 0,    		/*!< GPIO_LOW */
	LOGIC_HIGH = 1    		/*!< GPIO_HIGH */
}gpio_logic_t;


/*!
 * MCU GPIO PORTx definition
 */
typedef enum
{
	GPIOA  = 0,    		/*!< GPIOA */
	GPIOB  = 1,    		/*!< GPIOB */
	GPIOC  = 2,     	/*!< GPIOC */
	MAX_PORT_NUM 		/*!< MAX_PORT_NUM */
}gpio_port_index_t;


/*!
 * MCU GPIO PINx definition
 */
typedef enum
{
	PIN0  = 0,  		/*!< PIN0 */
	PIN1  = 1,  		/*!< PIN1 */
	PIN2  = 2,  		/*!< PIN2 */
	PIN3  = 3,  		/*!< PIN3 */
	PIN4  = 4,  		/*!< PIN4 */
	PIN5  = 5,  		/*!< PIN5 */
	PIN6  = 6,  		/*!< PIN6 */
	PIN7  = 7,  		/*!< PIN7 */
	PIN8  = 8,  		/*!< PIN8 */
	PIN9  = 9,  		/*!< PIN9 */
	PIN10 =  10,		/*!< PIN10 */
	PIN11 = 11 ,		/*!< PIN11 */
	PIN12 =  12,		/*!< PIN12 */
	PIN13 =  13,		/*!< PIN13 */
	PIN14 =  14,		/*!< PIN14 */
	PIN15 =  15,		/*!< PIN15 */
	MAX_PIN_NUM 		/*!< MAX_PIN_NUM */
}gpio_pin_index_t;

typedef enum
{
	PIN_INPUT_ANALOG,				/*!   INPUT Modes    */
	PIN_INPUT_FLOATING,
	PIN_INPUT_PULL_UP_DOWEN,
	PIN_OUTPUT_SPEED_10MHZ_PP,    	/*!   10MHZ SPEED   */
	PIN_OUTPUT_SPEED_10MHZ_OD,
	PIN_OUTPUT_SPEED_10MHZ_AFPP,
	PIN_OUTPUT_SPEED_10MHZ_AFOD,
	PIN_OUTPUT_SPEED_2MHZ_PP,      /*!   2 MHZ SPEED    */
	PIN_OUTPUT_SPEED_2MHZ_OD,
	PIN_OUTPUT_SPEED_2MHZ_AFPP,
	PIN_OUTPUT_SPEED_2MHZ_AFOD,
	PIN_OUTPUT_SPEED_50MHZ_PP, 	   /*!   50 MHZ SPEED   */
	PIN_OUTPUT_SPEED_50MHZ_OD,
	PIN_OUTPUT_SPEED_50HZ_AFPP,
	PIN_OUTPUT_SPEED_50HZ_AFOD
}pin_mode_cnfg_t;

/*!
 * MCU GPIO PINx configuration
 */
typedef struct
{
    uint8_t port      :2; /*! @ref  gpio_port_index_t	*/
    uint8_t pin       :4; /*! @ref  gpio_pin_index_t	*/
    uint8_t pin_mode  :4; /*! @ref  pin_mode_cnfg_t		*/
    uint8_t logic     :1; /*! @ref  gpio_logic_t		*/
    uint8_t reserved  :5;
}pin_config_t;

/*=====================================================================================
 *              Section: variables Declarations
 =====================================================================================*/


/*=====================================================================================
 *              Section: Function Declarations
 =====================================================================================*/

/*!
 * Set Direction
*/
Std_ReturnType MGPIO_SetPinDirection(const pin_config_t* _pin_config);
Std_ReturnType MGPIO_SetPORTDirection(const pin_config_t* _pin_config);
Std_ReturnType MGPIO_SetHighPinsDirection(const pin_config_t* _pin_config);
Std_ReturnType MGPIO_SetLowPinsDirection(const pin_config_t* _pin_config);
/*!
 * Set Value
*/
Std_ReturnType MGPIO_SetPinValue(const pin_config_t* _pin_config , gpio_logic_t copy_logic_val );
void MGPIO_SetPORTValue(gpio_port_index_t copy_port_index, uint16_t copy_port_Value );
void MGPIO_SetHighPinsValue(gpio_port_index_t copy_port_index, uint8_t copy_port_Value );
void MGPIO_SetLowPinsValue(gpio_port_index_t copy_port_index, uint8_t copy_port_Value);
/*!
 * Get Value
*/
Std_ReturnType MGPIO_GetPinValue(pin_config_t* _pin_config , gpio_logic_t* logic_val_returned);
void MGPIO_SetPullUpDown(pin_config_t* _pin_config, uint8_t copy_u8mode);
void MGPIO_TogglePin(pin_config_t* _pin_config);
/*!
 * Lock/UnLock pin
*/
void MGPIO_voidLockPin(uint8_t copy_u8PORT,uint8_t copy_u8PIN);
void MGPIO_voidUnLockPin(uint8_t copy_u8PORT,uint8_t copy_u8PIN);







#endif



