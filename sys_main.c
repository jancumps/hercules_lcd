/** @file sys_main.c 
*   @brief Application main file
*   @date 16.Feb.2015
*   @version 04.03.00
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2015 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
#include "gio.h"
#include "etpwm.h"
#include "44780.h"


#include <stdio.h> // temporary for debuggig printf


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
	uint32_t uWaitCounter = 0;
	uint32_t uBannerLoop = 0;
	uint32_t uBackLoop = 0;
	const char sBanner[] =  "   The JENS-MICHAEL GROSS-Day - March, 30th - Thanks for your contributions to TI-E2E!    ...   The JENS-MICHAEL GROSS-Day - ";
	char sBuff[17] = "";


	gioInit();

	gioPin_t rs = {gioPORTA,0};
	gioPin_t enable = {gioPORTA,1};
	gioPin_t d0 = {gioPORTA,2};
	gioPin_t d1 = {gioPORTA,5};
	gioPin_t d2 = {gioPORTA,6};
	gioPin_t d3 = {gioPORTA,7};
	lcdInit(&rs, &enable, &d0, &d1, &d2, &d3);
	lcdBegin(16,2, 0);

     while(1) {
    	 lcdSetCursor(0,0);            // move to the beginning of the first line
    	 memcpy(sBuff, &(sBanner[uBannerLoop]), 16 );
         lcdPrint( sBuff);
    	 lcdSetCursor(0,1);            // move to the beginning of the second line
    	 for (uBackLoop = 0; uBackLoop < 16; uBackLoop++) {
    		 sBuff[15-uBackLoop] = sBanner[uBannerLoop+16+uBackLoop];

    	 }

//    	 memcpy(sBuff, &(sBanner[uBannerLoop + 16]), 16 );
         lcdPrint( sBuff);
         uBannerLoop++;
         if (uBannerLoop  == 93) {
        	 uBannerLoop = 0;
         }
    	 for(uWaitCounter=0; uWaitCounter < 7000000; uWaitCounter++); //wait some time.
     }
/* USER CODE END */
}

/* USER CODE BEGIN (4) */
/* USER CODE END */
