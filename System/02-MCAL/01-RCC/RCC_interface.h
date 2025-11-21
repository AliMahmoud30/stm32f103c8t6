/****************************************************************************************/
/*Author     : ALi Morsy															    */
/*Version    :  V01								  								        */
/*Date	     :  			                     								        */
/* ************************************************************************************* */

#ifndef _RCC_INTERFACE_H
#define _RCC_INTERFACE_H

//#define RCC_AHB    0
//#define RCC_APB1   1
//#define RCC_APB2   2


/*!
 * MCU AMPA Bus.
 */
typedef enum
{
	RCC_AHB,
	RCC_APB1,
	RCC_APB2,
	MAX_BUS_NUM
}RCC_Bus_Type_t;

/*!
 * MCU Clock Source Type for (RCC_CR) register.
 */
typedef enum
{
	HSI_CLOCK,
	HSE_CLOCK,
	PLL_CLOCK,
	MAX_CLOCK_SOURCE_NUM
}Clock_Source_Type_t;

/*!
 * APB2 peripheral reset register (RCC_APB2RSTR)
 */
typedef enum
{
	AFIORST 	= 0,          /*!< AFIORST 	  */
	IOPARST 	= 2,          /*!< IOPORTARST */
	IOPBRST 	= 3,          /*!< IOPORTBRST */
	IOPCRST 	= 4,          /*!< IOPORTCRST */
	IOPDRST 	= 5,          /*!< IOPORTDRST */
	IOPERST 	= 6,          /*!< IOPORTERST */
	IOPFRST 	= 7,          /*!< IOPORTFRST */
	IOPGRST 	= 8,          /*!< IOPORTGRST */
	ADC1RST 	= 9,          /*!< ADC1RST    */
	ADC2RST 	= 10,         /*!< ADC2RST    */
	TIM1RST 	= 11,         /*!< TIM1RST    */
	SPI1RST 	= 12,         /*!< SPI1RST    */
	TIM8RST 	= 13,         /*!< TIM8RST    */
	USART1RST 	= 14,         /*!< USART1RST  */
	ADC3RST 	= 15,         /*!< ADC3RST    */
	MAX_NUM_OF_APB2_RST_PER/*!< MAX_NUM_OF_APB2_RST_PER */
}RCC_APB2RSTR_type_t;

/*!
 * APB1 peripheral reset register (RCC_APB1RSTR)
 */
typedef enum
{
	TIM2RST 	= 0,          /*!< TIM2RST */
	TIM3RST		= 1,          /*!< TIM3RST */
	TIM4RST 	= 2,          /*!< TIM4RST */
	TIM5RST 	= 3,          /*!< TIM5RST */
	TIM6RST 	= 4,          /*!< TIM6RST */
	TIM7RST 	= 5,          /*!< TIM7RST */
	WWDGRST 	= 11,         /*!< WWDGRST */
	SPI2RST 	= 14,         /*!< SPI2RST */
	SPI3RST 	= 15,         /*!< SPI3RST */
	USART2RST	= 17,         /*!< USART2RST */
	USART3RST 	= 18,      	  /*!< USART3RST */
	USART4RST 	= 19,      	  /*!< USART4RST */
	USART5RST 	= 20,         /*!< USART5RST */
	I2C1RST 	= 21,         /*!< I2C1RST */
	I2C2RST 	= 22,         /*!< I2C2RST */
	USBRST 		= 23,         /*!< USBRST */
	CANRST	 	= 25,         /*!< CANRST */
	BKPRST	 	= 27,         /*!< BKPRST */
	PWRRST	 	= 28,         /*!< PWRRST */
	DACRST	 	= 29,         /*!< DACRST */
	MAX_NUM_OF_APB1_RST_PER/*!< MAX_NUM_OF_APB1_RST_PER */
}RCC_APB1RSTR_type_t;

/*!
 * AHB peripheral clock enable register (RCC_AHBENR)
 */
