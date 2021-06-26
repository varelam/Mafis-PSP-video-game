#include "04_levelFDUP.hpp"

void State04(player &myPlayer)
{
    pspDebugScreenClear();
    pspDebugScreenPrintf("Bem-vinda a maravilhosa Faculdade de Direito da\nUniversidade do Porto");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    // pspDelay();
    // PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("Aqui vais... ");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    // pspDelay();
    // PressX();
    
    // Force clear
    graph::swapBuffers();
    graph::clear(BLUE_LIGHT);
    graph::swapBuffers();
    graph::clear(BLUE_LIGHT);
    myPlayer.setPos(SCREEN_WIDTH/2,SCREEN_HEIGHT,4);
    myPlayer.draw();
    graph::swapBuffers();

    myPlayer.setGravity(2);

    while(myPlayer.moveAround() >= 0)
    {
        graph::clearKeep(20, BLUE_LIGHT); 
        myPlayer.draw();
        graph::swapBuffers();
    }
    
}