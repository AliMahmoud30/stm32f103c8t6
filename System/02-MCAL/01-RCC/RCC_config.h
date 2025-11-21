/****************************************************************************************/
/* Author     : ALi Morsy							   								    */
/* Version    :  V01							     	 							    */
/* Date	      :                                                           				 */
/****************************************************************************************/


#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/*! RCC_HSI_CLOCK_STATE Options :
    RCC_ENABLE_OPTION
    RCC_DISABLE_OPTION	    	*/
#define RCC_HSI_CLOCK_STATE			RCC_DISABLE_OPTION

/*! RCC_HSE_CLOCK_STATE Options :
    RCC_HSE_CRYSTAL
    RCC_HSE_RC
    RCC_DISABLE_OPTION	    	*/
#define RCC_HSE_CLOCK_STATE			RCC_HSE_CRYSTAL

/*! RCC_PLL_CLOCK_STATE Options :
    RCC_ENABLE_OPTION
    RCC_DISABLE_OPTION	    	*/
#define RCC_PLL_CLOCK_STATE			RCC_ENABLE_OPTION

/*! RCC_SYSTEM_CLOCK Options :
    RCC_HSE_CRYSTAL
    RCC_HSE_RC
    RCC_HSI
    RCC_PLL	    	*/
#define RCC_SYSTEM_CLOCK_TYPE		RCC_HSE_CRYSTAL


/*! Options : RCC_PLL_IN_HSE_DIV_2
              RCC_PLL_IN_HSI_DIV_2
              RCC_PLL_IN_HSE        */
/*! Note : Select Value Only if you have PLL as Input Clock source */
#if RCC_SYSTEM_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT    RCC_PLL_IN_HSE
#endif // RCC_CLOCK_TYPE


/*! Options : 2 to 16  */
/*! Note : Select Value Only if you have PLL as Input Clock source */
#if RCC_SYSTEM_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL  4
#endif


#endif
