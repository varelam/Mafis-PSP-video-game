#include "mafis.hpp"

void pspDelay()
{
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 3e8;
    nanosleep(&delay, NULL);
}

void PressX()
{
    SceCtrlData ctrlData;
    bool b_exit = false;
    
    while(!b_exit)
    {
        // Read buttons
        sceCtrlReadBufferPositive(&ctrlData, 1);

        // Select cross
        if(ctrlData.Buttons & PSP_CTRL_CROSS)
        {
            b_exit = true;
        }
    }
    pspDelay();
}

bool PressXorC()
{
    SceCtrlData ctrlData;
    bool b_exit = false;
    bool b_result = false;

    while(!b_exit)
    {
        // Read buttons
        sceCtrlReadBufferPositive(&ctrlData, 1);

        // Select cross
        if(ctrlData.Buttons & PSP_CTRL_CROSS)
        {
            b_exit = true;
            b_result = true;
        }
        else if(ctrlData.Buttons & PSP_CTRL_CIRCLE)
        {
            b_exit = true;
            b_result = false;
        }
    }
    pspDelay();
    return(b_result);
}

int swipe()
{
    SceCtrlData ctrlData;
    bool b_exit = false;
    int result = 0;

    while(!b_exit)
    {
        // Read buttons
        sceCtrlReadBufferPositive(&ctrlData, 1);

        // Select cross
        if(ctrlData.Buttons & PSP_CTRL_RIGHT)
        {
            b_exit = true;
            result = 5;
        }
        else if(ctrlData.Buttons & PSP_CTRL_LEFT)
        {
            b_exit = true;
            result = -1;
        }
        else if(ctrlData.Buttons & PSP_CTRL_UP)
        {
            b_exit = true;
            result = 20;
        }
        else if(ctrlData.Buttons & PSP_CTRL_DOWN)
        {
            b_exit = true;
            result = -5;
        }
        else if(ctrlData.Buttons & PSP_CTRL_CIRCLE)
        {
            b_exit = true;
            result = 0;
        }
    }
    pspDelay();
    return(result);
}
