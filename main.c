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
#define INTERVAL 20

typedef enum Color {
  _ = 0b000,
  R = 0b001, 
  Y = 0b010, 
  G = 0b100
} Color;

uint8 counter = 0;
int state = 0;
CYBIT algorithm = 0;


inline void runAlgorithm1();
inline void runAlgorithm2();

CY_ISR(timer_isr_interrupt)
{
    if (counter >= INTERVAL) 
    {
        counter = 0;
    } 
    counter++;
    Timer_Counter_ClearInterrupt(Timer_Counter_INTR_MASK_TC);
}

CY_ISR(button_isr_interrupt)
{
    state += 1;
    Button_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    Timer_Counter_Start();
    timer_isr_StartEx(timer_isr_interrupt);
    button_isr_StartEx(button_isr_interrupt);

    for(;;)
    {            
        if (state % 2 == 1)
        {
            runAlgorithm1();
        }
        else if (state % 2 == 0)
        {
            runAlgorithm2();
        }
    }
}

inline void runAlgorithm1()
{
    if (counter < 8)
    {
        Control_Reg_Write(R);
    }
    else if (counter < 10)
    {
        Control_Reg_Write(Y);
    }
    else if (counter < 14)
    {
        Control_Reg_Write(G);
    }
    else if (counter < 15)
    {
        Control_Reg_Write(_);
    }
    else if (counter < 16)
    {
        Control_Reg_Write(G);
    }
    else if (counter < 17)
    {
        Control_Reg_Write(_);
    }
    else if (counter < 18)
    {
        Control_Reg_Write(G);
    }
    else if (counter < 20)
    {
        Control_Reg_Write(Y);
    }
    else
    {
        Control_Reg_Write(_);
    }
}

inline void runAlgorithm2()
{
    if (counter < 4)
    {
        Control_Reg_Write(G);
    }
    else if (counter < 5)
    {
        Control_Reg_Write(_);
    }
    else if (counter < 6)
    {
        Control_Reg_Write(G);
    }
    else if (counter < 7)
    {
        Control_Reg_Write(_);
    }
    else if (counter < 8)
    {
        Control_Reg_Write(G);
    }
    else if (counter < 10)
    {
        Control_Reg_Write(Y);
    }
    else if (counter < 18)
    {
        Control_Reg_Write(R);
    }
    else if (counter < 20)
    {
        Control_Reg_Write(Y);
    }
    else
    {
        Control_Reg_Write(_);
    }
}
