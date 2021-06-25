#include "04_levelFDUP.hpp"

void State04(player &myPlayer)
{
    pspDebugScreenClear();
    pspDebugScreenPrintf("Nivel da FDUP!\n");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw(SCREEN_WIDTH/2, SCREEN_HEIGHT/2 + 80, 1);
    graph::swapBuffers();


    sleep(3);
}