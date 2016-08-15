/*******************************************************************************
*
* Filename:             userinterface.h
* Owner :               Rod Wang (rowa@cypress.com)
*
* Version:              V1.0 
* Description:          This is the head file for userinterface.c.
* -------------------------------------------------------------------------------
* ChangeList: 
*   V1.0                Initial version
* -------------------------------------------------------------------------------
* Known issues:         
*   V1.0                N/A
* -------------------------------------------------------------------------------
* Hardare Dependency:   
*   1. CY8CKIT-042(MCU board) + CY8CKIT-037(Driver Board)  
* -------------------------------------------------------------------------------
* Related documents:
*   N/A
* -------------------------------------------------------------------------------
* Code Tested with:     PSoC Creator  3.2 (3.2.0.724)
*                       ARM GCC 4.8.4;
*
********************************************************************************
* Copyright (2014), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is 
* protected by and subject to worldwide patent protection (United States and 
* foreign), United States copyright laws and international treaty provisions. 
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable 
* license to copy, use, modify, create derivative works of, and compile the 
* Cypress Source Code and derivative works for the sole purpose of creating 
* custom software in support of licensee product to be used only in conjunction 
* with a Cypress integrated circuit as specified in the applicable agreement. 
* Any reproduction, modification, translation, compilation, or representation of 
* this software except as specified above is prohibited without the express 
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. Use may be 
* limited by and subject to the applicable Cypress software license agreement. 
*******************************************************************************/

#ifndef _USER_INTERFACE_H_
#define _USER_INTERFACE_H_

/******************************************************************************
 * Header file including
 ******************************************************************************/ 
#include <cytypes.h>

/******************************************************************************
 * Macro declaration   
 ******************************************************************************/    
/* button status */
#define BUTTON_OFF                          ((uint8)(0x00))
#define BUTTON_ON                           ((uint8)(0x01))

/* button count */
#define BTN_COUNT                           ((uint8)(1))
    
/******************************************************************************
 * Structure/Enum type declaration   
 ******************************************************************************/ 
        
/******************************************************************************
 * Global variables declaration   
 ******************************************************************************/    
extern uint8 btnStatus[BTN_COUNT];  

extern uint8  stateSys;    
/******************************************************************************
 * Global function declaration   
 ******************************************************************************/  
extern void ButtonInit(void);
extern void ButtonProcess(void);
extern void ReadSpeedRef(void);
extern void UpdateStatusInit(void);
extern void UpdateStatusError(void);
extern void ClearStatusError(void);
extern void BCPPoll(void);
/******************************************************************************
 * End of declaration   
 ******************************************************************************/  



#endif  /* _USER_INTERFACE_H_ */
