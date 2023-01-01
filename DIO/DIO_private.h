/***************************************************************************************/
/***************************************************************************************/
/*  Layer           : MCAL                                                             */
/*                                                                                     */
/*  Component       : DIO                                                              */
/*                                                                                     */
/*  Description     : DIO Module Private                                               */
/*                                                                                     */
/*  File            : DIO_private.h                                                    */
/*                                                                                     */
/*  Scope           : Private                                                          */
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
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H



/* Defining PORT A registers */
#define DIO_A_CRL       *((u32*)0x4001 0800)
#define DIO_A_CRH       *((u32*)0x4001 0804)
#define DIO_A_IDR       *((u32*)0x4001 0808)
#define DIO_A_ODR       *((u32*)0x4001 080C)
#define DIO_A_BSRR      *((u32*)0x4001 0810)
#define DIO_A_BRR       *((u32*)0x4001 0814)
#define DIO_A_LCKR      *((u32*)0x4001 0818)

/* Defining PORT B registers */
#define DIO_B_CRL       *((u32*)0x4001 0C00)
#define DIO_B_CRH       *((u32*)0x4001 0C04)
#define DIO_B_IDR       *((u32*)0x4001 0C08)
#define DIO_B_ODR       *((u32*)0x4001 0C0C)
#define DIO_B_BSRR      *((u32*)0x4001 0C10)
#define DIO_B_BRR       *((u32*)0x4001 0C14)
#define DIO_B_LCKR      *((u32*)0x4001 0C18)

/* Defining PORT C registers */
#define DIO_C_CRL       *((u32*)0x4001 1000)
#define DIO_C_CRH       *((u32*)0x4001 1004)
#define DIO_C_IDR       *((u32*)0x4001 1008)
#define DIO_C_ODR       *((u32*)0x4001 100C)
#define DIO_C_BSRR      *((u32*)0x4001 1010)
#define DIO_C_BRR       *((u32*)0x4001 1014)
#define DIO_C_LCKR      *((u32*)0x4001 1018)





#endif