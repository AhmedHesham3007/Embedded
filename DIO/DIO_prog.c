/***************************************************************************************/
/***************************************************************************************/
/*  Layer           : MCAL                                                             */
/*                                                                                     */
/*  Component       : DIO                                                              */
/*                                                                                     */
/*  Description     : DIO Module Program                                               */
/*                                                                                     */
/*  File            : DIO_prog.c                                                       */
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
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"


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
void MDIO_voidSetPinDirection(u8 Copy_u8PortId , u8 Copy_u8PinId , u8 Copy_u8Mode)
{
    switch(Copy_u8PortId)
    {
        case PORTA :
            if (Copy_u8PinId <= 7) /* Check if the pin in the CRL */
            {
                DIO_A_CRL &= ((0b0000) << (Copy_u8PinId * 4));   /* Clear the mode bits to write the new mode */
                DIO_A_CRL |= ((Copy_u8Mode) << (Copy_u8PinId * 4)); /* Write the new mode to the set the pin mode */
            }
            else if (7 < Copy_u8PinId <= 15) /* Check if the pin in th CRH */
            {
                Copy_u8PinId = Copy_u8PinId - 8 ;
                DIO_A_CRH &= ((0b0000) << (Copy_u8PinId * 4));   /* Clear the mode bits to write the new mode */
                DIO_A_CRH |= ((Copy_u8Mode) << (Copy_u8PinId * 4)); /* Write the new mode to the set the pin mode */
            }
            break;
        case PORTB :
            if (Copy_u8PinId <= 7) /* Check if the pin in the CRL */
            {
                DIO_B_CRL &= ((0b0000) << (Copy_u8PinId * 4));   /* Clear the mode bits to write the new mode */
                DIO_B_CRL |= ((Copy_u8Mode) << (Copy_u8PinId * 4)); /* Write the new mode to the set the pin mode */
            }
            else if (7 < Copy_u8PinId <= 15) /* Check if the pin in th CRH */
            {
                Copy_u8PinId = Copy_u8PinId - 8 ;
                DIO_B_CRH &= ((0b0000) << (Copy_u8PinId * 4));   /* Clear the mode bits to write the new mode */
                DIO_B_CRH |= ((Copy_u8Mode) << (Copy_u8PinId * 4)); /* Write the new mode to the set the pin mode */
            } 
            break;
        case PORTC :
            if (Copy_u8PinId <= 7) /* Check if the pin in the CRL */
            {
                DIO_C_CRL &= ((0b0000) << (Copy_u8PinId * 4));   /* Clear the mode bits to write the new mode */
                DIO_C_CRL |= ((Copy_u8Mode) << (Copy_u8PinId * 4)); /* Write the new mode to the set the pin mode */
            }
            else if (7 < Copy_u8PinId <= 15) /* Check if the pin in th CRH */
            {
                Copy_u8PinId = Copy_u8PinId - 8 ;
                DIO_C_CRH &= ((0b0000) << (Copy_u8PinId * 4));   /* Clear the mode bits to write the new mode */
                DIO_C_CRH |= ((Copy_u8Mode) << (Copy_u8PinId * 4)); /* Write the new mode to the set the pin mode */
            } 
            break;
        default :  /* Error invaled pin selection */ break;
    }
}

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
void MDIO_voidSetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId ,u8 Copy_u8Value)
{
    switch(Copy_u8PortId)
    {
        if (Copy_u8Value == DIO_LOW)
            {
                case DIO_PORTA :    CLR_BIT(DIO_A_ODR , Copy_u8PinId);  break;
                case DIO_PORTB :    CLR_BIT(DIO_B_ODR , Copy_u8PinId);  break;
                case DIO_PORTC :    CLR_BIT(DIO_C_ODR , Copy_u8PinId);  break;
                default        :    /* Error invalid pin selection */   break;
            } 
        else if (Copy_u8Value == DIO_HIGH)
        {
            case DIO_PORTA :    SET_BIT(DIO_A_ODR , Copy_u8PinId);  break;
            case DIO_PORTB :    SET_BIT(DIO_B_ODR , Copy_u8PinId);  break;
            case DIO_PORTC :    SET_BIT(DIO_C_ODR , Copy_u8PinId);  break;
            default        :    /* Error invalid pin selection */   break;
        }
    }
}

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
u8 MDIO_u8GetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId)
{
    u8 Local_u8ReturnValue = 0 ;
    switch(Copy_u8PortId)
    {
        case DIO_PORTA :    Local_u8ReturnValue = GET_BIT(DIO_A_IDR , Copy_u8PinId);  break;
        case DIO_PORTB :    Local_u8ReturnValue = GET_BIT(DIO_A_IDR , Copy_u8PinId);  break;
        case DIO_PORTC :    Local_u8ReturnValue = GET_BIT(DIO_A_IDR , Copy_u8PinId);  break;
        default        :    /* Error invalid pin selection */   break;  
    }
    return Local_u8ReturnValue;
}