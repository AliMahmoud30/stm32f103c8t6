/*********************************************************************/
/* Author: Ali Morsy 											     */
/* Version : V01                                                     */
/* date  :  													     */
/* Description : NVIC Register Description									     */
/*********************************************************************/
#ifndef	NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*=====================================================================================
 *              Section: Includes
 =====================================================================================*/

/*=====================================================================================
 *              Section: Macro Declarations
 =====================================================================================*/
/* 0xE000E100  Base Address */

#define  NVIC_ISER0		*((uint32_t*)0xE000E100)	/* Enable External Interrupts from 0 to 31   */
#define  NVIC_ISER1		*((uint32_t*)0xE000E104)	/* Enable External Interrupts from 32 to 63   */

#define  NVIC_ICER0		*((uint32_t*)0xE000E180)	/* Disable External Interrupts from 0 to 31  */
#define  NVIC_ICER1		*((uint32_t*)0xE000E184) /* Disable External Interrupts from 32 to 63  */

#define  NVIC_ISPR0		*((uint32_t*)0xE000E200) /* Set Pending Flag Interrupts from 0 to 31  */
#define  NVIC_ISPR1		*((uint32_t*)0xE000E204) /* Set Pending Flag Interrupts from 32 to 63 */

#define  NVIC_ICPR0		*((uint32_t*)0xE000E280) /* Clear Pending Flag Interrupts from 0 to 31  */
#define  NVIC_ICPR1		*((uint32_t*)0xE000E284)	/* Clear Pending Flag Interrupts from 32 to 63 */

#define  NVIC_IABR0		*((volatile uint32_t*)0xE000E300) /* Read Active Flag Interrupts from 0 to 31  */
#define  NVIC_IABR1		*((volatile uint32_t*)0xE000E304) /* Read Active Flag Interrupts from 32 to 59  */

#define NVIC_IPR		 ((volatile uint8_t* )0xE000E400)
//#define SCB_AIRCR		*((volatile uint32_t*)0xE000ED0C)

#define MNVIC_GROUP4_SUB_0		0x05FA0300
#define MNVIC_GROUP3_SUB_1		0x05FA0400
#define MNVIC_GROUP2_SUB_2		0x05FA0500
#define MNVIC_GROUP1_SUB_3		0x05FA0600
#define MNVIC_GROUP0_SUB_4		0x05FA0700


/*=====================================================================================
 *              Section: Macro Function Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: Data Type Declarations
 =====================================================================================*/
//typedef struct
//{
//	uint32_t NVIC_ISER0;
//	uint32_t NVIC_ISER1;
//	uint32_t NVIC_ISER2;
//	uint32_t Reserved_1;
//	uint32_t Reserved_2;
//	uint32_t NVIC_ICER0;
//	uint32_t NVIC_ICER1;
//	uint32_t NVIC_ICER2;
//	uint32_t Reserved_1;
//	uint32_t Reserved_2;
//
//}NVIC_ref_def_t;

/*=====================================================================================
 *              Section: variables Declarations
 =====================================================================================*/

/*=====================================================================================
 *              Section: Function Declarations
 =====================================================================================*/



#endif
