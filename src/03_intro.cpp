#include "03_intro.hpp"

void State03(player &myPlayer)
{
    int bodyIdx = 0;
    int bodyColors[6] = {15,3,2,3,10,0};
    int scaleii = 1;
    int xii = SCREEN_WIDTH/2;
    int yii = SCREEN_HEIGHT/2 + 80;

    // Set player properties for this level
    myPlayer.setPos(xii,yii,scaleii);
    myPlayer.updateColor(bodyColors);

    // Printf in Debug Sreen
    pspDebugScreenPrintf("Vamos comecar por personalizar o teu jogador!\n");
    pspDebugScreenPrintf("Usa as setas para escolher a cor, prime X para avancar!");
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    

    return; ////////////////////////////////////////////////////////////// DEBUG



    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 3e8;

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
                pspDebugScreenPrintf(".");
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
        myPlayer.draw();
        graph::swapBuffers();
        
	    nanosleep(&delay, NULL);
    }

    pspDebugScreenClear();
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    pspDebugScreenPrintf("Estamos prontos para a nossa aventura!\n");
    sleep(2);
    pspDebugScreenPrintf("Tomei a liberdade de te criar um perfil no Tinder... \nPode dar mais jeito no futuro:\n");
    sleep(2);
    pspDebugScreenClear();
    sceDisplayWaitVblankStart();

    // Force clear
    graph::swapBuffers();
    graph::clear(BLUE_LIGHT);
    graph::swapBuffers();
    graph::clear(BLUE_LIGHT);
    graph::swapBuffers();


    delay.tv_nsec = 1e7;
    for (int i=0;i<50;i++) // Slide right for style
    {
        xii++;
        myPlayer.setPos(xii,yii,scaleii);
        graph::clear(BLUE_LIGHT);
        myPlayer.draw();
        graph::swapBuffers();
        nanosleep(&delay, NULL);
    }
    sleep(3);
    pspDebugScreenPrintf("O MEU PERFIL:\n\n\n\n");

    pspDebugScreenPrintf("IDADE:\t22\n\n");

    pspDebugScreenPrintf("SIGNO SOLAR:\n");
    pspDebugScreenPrintf("Caranguejo\n\n");

    pspDebugScreenPrintf("INTERESSES:\n");
    pspDebugScreenPrintf("Astrologia\n");
    pspDebugScreenPrintf("Meninos de Engenharia\n");
    pspDebugScreenPrintf("Magoar fachos\n");
    pspDebugScreenPrintf("Gatinhos\n\n");

    pspDebugScreenPrintf("SPOTIFY:\n");
    pspDebugScreenPrintf("Taylor Swift\n");
    pspDebugScreenPrintf("Olivia Rodrigo\n");
    pspDebugScreenPrintf("Capitao Fausto\n");
    pspDebugScreenPrintf("Luis Severo\n\n");

    pspDebugScreenPrintf("BIO:\n");
    pspDebugScreenPrintf("Lembram-se daquela \nvez em que...\n\n");
    graph::swapBuffers();
    graph::drawRect(SCREEN_WIDTH/2,0, SCREEN_WIDTH/2,SCREEN_HEIGHT, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();

    sleep(2);
    PressX();
    return;
}