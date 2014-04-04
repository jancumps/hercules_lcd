/** @file sys_main.c 
*   @brief Application main file
*   @date 24.Feb.2014
*   @version 03.08.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* (c) Texas Instruments 2009-2014, All rights reserved. */

/* USER CODE BEGIN (0) */
#include "gio.h"
#include "het.h"
#include "44780.h"

#include "stdio.h" // temporary for debuggig printf


/* USER CODE END */

/* Include Files */

#include "sys_common.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */
/* USER CODE END */

void main(void)
{
/* USER CODE BEGIN (3) */
	gioInit();
//	hetInit();

	lcdPin_t rs = {hetPORT1,12};
	lcdPin_t enable = {hetPORT1,14};
	lcdPin_t d0 = {hetPORT1,2};
	lcdPin_t d1 = {hetPORT1,4};
	lcdPin_t d2 = {hetPORT1,6};
	lcdPin_t d3 = {hetPORT1,10};
	lcdInit(&rs, &enable, &d0, &d1, &d2, &d3);
	lcdBegin(16,2, 0);

	 lcdSetCursor(0,0);            // move to the beginning of the second line
     lcdPrint("Hello, world!");

     uint32 u = 0;
     char buf[10];
     printf("\n");

//     lcdTestBed();
     while(1) {
    	 lcdSetCursor(6,1);            // move cursor to second line 1 and 6 spaces over
    	 sprintf(buf, "%u%", u);
    	 lcdPrint(buf);
    	 u++;
     }
/* USER CODE END */
}

/* USER CODE BEGIN (4) */
/* USER CODE END */
