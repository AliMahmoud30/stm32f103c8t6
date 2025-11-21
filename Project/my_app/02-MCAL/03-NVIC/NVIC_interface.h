/*********************************************************************/
/* Author: Ali Morsy 											     */
/* Version : V01                                                     */
/* date  :  													     */
/* Description : NVIC MODULE									     */
/*********************************************************************/

#ifndef	NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/*=====================================================================================
 *              Section: Includes
 =====================================================================================*/

/*=====================================================================================
 *              Section: Macro Declarations
 =====================================================================================*/
#define GROUP3	0x05FA0300	// 4bits for group (IPR) => group
#define GROUP4	0x05FA0400	// 3bits for group and 1bit for sub
#define GROUP5	0x05FA0500	// 2bits for group and 2bit for sub
#define GROUP6	0x05FA0600	// 1bits for group and 3bit for sub
#define GROUP7	0x05FA0700	// 0 group and 4bit for sub

/*=====================================================================================
 *              Section: Macro Function Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: Data Type Declarations
 =====================================================================================*/

/**
  * @brief  STM32F10xxx NVIC Interrupt Position Numbers
  * @note   Based on STM32F10xxx vector table
  */
typedef enum
{
    NVIC_WWDG           = 0,   /**< Window watchdog interrupt */
    NVIC_PVD            = 1,   /**< PVD through EXTI Line detection interrupt */
    NVIC_TAMPER         = 2,   /**< Tamper interrupt */
    NVIC_RTC            = 3,   /**< RTC global interrupt */
    NVIC_FLASH          = 4,   /**< Flash global interrupt */
    NVIC_RCC            = 5,   /**< RCC global interrupt */
    NVIC_EXTI0          = 6,   /**< EXTI Line0 interrupt */
    NVIC_EXTI1          = 7,   /**< EXTI Line1 interrupt */
    NVIC_EXTI2          = 8,   /**< EXTI Line2 interrupt */
    NVIC_EXTI3          = 9,   /**< EXTI Line3 interrupt */
    NVIC_EXTI4          = 10,  /**< EXTI Line4 interrupt */
    NVIC_DMA1_Channel1  = 11,  /**< DMA1 Channel1 global interrupt */
    NVIC_DMA1_Channel2  = 12,  /**< DMA1 Channel2 global interrupt */
    NVIC_DMA1_Channel3  = 13,  /**< DMA1 Channel3 global interrupt */
    NVIC_DMA1_Channel4  = 14,  /**< DMA1 Channel4 global interrupt */
    NVIC_DMA1_Channel5  = 15,  /**< DMA1 Channel5 global interrupt */
    NVIC_DMA1_Channel6  = 16,  /**< DMA1 Channel6 global interrupt */
    NVIC_DMA1_Channel7  = 17,  /**< DMA1 Channel7 global interrupt */
    NVIC_ADC1_2         = 18,  /**< ADC1 and ADC2 global interrupt */
    NVIC_USB_HP_CAN_TX  = 19,  /**< USB High Priority or CAN TX interrupts */
    NVIC_USB_LP_CAN_RX0 = 20,  /**< USB Low Priority or CAN RX0 interrupts */
    NVIC_CAN_RX1        = 21,  /**< CAN RX1 interrupt */
    NVIC_CAN_SCE        = 22,  /**< CAN SCE interrupt */
    NVIC_EXTI9_5        = 23,  /**< EXTI Line[9:5] interrupts */
    NVIC_TIM1_BRK       = 24,  /**< TIM1 Break interrupt */
    NVIC_TIM1_UP        = 25,  /**< TIM1 Update interrupt */
    NVIC_TIM1_TRG_COM   = 26,  /**< TIM1 Trigger and Commutation interrupts */
    NVIC_TIM1_CC        = 27,  /**< TIM1 Capture Compare interrupt */
    NVIC_TIM2           = 28,  /**< TIM2 global interrupt */
    NVIC_TIM3           = 29,  /**< TIM3 global interrupt */
    NVIC_TIM4           = 30,  /**< TIM4 global interrupt */
    NVIC_I2C1_EV        = 31,  /**< I2C1 event interrupt */
    NVIC_I2C1_ER        = 32,  /**< I2C1 error interrupt */
    NVIC_I2C2_EV        = 33,  /**< I2C2 event interrupt */
    NVIC_I2C2_ER        = 34,  /**< I2C2 error interrupt */
    NVIC_SPI1           = 35,  /**< SPI1 global interrupt */
    NVIC_SPI2           = 36,  /**< SPI2 global interrupt */
    NVIC_USART1         = 37,  /**< USART1 global interrupt */
    NVIC_USART2         = 38,  /**< USART2 global interrupt */
    NVIC_USART3         = 39,  /**< USART3 global interrupt */
    NVIC_EXTI15_10      = 40,  /**< EXTI Line[15:10] interrupts */
    NVIC_RTCAlarm       = 41,  /**< RTC alarm through EXTI line interrupt */
    NVIC_USBWakeup      = 42,  /**< USB wakeup from suspend through EXTI line interrupt */
    NVIC_TIM8_BRK       = 43,  /**< TIM8 Break interrupt */
    NVIC_TIM8_UP        = 44,  /**< TIM8 Update interrupt */
    NVIC_TIM8_TRG_COM   = 45,  /**< TIM8 Trigger and Commutation interrupts */
    NVIC_TIM8_CC        = 46,  /**< TIM8 Capture Compare interrupt */
    NVIC_ADC3           = 47,  /**< ADC3 global interrupt */
    NVIC_FSMC           = 48,  /**< FSMC global interrupt */
    NVIC_SDIO           = 49,  /**< SDIO global interrupt */
    NVIC_TIM5           = 50,  /**< TIM5 global interrupt */
    NVIC_SPI3           = 51,  /**< SPI3 global interrupt */
    NVIC_UART4          = 52,  /**< UART4 global interrupt */
    NVIC_UART5          = 53,  /**< UART5 global interrupt */
    NVIC_TIM6           = 54,  /**< TIM6 global interrupt */
    NVIC_TIM7           = 55,  /**< TIM7 global interrupt */
    NVIC_DMA2_Channel1  = 56,  /**< DMA2 Channel1 global interrupt */
    NVIC_DMA2_Channel2  = 57,  /**< DMA2 Channel2 global interrupt */
    NVIC_DMA2_Channel3  = 58,  /**< DMA2 Channel3 global interrupt */
    NVIC_DMA2_Channel4_5 = 59  /**< DMA2 Channel4 and DMA2 Channel5 global interrupts */
} NVIC_IRQn_Type;


/*=====================================================================================
 *              Section: variables Declarations
 =====================================================================================*/


/*=====================================================================================
 *              Section: Function Declarations
 =====================================================================================*/
void MNVIC_voidEnableInterrupt(NVIC_IRQn_Type  copy_irq_position);
void MNVIC_voidDisableInterrupt(NVIC_IRQn_Type copy_irq_position);
void MNVIC_voidSetPendingFlag(NVIC_IRQn_Type   copy_irq_position);
void MNVIC_voidClearPendingFlag(NVIC_IRQn_Type copy_irq_position);
uint8_t MNVIC_voidGetActiveFlag(NVIC_IRQn_Type copy_irq_position);
void MNVIC_voidInit(void);
void MNVIC_voidSetPriority(uint8_t copy_u8PeripheralIdx, uint8_t copy_u8priority);
/* eng ahmed atia*/
//void MNVIC_voidSetPrioriy(s8 copy_s8IntID, u8 copy_u8GroupPrioriy,u8 copy_u8Subpriority, u32 copy_u32Group);


#endif
