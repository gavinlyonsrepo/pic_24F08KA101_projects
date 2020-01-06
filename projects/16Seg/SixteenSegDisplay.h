/*
* Project Name: FourteenSegDisplay
* File: SixteenSegDisplay.h
* Description: header file  for SixteenSegDisplay  library
* Author: Gavin Lyons.
* Created: jan 2019
* Fork of Arduino library SixteenSegDisplay
* URL: https://github.com/gavinlyonsrepo/pic_16F18446_projects
*/

#include "mcc_generated_files/system.h"

#ifndef SixteenSegDisplay_h
#define SixteenSegDisplay_h
    
#define SHIFT_DELAY 20   //shift delay in usecconds can be adjusted to avoid flickering 
#define ASCII_OFFSET 32 // ASCII table offset to jump over first missing 32 chars
#define HEX_OFFSET   16 // ASCII table offset to reach 0 position for Hexadecimal
#define DOT_MASK_DEC   0x80 //  Mask to switch on decimal point in digit byte. 
#define DOT_MASK_ANODE_DEC  0x7F //  Mask to switch on decimal point in digit byte for common anode 
#define COMMON_ANODE_MASK 0xFFFF // mask to be applied to value if user wants common anode. 
#define LOWER_BYTE_MASK 0X00FF //mask to be applied to mask off lower byte of a uint16_t var

//extern bool _commoncathode;
//extern bool _nodecimalpoint;

// Passed a boolean value called common
// common = true = Common Cathode(default)
// common = false = Common Anode
// NoDecimalPoint = false = use the decimal point , 7 digits max
// NoDecimalPoint = true = do not use decimal point , 8 digits max
void SixteenSegDisplay(bool common, bool nodecpoint);

// Send ASCII value to 16 segment display, passed ASCII value byte, 
// and digits position 0x40-0x20-0x10-0x08-0x04-0x02-0x01 D7-D1
//boolean to set byte
void displayASCII(uint8_t ascii, uint8_t digits, bool dotOn);

// Send HEX value to 16 segment display, passed a hex value  0-15 : 0x00 to 0x0F,  
// and digits position 0x40-0x20-0x10-0x08-0x04-0x02-0x01 D7-D1
void displayHex(uint8_t hex, uint8_t digits);

//  Send segment value to 16 segment display,
//  Passed value corresponding to segments  (u-t-s-r-p-n-m-k-h-g-f-e-d-c-b-a) Two bytes. 
//  and  digits position 0x40-0x20-0x10-0x08-0x04-0x02-0x01 D7-D1
//  Doton is for decimal point on or off, true on
void displaySeg(uint16_t value, uint8_t digits, bool dotOn);

// Passed a character string, 
// and starting position 0x40-0x20-0x10-0x08-0x04-0x02-0x01 D7-D1
// So to print AB as "AB" set start postion to 2.
void displayString(const char* str, uint8_t startPos);

//Used for timing internally in DataDisplay method
void sclock(void);

//Shift out a byte of data MSB
void DataDisplay(unsigned int data);


#endif
