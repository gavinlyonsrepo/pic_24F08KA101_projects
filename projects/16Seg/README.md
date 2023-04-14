
Overview
--------------------------------------------
* Name: SixteenSegDisplay
* Description: 

A library to display data on a 16 segment LED module.
It requires 3 Daisy chained shift registers/
Library is also designed to work with both common anode and common cathode module.
Library includes ASCII font and also supports Hexadecimal, Decimal point, string support.
It also provides a function for manually setting segments to any user defined pattern. 

* Author: Gavin Lyons.
* Complier: xc16 v1.41 compiler
* PIC: PIC24F08KA101
* IDE:  MPLAB X v5.30
* URL: https://github.com/gavinlyonsrepo/pic_24F08KA101_projects
* Note: This is a fork of a subsection of a Arduino library I wrote. "FourteenSegDisplay" 
It can be found in Arduino librarymanger or at [link](https://github.com/gavinlyonsrepo/FourteenSegDisplay).


Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)
  * [Connections](#connections)
  * [Files](#files)
  * [Functions](#functions)
  
Features
----------------------

A sixteen-segment display (SISD) is a type of display based on 16 segments 
that can be turned on or off to produce a graphic or Alphanumeric pattern. 
It is an extension of the more common seven-segment display, 
adding four diagonal and two vertical segments and splitting the three horizontal segments in half. 

![ 16seg1 ](https://github.com/gavinlyonsrepo/FourteenSegDisplay/blob/master/extra/image/16seg1.jpg)

16, 14 and 7 displays segments layout.

![ layout ](https://github.com/gavinlyonsrepo/FourteenSegDisplay/blob/master/extra/image/14seg2.png)

When displaying a large number of digts 4-8,Run at a "fast" clock freq (8mhz plus) 
to avoid flickering in the display and/or adjust shift delay parameter
in header file. In included config runs at 8Mhz internal.

This design requires 3 shift registers. 2 shift registers move data word to display
and third to controls digits. The last bit of third register controls decimal point.
As a result this limits maximum display size to seven digits but
If user does not want decimal point support this can be disabled by setting a parameter.
and user can use all 8. 
This model supports a maximum of 7-8 digits (eg for eight digits (D8D7D65D4D3D2D1). 
For purposes of the schematic and software D1
is the Least significant or right most Digit.  LSB RHS.
This library was tested on a single digit PSC05-11SURKWA common cathode. This table can be expanded to 7-8
digits.

Connections
-----------------------

| PIC , SW | IC 1 | IC 2 | IC 3 | PSC05-11SURKWA | 
| ---  | --- | --- | --- | --- | 
| RA2 , SCLK | SCLK  | SCLK | SCLK |  |
| RA1 , RCLK | RCLK  | RCLK | RCLK |  |
| RA0 , SER | SER  |  |   |   |
|    | QH'  | SER  |  |   |
|    |   |  QH' | SER |   |
|   | QA |    |     | a 1 |
|   | QB |    |     | b 18 |
|   | QC |    |     | c 16 |
|   | QD |    |     | d 13 |
|   | QE |    |     | e 10 |
|   | QF |    |     | f 9 |
|   | QG |    |     | g 8 |
|   | QH |    |     | h 4 |
|   |    | QA |     | k 3 |
|   |    | QB |     | m 2 |
|   |    | QC |     | n 17 |
|   |    | QD |     | p 15 |
|   |    | QE |     | r 14 |
|   |    | QF |     | s 6 |
|   |    | QG |     | t 7 |
|   |    | QH |     | u 5 |
|   |    |    | QA  | Digit1 11 LSB RHS |
|   |    |    | QB-QG  | extra digits 6-7 as needed |
|   |    |    | QH  | Decimal point 12 optional |

![ layout ](https://github.com/gavinlyonsrepo/FourteenSegDisplay/blob/master/extra/image/16seg.png)


Files
----------------------

| Test file | Font file | Header file | code file |
| --- | --- | --- |  --- | 
|  main.c | SixteenSegDisplayFont.h | SixteenSegDisplay.h | SixteenSegDisplay.c |

Functions
-------------------------------------

The commented functions can be found in library header files
See these file for more details on functions.

The main.c file contain a set of tests demonstrating public library functions.

1. void SixteenSegDisplay(bool common, bool nodecpoint);
2. void displayASCII(uint8_t ascii, uint8_t digits , bool dotOn);
3. void displayHex(uint8_t hex, uint8_t digits ;
4. void displaySeg(uint16_t value, uint8_t digits);
5. void displayString(const char* str, uint8_t startPos); 







