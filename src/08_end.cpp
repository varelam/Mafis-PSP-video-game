#include "08_end.hpp"

void State08(player &myPlayer)
{
    pspDebugScreenClear();
    graph::swapBuffers();
    graph::clearKeep(20, WHITE);
    pspDebugScreenPrintf("O que e isto? Recebemos um super like!\n");
    myPlayer.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();

    // Flash
    // Draw swipe result
    graph::swapBuffers();
    graph::clear(BLUE);
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();

    // Create not myself
    int scaleii = 1;
    int xii = SCREEN_WIDTH/2 + 50;
    int yii = SCREEN_HEIGHT/2 + 80; 
    player notManel(xii,yii,scaleii,15,3,0,0,15,7);
    int bodyColors[6] = {15,3,0,0,15,7};
    notManel.updateColor(bodyColors);

    pspDebugScreenClear();
    pspDebugScreenPrintf("MANEL:\n\n\n\n");

    pspDebugScreenPrintf("IDADE:\t25\n\n");

    pspDebugScreenPrintf("SIGNO SOLAR:\n");
    pspDebugScreenPrintf("Peixs-CARNEIRO!\n\n");

    pspDebugScreenPrintf("INTERESSES:\n");
    pspDebugScreenPrintf("Musica e coisas techy\n");
    pspDebugScreenPrintf("Coffees no BOP\n");
    pspDebugScreenPrintf("Passear nas virtudes\n");
    pspDebugScreenPrintf("Debates sobre coisas parvas\n\n");

    pspDebugScreenPrintf("SPOTIFY:\n");
    pspDebugScreenPrintf("Aaron Parks\n");
    pspDebugScreenPrintf("Kurt Rosenwinkel\n");
    pspDebugScreenPrintf("Capitao Fausto\n");
    pspDebugScreenPrintf("King Gizzard Lizzard Wizzard\n\n");

    pspDebugScreenPrintf("BIO:\n");
    pspDebugScreenPrintf("A procura de uma Mafalda\n\n");
    graph::swapBuffers();
    graph::drawRect(SCREEN_WIDTH/2,0, SCREEN_WIDTH/2,SCREEN_HEIGHT, BLUE_LIGHT);
    notManel.drawBoy();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();

    int swipeValue = swipe();
    graph::swapBuffers();
    pspDebugScreenClear();
    if(swipeValue<0)
    {
        graph::clear(RED_LIGHT);
    }
    else if (swipeValue>10)
    {
        graph::clear(BLUE);
    }
    else
    {
        graph::clear(GREEN_LIGHT);
    }
    myPlayer.setPos(xii+30,yii,scaleii);
    notManel.drawBoy();
    myPlayer.draw();
    graph::swapBuffers();
    sceDisplayWaitVblankStart();
    pspDelay();

    if(swipeValue<0)
    {
        pspDebugScreenPrintf("Foste rude com esse swipe left :o\n\n");
    }
    else if (swipeValue>10)
    {
        pspDebugScreenPrintf("ITS A MATCH!\n\n");
        pspDebugScreenPrintf("Awwww, sabes sempre que eu te dou sempre um super like!\n\n");
    }
    else
    {
        pspDebugScreenPrintf("ITS A MATCH!\n\n");
    }
    sleep(3);

    pspDebugScreenPrintf("Espero que tenhas gostado do jogo!\nEu gostei muito de o fazer para ti!\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Desejo-te um feliz aniversario ao som de 22 da Taylor Swift!\n\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Eu tentei muito colocar som no jogo mas \nesta fora das minhas competencias\n\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Como chegaste ao fim agora podes ter as tuas prendas!\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Pergunta ao Manel mais proximo pelas prendas ou abre-as\n");
    pspDebugScreenPrintf("caso se encontrem na tua posse.\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Bem, e tudo! Gosto muito de tiiiiiii\n\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Ate jaaaaaaaaaaa   \(\^\^ \))\n\n");
    sleep(3);
}