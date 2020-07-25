
Overview
--------------------------------------------
* Name: UART PC to PIC basic Data link
* Description: An Example program to transfer data from the PIC to the PC via 
the UART and USB ports. 
* Author: Gavin Lyons.
* Complier: xc16 v1.41 compiler
* PIC: PIC24F08KA101
* IDE:  MPLAB X v5.30
* Copyright: (C) 2019 G Lyons This program is free software, see license.md for more detail.
* URL: https://github.com/gavinlyonsrepo/pic_24F08KA101_projectsons.


Table of contents
---------------------------

  * [Overview](#overview)
  * [Features](#features)


Features
----------------------

**Connections**

| PIC PIN | YP-05 FTDI | 
| ---  | --- | 
| RB2 UART 1 RX | TX |  
| RB7 UART 1 TX | RX | 
| RA0 ADC input | n/a |  
| RA4 STATUS LED | n/a  | 


**YP-05**

This code will work with many [FTDI](https://en.wikipedia.org/wiki/FTDI) serial and bluetooth modules the one used here is
the YP-05 which can be set for 5 or 3.3V. Set to 3.3V for this PIC.
This module is based on [FT232RL](https://www.sparkfun.com/datasheets/IC/FT232R_v104.pdf) chip. 
The Yp05 is connected to USB port of PC.

![ yp05 ](https://github.com/gavinlyonsrepo/pic_24F08KA101_projects/blob/master/images/3.jpg)



