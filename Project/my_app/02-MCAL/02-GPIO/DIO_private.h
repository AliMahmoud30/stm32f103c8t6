/*********************************************************************/
/* Author: Ali Morsy 											     */
/* Version : V01                                                     */
/* date  : 			 											     */
/* Description : GPIO REGISTERS									     */
/*********************************************************************/

/*********************************************************************/
/* Guard of file will call one time in .c                            */
/*********************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/*=====================================================================================
 *              Section: Includes
 =====================================================================================*/

/*=====================================================================================
 *              Section: Macro Declarations
 =====================================================================================*/

#define GPIOA_BASE_ADDRESS    (volatile uint32_t*)0x40010800    /*! PORTA  Base Address */
#define GPIOB_BASE_ADDRESS    (volatile uint32_t*)0x40010C00    /*! PORTB  Base Address */
#define GPIOC_BASE_ADDRESS    (volatile uint32_t*)0x40011000    /*! PORTC  Base Address */

/*=====================================================================================
 *              Section: Macro Function Declarations
 =====================================================================================*/


 /*=====================================================================================
  *              Section: Data Type Declarations
  =====================================================================================*/
/*!
 *
 */
typedef struct
{
	uint32_t GPIO_CRL;
	uint32_t GPIO_CRH;
	uint32_t GPIO_IDR;
	uint32_t GPIO_ODR;
	uint32_t GPIO_BSR;
	uint32_t GPIO_BRR;
	uint32_t GPIO_LCK;
}gpio_reg_def_type_t;


#define GPIO_PORTA_REGS							((gpio_reg_def_type_t*)GPIOA_BASE_ADDRESS)
#define GPIO_PORTB_REGS							((gpio_reg_def_type_t*)GPIOB_BASE_ADDRESS)
#define GPIO_PORTC_REGS							((gpio_reg_def_type_t*)GPIOC_BASE_ADDRESS)

/*=====================================================================================
 *              Section:  private Function Declarations
 =====================================================================================*/
static void MGPIO_Set_PORTA_Pin_Mode_Configuration(gpio_pin_index_t pin_index, uint8_t copy_u8pin_mode);
static void MGPIO_Set_PORTB_Pin_Mode_Configuration(gpio_pin_index_t pin_index, uint8_t copy_u8pin_mode);
static void MGPIO_Set_PORTC_Pin_Mode_Configuration(gpio_pin_index_t pin_index, uint8_t copy_u8pin_mode);


             /*REGISTERS ADDRESSES For PORTA  */
//#define GPIOA_CRL   	      *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x00))
//#define GPIOA_CRH   	      *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x04))
//#define GPIOA_IDR   	      *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x08))
//#define GPIOA_ODR   	      *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x0C))
//#define GPIOA_BSR   	      *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x10))
//#define GPIOA_BRR   	      *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x14))
//#define GPIOA_LCK   	      *((volatile u32*)(GPIOA_BASE_ADDRESS + 0x18))


             /*REGISTERS ADDRESSES FOR PORTB  */
//#define GPIOB_CRL   	      *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x00))
//#define GPIOB_CRH   	      *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x04))
//#define GPIOB_IDR   	      *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x08))
//#define GPIOB_ODR   	      *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x0C))
//#define GPIOB_BSR   	      *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x10))
//#define GPIOB_BRR   	      *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x14))
//#define GPIOB_LCK   	      *((volatile u32*)(GPIOB_BASE_ADDRESS + 0x18))


             /*REGISTERS ADDRESSES FOR PORTC  */
//#define GPIOC_CRL   	      *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x00))
//#define GPIOC_CRH   	      *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x04))
//#define GPIOC_IDR   	      *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x08))
//#define GPIOC_ODR   	      *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x0C))
//#define GPIOC_BSR   	      *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x10))
//#define GPIOC_BRR   	      *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x14))
//#define GPIOC_LCK   	      *((volatile u32*)(GPIOC_BASE_ADDRESS + 0x18))

#endif //DIO_PRIVATE_H
