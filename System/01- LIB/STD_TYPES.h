/****************************************************/
/* Author		: Ali Morsy 						*/
/* Date			: 20-8-2022 						*/
/* Version		: V02								*/
/* LOG			: V01 -> Initial creation			*/
/*				: Vo2 -> Add to signed Data Types	*/
/****************************************************/

#ifndef		STD_TYPES_H
#define 	STD_TYPES_H

/* Section: Data Type Declarations */
typedef unsigned char        uint8_t;
typedef unsigned short       uint16_t;
typedef unsigned long        uint32_t;
typedef unsigned long long   uint64_t;

typedef signed char          sint8_t;
typedef signed short         sint16_t;
typedef signed long          sint32_t;
typedef signed long long     sint64_t;

#define  NULL 				(void*)0

/* Section: Macro Declarations */
#define STD_HIGH            0X01
#define STD_LOW             0X00

#define STD_ON              0X01
#define STD_OFF             0X00

#define STD_ACTIVE          0X01
#define STD_IDLE            0X00

#define ZERO_INIT       0

typedef enum {OPERATION_ERROR = 0, OPERATION_SUCCESS = 1}Std_ReturnType;


#endif	// STD_TYPES_H

