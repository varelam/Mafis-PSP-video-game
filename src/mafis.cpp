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

