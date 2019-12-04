
/*
* Project Name: blink
* File: main.c 
* Description: blink an LED on RA4
* Author: Gavin Lyons.
* Complier: XC16 v1.40 c gcc compiler
* PIC: PIC24F08KA101
* IDE:  MPLAB X v5.25
* Development board: n/a
* Created December 2019
* Description: See URL for full details.
* URL: https://github.com/gavinlyonsrepo/pic_PIC24F08KA101_projects
*/

/*  Section: Included Files  */
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/mcc.h"
#define FOSC 4000000UL //for delay 
#define FCY     (FOSC/2) //for delay 
#include <libpic30.h> //for delay 

/*    Main application   */
int main(void)
{

    SYSTEM_Initialize();

    while (1)
    {
        LED_RA4_Toggle();
        __delay_ms(2000);
    }

    return 1;
}
/*           End of File    */

