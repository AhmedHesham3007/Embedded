/***************************************************************************************/
/***************************************************************************************/
/*  Layer           : MCAL                                                             */
/*                                                                                     */
/*  Component       : DIO                                                              */
/*                                                                                     */
/*  Description     : DIO Module Interface                                             */
/*                                                                                     */
/*  File            : DIO_int.h                                                        */
/*                                                                                     */
/*  Scope           : Public                                                           */
/*                                                                                     */
/*  Coding language : C                                                                */
/*                                                                                     */
/*                                                                                     */
/*  Target          : STM 32F103 ARM Cortex M3                                         */
/*                                                                                     */
/*  Author          : Ahmed Hesham                                                     */
/*  Version         : V1                                                               */
/*  Date            : 24 / 10 / 2022                                                   */
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
#ifndef DIO_INT_H
#define DIO_INT_H

/* Defining the High and Low */
#define DIO_LOW     0
#define DIO_HIGH    1

/* Defining the DIO Ports */
#define DIO_PORTA   0
#define DIO_PORTB   1
#define DIO_PORTC   2

/* Defining the 15 pins of DIO */
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7
#define DIO_PIN8   8
#define DIO_PIN9   9
#define DIO_PIN10  10
#define DIO_PIN11  11
#define DIO_PIN12  12
#define DIO_PIN13  13
#define DIO_PIN14  14
#define DIO_PIN15  15

/* DIO pin Output Modes with 10MHZ speed  */
#define DIO_OUTPUT_SPEED_10MHZ_PP         0b0001
#define DIO_OUTPUT_SPEED_10MHZ_OD         0b0101
#define DIO_OUTPUT_SPEED_10MHZ_AFPP       0b1001
#define DIO_OUTPUT_SPEED_10MHZ_AFOD       0b1101
/* DIO pin Output Modes with 2MHZ speed  */
#define DIO_OUTPUT_SPEED_2MHZ_PP          0b0010
#define DIO_OUTPUT_SPEED_2MHZ_OD          0b0110
#define DIO_OUTPUT_SPEED_2MHZ_AFPP        0b1010
#define DIO_OUTPUT_SPEED_2MHZ_AFOD        0b1110
/* DIO pin Output Modes with 50MHZ speed  */
#define DIO_OUTPUT_SPEED_50MHZ_PP         0b0011
#define DIO_OUTPUT_SPEED_50MHZ_OD         0b0111
#define DIO_OUTPUT_SPEED_50MHZ_AFPP       0b1011
#define DIO_OUTPUT_SPEED_50MHZ_AFOD       0b1111
/* DIO pin Input Mode */
#define DIO_INPUT_ANALOG                  0b0000
#define DIO_INPUT_FLOATING                0b0100
#define DIO_INPUT_PULL_UP_DOWN            0b1000


/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/* Function Parameter1 : Copy_u8PortId     (ID of the used port)                              */
/* Range               : PORTA , PORTB , PORTC                                                */
/* Function Parameter2 : Copy_u8PinId     (ID of the PIN)                                     */
/* Range               : PIN0 -> PIN15                                                        */
/* Function Parameter3 : Copy_u8Mode     (The mode of the pin)                                */
/* Range               : choose the mode of the pin)                                          */
/* Return              : Void                                                                 */
/* Functionality       : Set the direction of the DIO PIN (INPUT or OUTPUT) and its mode      */
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
void MDIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Mode);

/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/* Function Parameter1 : Copy_u8PortId     (ID of the used port)                              */
/* Range               : PORTA , PORTB , PORTC                                                */
/* Function Parameter2 : Copy_u8PinId     (ID of the PIN)                                     */
/* Range               : PIN0 -> PIN15                                                        */
/* Function Parameter3 : Copy_u8Value     (The Value of the pin)                              */
/* Range               : DIO_LOW   & DIO_HIGH                                                 */
/* Return              : Void                                                                 */
/* Functionality       : Set the Value of the DIO PIN (DIO_LOW or DIO_HIGH)                   */
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
void MDIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId ,u8 Copy_u8Value);

/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
/* Function Parameter1 : Copy_u8PortId     (ID of the used port)                              */
/* Range               : PORTA , PORTB , PORTC                                                */
/* Function Parameter2 : Copy_u8PinId     (ID of the PIN)                                     */
/* Range               : PIN0 -> PIN15                                                        */
/* Return              : u8                                                                   */
/* Functionality       : Get the Value of the DIO PIN                                         */
/**********************************************************************************************/
/**********************************************************************************************/
/**********************************************************************************************/
u8 MDIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId);


#endif