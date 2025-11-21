/* *****************************************************************************************/
/*Author     : ALi Morsy							                                       */
/*Version    :  V01								                                           */
/*Date	     :  			                                                               */
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/*!
 *
 */
void RCC_voidInitSysClock(void)
{
	uint32_t Local_CR_Reg_Value = 0;  // control register value
	uint32_t Local_CFR_Reg_Value = 0; // configuration register value

  #if RCC_SYSTEM_CLOCK_TYPE == RCC_HSE_CRYSTAL
	Local_CR_Reg_Value  |= RCC_HSE_ON;
	Local_CFR_Reg_Value |= RCC_HSE_SYS_CLOCK;  /* Enable HSE  with no Bypass (CRYSTAL)*/
  #elif RCC_SYSTEM_CLOCK_TYPE == RCC_HSE_RC
	Local_CR_Reg_Value  |= RCC_HSE_ON | RCC_HSE_BYPS; /*Enable HSE with Bypass (RC) */
	Local_CFR_Reg_Value |= RCC_HSE_SYS_CLOCK;

  #elif RCC_SYSTEM_CLOCK_TYPE == RCC_HSI
	Local_CR_Reg_Value  |= RCC_HSI_ON;          /* Enable HSI +Trimming = 0*/
	Local_CFR_Reg_Value |= RCC_HSI_SYS_CLOCK;
  #elif RCC_SYSTEM_CLOCK_TYPE == RCC_PLL
    #if RCC_PLL_INPUT   == RCC_PLL_IN_HSE_DIV_2
		Local_CR_Reg_Value   |= RCC_HSE_ON | RCC_PLLON;         /* Enable PLL and HSE */
		Local_CFR_Reg_Value  = 0x00030002;
    #elif RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
		Local_CR_Reg_Value   |= RCC_HSI_ON | RCC_PLLON;     	/* Enable PLL and HSI */
		RCC_Reg_Def->RCC_CFGR = 0x00000002;
    #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		Local_CR_Reg_Value   |= RCC_HSE_ON | RCC_PLLON;         /* Enable PLL and HSE */
		RCC_Reg_Def->RCC_CFGR = 0x00010002;
    #endif // RCC_PLL_IN

	RCC_Reg_Def->RCC_CFGR|=( (RCC_PLL_MUL_VAL-2) << 21);  // RCC Multiplication

  #else
        #error("You chosed Wrong Clock Type")

  #endif // RCC_CLOCK_TYPE

	RCC_Reg_Def->RCC_CR   = Local_CR_Reg_Value;
	RCC_Reg_Def->RCC_CFGR = Local_CFR_Reg_Value;
}

/*!
 *
 * @param clock_source
 */
void RCC_voidEnableClockSource(Clock_Source_Type_t clock_source)
{
    if(clock_source < MAX_CLOCK_SOURCE_NUM)
    {
        switch(clock_source)
        {
            case HSI_CLOCK  : SET_BIT(RCC_Reg_Def->RCC_CR,  0); break;
            case HSE_CLOCK  : SET_BIT(RCC_Reg_Def->RCC_CR, 16); break;
            case PLL_CLOCK  : SET_BIT(RCC_Reg_Def->RCC_CR, 24); break;
            default       : /* Return Error*/                	break;
        }
    }
    else
    {
        /*Return Error*/
    }
}

/*!
 *
 * @param clock_source
 */
void RCC_voidDisableClockSource(Clock_Source_Type_t clock_source)
{
    if(clock_source < MAX_CLOCK_SOURCE_NUM)
    {
        switch(clock_source)
        {
            case HSI_CLOCK  : CLR_BIT(RCC_Reg_Def->RCC_CR,  0); break;
            case HSE_CLOCK  : CLR_BIT(RCC_Reg_Def->RCC_CR, 16); break;
            case PLL_CLOCK  : CLR_BIT(RCC_Reg_Def->RCC_CR, 24); break;
            default       : /* Return Error*/                	break;
        }
    }
    else
    {
        /*Return Error*/
    }
}

/*!
 *
 * @param copy_BusType
 * @param copy_u8PerId
 */
void RCC_voidEnablePeripheralClock(RCC_Bus_Type_t copy_BusType, uint8_t copy_u8PerId)
{
    if(copy_u8PerId <=31)
    {
        switch(copy_BusType)
        {
            case RCC_AHB  : SET_BIT(RCC_Reg_Def->RCC_AHBENR,  copy_u8PerId); break;
            case RCC_APB1 : SET_BIT(RCC_Reg_Def->RCC_APB1ENR, copy_u8PerId); break;
            case RCC_APB2 : SET_BIT(RCC_Reg_Def->RCC_APB2ENR, copy_u8PerId); break;
            default       : /* Return Error*/                     			 break;
        }
    }
    else
    {
        /*Return Error*/
    }
}

/*!
 *
 * @param copy_BusType
 * @param copy_u8PerId
 */
void RCC_voidDisablePeripheralClock(RCC_Bus_Type_t copy_BusType, uint8_t copy_u8PerId)
{
    if(copy_u8PerId <=31)
    {
        switch(copy_BusType)
        {
            case RCC_AHB  : CLR_BIT(RCC_Reg_Def->RCC_AHBENR,  copy_u8PerId);  break;
            case RCC_APB1 : CLR_BIT(RCC_Reg_Def->RCC_APB1ENR, copy_u8PerId);  break;
            case RCC_APB2 : CLR_BIT(RCC_Reg_Def->RCC_APB2ENR, copy_u8PerId);  break;
            default       : /*! Return Error */  		                      break;
        }
    }
    else
    {
        /*!
         * Return Error
         */
    }
}

/*!
 *
 * @param copy_BusType
 * @param copy_u8PerId
 */
void RCC_voidResetPeripheral(RCC_Bus_Type_t copy_BusType, uint8_t copy_u8PerId)
{
    if(copy_u8PerId <=31)
    {
        switch(copy_BusType)
        {
         	/*! atomic operation  1: effect, 0: No effect */
            case RCC_APB1 : RCC_Reg_Def->RCC_APB1RSTR =  (uint32_t)1 << copy_u8PerId;  break;
            case RCC_APB2 : RCC_Reg_Def->RCC_APB2RSTR =  (uint32_t)1 << copy_u8PerId;  break;
            default       : /*! Return Error */  		                      		   break;
        }
    }
    else
    {
        /*!
         * Return Error
         */
    }
}

