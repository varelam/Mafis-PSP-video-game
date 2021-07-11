#include "06_tutorial2.hpp"

void State06(player &myPlayer)
{
    pspDebugScreenClear();
    pspDebugScreenPrintf("A Mafalda esta um pouquinho v drunk e precisa de atencao\n");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("E que tal um pouquinho de swipe no Tinder para passar o tempo?\n");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();
    PressX();

    int scaleii = 1;
    int xii = SCREEN_WIDTH/2 + 50;
    int yii = SCREEN_HEIGHT/2 + 80;
    // Set player properties for this level
    myPlayer.setPos(xii,yii,scaleii);

    pspDebugScreenClear();
    pspDebugScreenPrintf("Vamos abrir a app e comecar a jogar\n");
    graph::swapBuffers();
    graph::clearKeep(20, WHITE);
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("E muito facil, so tens de dar swipe com as setas\n");
    pspDebugScreenPrintf("aos meninos que aparecem e procurar um Manel\n");
    graph::swapBuffers();
    graph::clearKeep(20, WHITE);
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("Se tu deres swipe right a certo tipo de meninos \n");
    pspDebugScreenPrintf("o algortimo vai-te empurrar para esse tipo de meninos\n");
    graph::swapBuffers();
    graph::clearKeep(20, WHITE);
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("Mas se deres swipe a outro tipo de meninos \n");
    pspDebugScreenPrintf("o algoritmo vai-te mostrar meninos meh\n");
    graph::swapBuffers();
    graph::clearKeep(20, WHITE);
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("Quando conseguires alinhar o algoritmo \n");
    pspDebugScreenPrintf("para mostrar meninos Mafalda ganhas o jogo!\n");
    graph::swapBuffers();
    graph::clearKeep(20, WHITE);
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("Mas se alinhares o algoritmo para meninos coco\n");
    pspDebugScreenPrintf("vais ficar presa na dark zone do Tinder e perdes!\n");
    graph::swapBuffers();
    graph::clearKeep(20, WHITE);
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("Vamos comecar?\n");
    graph::swapBuffers();
    graph::clearKeep(20, WHITE);
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();
    PressX();


    // int bodyColors[6] = {15,3,2,3,10,0};
}