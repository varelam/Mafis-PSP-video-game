#include "03_intro.hpp"

void State03(player * myPlayer_ptr)
{
    // Create a player
    player myPlayer = *myPlayer_ptr;
    int bodyIdx = 0;
    int bodyColors[6] = {15,3,2,3,10,0};
    myPlayer.updateColor(bodyColors);

    // Printf in Debug Sreen
    pspDebugScreenPrintf("Vamos comecar por personalizar o teu jogador!\n");
    pspDebugScreenPrintf("Usa as setas para escolher a cor, prime X para avancar!\n");
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2 + 80, 1);
    graph::swapBuffers();
    
    
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 5e8;

    while(bodyIdx<6)
    {
        // Read commands
        SceCtrlData ctrlData;

        bool b_exit = false;

        while(!b_exit)
        {
            // Read buttons
            sceCtrlReadBufferPositive(&ctrlData, 1);

            // Select cross
            if(ctrlData.Buttons & PSP_CTRL_CROSS) // Go further
            {
                bodyIdx++;
                b_exit = true;
            }
            else if(ctrlData.Buttons & PSP_CTRL_CIRCLE) // Go back
            {
                bodyIdx--;
                if(bodyIdx<0){bodyIdx=0;}
                b_exit = true;
            }
            else if(ctrlData.Buttons & PSP_CTRL_RIGHT) // Change color +
            {
                bodyColors[bodyIdx] = bodyColors[bodyIdx] + 1;
                if(bodyColors[bodyIdx]>NUM_COLORS-1){bodyColors[bodyIdx] = 0;}
                b_exit = true;
            }
            else if(ctrlData.Buttons & PSP_CTRL_LEFT) // Change color -
            {   
                bodyColors[bodyIdx] = bodyColors[bodyIdx] - 1;
                if(bodyColors[bodyIdx]<0){bodyColors[bodyIdx] = NUM_COLORS-1;}
                b_exit = true;
            }
            else
            {
                b_exit = false;
            }
        }
        
        myPlayer.updateColor(bodyColors);
        graph::swapBuffers();
        graph::clearKeep(20, BLUE_LIGHT);
        myPlayer.draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2 + 80, 1);
        graph::swapBuffers();
        
	    nanosleep(&delay, NULL);
    }

    pspDebugScreenClear();
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2 + 80, 1);
    graph::swapBuffers();
    pspDebugScreenPrintf("Estamos prontos para a nossa ventura!\n");

    sleep(3);
    sceDisplayWaitVblankStart();
    // Scaled down
    // myPlayer.draw(SCREEN_WIDTH - 150, SCREEN_HEIGHT - 80,4);
    // sleep(5);
    return;
}