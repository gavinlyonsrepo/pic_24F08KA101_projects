/*
* Project Name: SixteenSegDisplay
* File: SixteenSegDisplay.c
* Description: Source  file for SixteenSegDisplay  library
* Author: Gavin Lyons.
* Created: Jan 2020
* Fork of part of  Arduino library SixteenSegDisplay
* URL: https://github.com/gavinlyonsrepo/pic_16F18446_projects
*/

#include "mcc_generated_files/mcc.h"
#include "SixteenSegDisplay.h"
#include "SixteenSegDisplayFont.h"

#define FOSC 8000000UL //for delay 
#define FCY     (FOSC/2) //for delay 
#include <libpic30.h> //for delay 

bool _commoncathode;
bool _nodecimalpoint;
    
void SixteenSegDisplay(bool common, bool nodecpoint) 
{
   SER_SetDigitalOutput();
   SCLK_SetDigitalOutput();
   RCLK_SetDigitalOutput();
   _commoncathode = common;
   _nodecimalpoint = nodecpoint;
}

void displaySeg(uint16_t value, uint8_t digits, bool dotOn) 
{ 
    if (_nodecimalpoint == false) // Are we using dots (dec point)
     {
          if (dotOn == true) // is dot set on for this digit, apply mask
          {
             digits = (digits + DOT_MASK_DEC);
          } 
     }
  
  if (_commoncathode == false) 
   {
     value = (value ^ COMMON_ANODE_MASK); // If common anode flip all bits.
     digits = (digits ^ LOWER_BYTE_MASK); 
   }
   

  uint8_t  upper , lower = 0;
  lower =  value & LOWER_BYTE_MASK;  // select lower byte
  upper = (value >> 8) & LOWER_BYTE_MASK; //select upper 
  
  RCLK_SetLow();
  DataDisplay(digits); //digit + dot control
  DataDisplay(upper);
  DataDisplay(lower);
  RCLK_SetHigh();
}

void displayASCII(uint8_t ascii, uint8_t digits, bool dotOn) {
  displaySeg(SixteenSeg[ascii - ASCII_OFFSET], digits, dotOn);
}

void displayHex(uint8_t hex, uint8_t digits) 
{
    uint8_t hexchar = 0;
    if ((hex >= 0) && (hex <= 9))
    {
        displaySeg(SixteenSeg[hex + HEX_OFFSET], digits, false);
        // 16 is offset in reduced ASCII table for 0 
    }else if ((hex >= 10) && (hex <=15))
    {
        // Calculate offset in reduced ASCII table for ABCDEF
        switch(hex) 
        {
         case 10: hexchar = 'A'; break;
         case 11: hexchar = 'B'; break;
         case 12: hexchar = 'C'; break;
         case 13: hexchar = 'D'; break;
         case 14: hexchar = 'E'; break;
         case 15: hexchar = 'F'; break;
        }
        displaySeg(SixteenSeg[hexchar - ASCII_OFFSET], digits, false);
    }
    
}

void displayString(const char* str, uint8_t startPos)
{
   char c;
   while ((c = (*str++))) {
        if (*str == '.') {
            displayASCII(c, startPos, true);
            str++;
        }  else {
            displayASCII(c, startPos, false);
        }
          startPos = (startPos>>1); //Bitshifting by one to right /2 to change position of bit set position
   }
}

/* DataDisplay:
 * This function will send the data to serial line 74HC9595
 */
void DataDisplay(unsigned int data){
    uint8_t i;
    bool bitset;
    
    for (i=0 ; i<8 ; i++){
       // bit shift and bit mask data. MSB
        //SER_SetDigitalOutput()
       //SER_SetHigh() = (data >>(7-i)) & 0x01;
       bitset = (data >>(7-i)) & 0x01;
       if (bitset == true)
           SER_SetHigh();
       else
           SER_SetLow();
        sclock(); //enable data storage clock
    }
  
}

/* sclock:
 * This function clock will enable the storage Clock to 74HC595
 */
void sclock(void){
    SCLK_SetHigh();
    __delay_us(SHIFT_DELAY);
    SCLK_SetLow();
    __delay_us(SHIFT_DELAY);
}