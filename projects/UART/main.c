/*
* File: main.c
* Description: UART PIC to PC link 
* Author: Gavin Lyons.
* Complier: xc16 1.41 compiler
* PIC: PIC24F08KA101
* IDE:  MPLAB X v5.30
* Created july 2020
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_24F08KA101_projectsts
*/


/* -------- libraries -------- */
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#define FOSC 4000000UL //for delay 
#define FCY     (FOSC/2) //for delay 
#include <libpic30.h> //for delay 

/* ----------- Defines -----------*/
#define STARTMES 0xAA 
#define MY_DELAY_TIME 2000
#define ADC_VOLT 129

/* -------- Function prototypes -------- */
void DisplayPotData(void);
void Setup(void);

/* --------------  Main --------------- */
int main(void)
{
    Setup();
    while (1)
    {
       __delay_ms(MY_DELAY_TIME);
       LED_RA4_Toggle();
       DisplayPotData();
    }

    return 1;
}
/* --------------  End of Main --------------- */


/* --------------  Function Space--------------- */

// Function to send ADC data to PC via UART 
void DisplayPotData(void)
{   
    uint16_t temperature= 0;
    uint16_t ADC_value= 0;
    uint8_t data_lower;
    uint8_t data_upper;
    
    ADC_value=ADC1_GetConversion(ADC_AN0);     
    temperature=(ADC_value*ADC_VOLT);

    data_lower = temperature & 0xff;
    data_upper = (temperature >> 8) & 0xff;
    UART1_Write(0x00);
    UART1_Write(data_upper);
    UART1_Write(data_lower);
    UART1_Write(0x00);
}
// Setup Function
void Setup(void)
{
    SYSTEM_Initialize();
    __delay_ms(MY_DELAY_TIME);
     UART1_Write(STARTMES);
}

/* End of File */

