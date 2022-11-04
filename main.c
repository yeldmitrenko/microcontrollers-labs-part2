/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    uint8 registerValue;
    LED_Write(0);
    
    for(;;)
    {
        registerValue = Input_Buttons_Read();
        if ((registerValue == 0b00110) || (registerValue == 0b01110) || (registerValue == 0b10101)
            || (registerValue == 0b00111) || (registerValue == 0b11100))
        {
            
            LED_Write(1);
        }
        else
        {
            LED_Write(0);
        }
    }
}

/* [] END OF FILE */
