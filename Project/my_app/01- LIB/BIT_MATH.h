/****************************************************/
/* Author		: Ali Morsy 						*/
/* Date			: 21 JUL 2022 						*/	
/* Version		: V01								*/
/****************************************************/

#ifndef		BIT_MATH_H
#define 	BIT_MATH_H

#define BIT_MASK    (uint32_t)1

#define HW_REG32(_X)                      (*((volatile uint32_t*)(_X)))

#define SET_BIT(VAR,BIT)		(VAR |=	 (BIT_MASK << BIT))
#define CLR_BIT(VAR,BIT)		(VAR &=	~(BIT_MASK << BIT))
#define TOG_BIT(VAR,BIT)		(VAR ^=	 (BIT_MASK << BIT))
#define GET_BIT(VAR,BIT)		((VAR >> BIT) & BIT_MASK)

#endif	//BIT_MATH_H
