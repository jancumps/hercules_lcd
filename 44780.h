/*
 * 44780.h
 *
 *  Created on: Mar 23, 2014
 *      Author: jan cumps
 *      100% intellectual property the Arduino LiquidCrystal library
 */

#ifndef __44780_H_
#define __44780_H_

#include "hal_stdtypes.h"
#include "gio.h"

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00




typedef struct {
		gioPORT_t *port; // the port the signal line is on
		uint32 bit;		 // the signal line
} lcdPin_t;

void lcdInit(const lcdPin_t *rs, const lcdPin_t *enable, const lcdPin_t *d0,
		const lcdPin_t *d1, const lcdPin_t *d2,
		const lcdPin_t *d3);
void lcdBegin(uint32 cols, uint32 lines, uint32 dotsize);
void lcdSetCursor(uint32 col, uint32 row);
void lcdPrint(const char *str);

#endif /* 44780_H_ */
