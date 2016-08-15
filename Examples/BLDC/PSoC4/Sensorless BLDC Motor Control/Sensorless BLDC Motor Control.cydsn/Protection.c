/*******************************************************************************
*
* Filename:             Protection.c
* Owner :               Bob Hu (bobh@cypress.com)
*
* Version:              V1.0 
* Description:          Sensorless BLDC Motor Control
*                       This file enables system to detection over voltage, over 
*                       current and other failure events.
*                       
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
#include <project.h>
#include "BLDCController.h"
#include "protection.h"

/*******************************************************************************
* Function Name: VoltageCheck
********************************************************************************
* Summary:
* Check DC bus voltage periodically for over voltage or under voltage event 
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
*******************************************************************************/
void VoltageCheck(void)
{
    uint16 adcResult;	
    static uint16 ovCheckCounter = 0;
    static uint16 uvCheckCounter = 0;
    
	adcResult = ADC_GetResult16(DC_BUS_CHAN);
    /* check over voltage */
    if(adcResult > OV_THRESHOLD)
    {
        ovCheckCounter++;
    }
    else
    {
        if(ovCheckCounter > 0)
            ovCheckCounter--;
    }

    if(ovCheckCounter > PROTECTION_DEBOUNDCE_CNT)
    {
        ovCheckCounter = 0;
        runState = ERRORSTOP;
        BLDC_Control.errorCode = OV_ERROR;
    }
    
    /* check under voltage */
    if(adcResult < UV_THRESHOLD)
    {
        uvCheckCounter++;
    }
    else
    {
        if(uvCheckCounter > 0)
            uvCheckCounter--;
    }

    if(uvCheckCounter > PROTECTION_DEBOUNDCE_CNT)
    {
        uvCheckCounter = 0;
        runState = ERRORSTOP;
        BLDC_Control.errorCode = UV_ERROR;
    }
}


/* [] END OF FILE */