typedef enum
{
	DMA1EN 		= 0,           /*!< DMA1EN */
	DMA2EN		= 1,            /*!< DMA2EN */
	SRAMEN 		= 2,           /*!< SRAMEN */
	FLITFEN 	= 4,           /*!< FLITFEN */
	CRCEN 		= 6,            /*!< CRCEN */
	FSMCEN 		= 8,           /*!< FSMCEN */
	SDIOEN 		= 10,          /*!< SDIOEN */
	MAX_NUM_OF_AHB_CLK_PERPH/*!< MAX_NUM_OF_AHB_CLK_PERPH */
}RCC_AHBENR_Clk_Enable_t;

/*!
 * APB2 peripheral clock enable register (RCC_APB2ENR)
 */
typedef enum
{
	AFIOEN 		= 0,            /*!< AFIOEN    */
	IOPAEN 		= 2,            /*!< IOPORTAEN */
	IOPBEN 		= 3,            /*!< IOPORTBEN */
	IOPCEN 		= 4,            /*!< IOPORTCEN */
	IOPDEN 		= 5,            /*!< IOPORTDEN */
	IOPEEN 		= 6,            /*!< IOPORTEEN */
	IOPFEN 		= 7,            /*!< IOPORTFEN */
	IOPGEN 		= 8,            /*!< IOPORTGEN */
	ADC1EN	 	= 9,            /*!< ADC1EN    */
	ADC2EN	 	= 10,           /*!< ADC2EN    */
	TIM1EN		= 11,           /*!< TIM1EN    */
	SPI1EN		= 12,           /*!< SPI1EN    */
	TIM8EN		= 13,           /*!< TIM8EN    */
	USART1EN 	= 14,           /*!< USART1EN  */
	ADC3EN	 	= 15,           /*!< ADC3EN    */
	MAX_NUM_OF_APB2_CLK_PERPH/*!< MAX_NUM_OF_APB2_CLK_PERPH */
}RCC_APB2ENR_Clk_Enable_t;

/*!
 * APB1 peripheral clock enable register (RCC_APB1ENR)
 */
typedef enum
{
	TIM2EN 		= 0,            /*!< TIM2EN */
	TIM3EN		= 1,             /*!< TIM3EN */
	TIM4EN 		= 2,            /*!< TIM4EN */
	TIM5EN 		= 3,            /*!< TIM5EN */
	TIM6EN 		= 4,            /*!< TIM6EN */
	TIM7EN 		= 5,            /*!< TIM7EN */
	WWDEN 		= 11,            /*!< WWDEN */
	SPI2EN	 	= 14,           /*!< SPI2EN */
	SPI3EN	 	= 15,           /*!< SPI3EN */
	USART2EN	= 17,           /*!< USART2EN */
	USART3EN 	= 18,          /*!< USART3EN */
	USART4EN 	= 19,          /*!< USART4EN */
	USART5EN 	= 20,          /*!< USART5EN */
	I2C1EN	 	= 21,           /*!< I2C1EN */
	I2C2EN	 	= 22,           /*!< I2C2EN */
	USBEN 		= 23,            /*!< USBEN */
	CANEN	 	= 25,            /*!< CANEN */
	BKPEN	 	= 27,            /*!< BKPEN */
	PWREN	 	= 28,            /*!< PWREN */
	DACEN	 	= 29,            /*!< DACEN */
	MAX_NUM_OF_APB1_CLK_PERPH/*!< MAX_NUM_OF_APB1_CLK_PERPH */
}RCC_APB1RENR_Clk_Enable_t;

void RCC_voidInitSysClock(void);
void RCC_voidEnableClockSource(Clock_Source_Type_t clock_source);
void RCC_voidDisableClockSource(Clock_Source_Type_t clock_source);
void RCC_voidEnablePeripheralClock(RCC_Bus_Type_t copy_BusType, uint8_t copy_u8PerId);
void RCC_voidDisablePeripheralClock(RCC_Bus_Type_t copy_BusType, uint8_t copy_u8PerId );
void RCC_voidResetPeripheral(RCC_Bus_Type_t copy_BusType, uint8_t copy_u8PerId);
#endif
