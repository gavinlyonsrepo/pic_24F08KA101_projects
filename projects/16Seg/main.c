/*
* Project Name: SixteenSegDisplay
* File: main.c
* Description: test  file for SixteenSegDisplay  library
* Author: Gavin Lyons.
* Created: August 2019
* Fork of part of Arduino library FourteenSegDisplay
* URL: https://github.com/gavinlyonsrepo/pic_16F18446_projects
*/


#include "mcc_generated_files/system.h"
#include "stdbool.h"
#include "SixteenSegDisplay.h"

//testnumber defines which test to run 
uint8_t mytestnumber = 1; //1= Hex 2= ASCII, 3 = ASCIIdot,  4 = segment, 5 & 6 = Stings(model 2 only)
  
#define initdelay 500  //optional

void myTEST(void);

/* Main application */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    SixteenSegDisplay(true, true);
    while (1)
    {
        myTEST();
    }

    return 1;
}

void myTEST()
{
    //**** Display String TEST ****
    if( mytestnumber == 5 )
    {
    displayString("AB", 0x02); // print AB "     AB"
    return;
    }
    if( mytestnumber == 6 ) //Showing decimal point use
    {
    displayString("A.B", 0x02); // print A.B "     A.B"
    return;
    }

    //  **** Display digit one ****
    switch(mytestnumber)
    {
    case 1:
        displayHex(0x3, 0x01);   // test 1 Hex
    break;
    case 2:
        displayASCII('B', 0x01,false); // test 2 ASCII
    break;
    case 3:
       displayASCII('B', 0x01, true);  //test 3 ASCII with dot
    break;
    case 4:
        displaySeg(0x4000, 0x01, false);  // test 4 Segments manual, u segs
    break;
    } 
    
    //  **** Display digit two ****  
    switch(mytestnumber)
    {
    case 1:
        displayHex(0xF, 0x02);   // test 1 Hex
    break;
    case 2:
        displayASCII('A', 0x02, false); // test 2 ASCII
    break;
    case 3:
        displayASCII('A', 0x02, true);  //test 3 ASCII with dot
    break;
    case 4:
        displaySeg(0x4400, 0x02,false);  // test 4 Segments manual, u-p segs
    break;
    } 
}

/*   EOF           */

