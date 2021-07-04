#include "04_tutorial.hpp"

using namespace std;

void State04(player &myPlayer)
{
    pspDebugScreenClear();
    pspDebugScreenPrintf("Bem-vinda ao teu maravilhoso Verao com migos!\n");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("Aqui vais viver a tua melhor vida de estudante\n");
    pspDebugScreenPrintf("aka apanhar a puta com migos todos os santos dias\n");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();
    
    block miniWhiskyBottle(3); // Create mini Whisky
    miniWhiskyBottle.xi = SCREEN_WIDTH/2;
    miniWhiskyBottle.yi = SCREEN_HEIGHT/2+10;
    miniWhiskyBottle.scale = 4;
    miniWhiskyBottle.status = 1;

    block whiskyBottle(3); // Create whisky
    whiskyBottle.xi = 50;
    whiskyBottle.yi = 150;
    whiskyBottle.scale = 1;
    whiskyBottle.status = 1;

    block miniSuperBottle(1); // Create mini SuperBock
    miniSuperBottle.xi = SCREEN_WIDTH/2;
    miniSuperBottle.yi = SCREEN_HEIGHT/2;
    miniSuperBottle.scale = 4;
    miniSuperBottle.status = 1;

    block superBottle(1); // Create big SuperBock
    superBottle.xi = 50;
    superBottle.yi = 150;
    superBottle.scale = 1;
    superBottle.status = 1;

    block miniBagacoBottle(2); // Create mini bagaco
    miniBagacoBottle.xi = SCREEN_WIDTH/2+35;
    miniBagacoBottle.yi = SCREEN_HEIGHT/2+20;
    miniBagacoBottle.scale = 4;
    miniBagacoBottle.status = 1;

    block bagacoBottle(2); // Create bagaco
    bagacoBottle.xi = SCREEN_WIDTH - 70;
    bagacoBottle.yi = 200;
    bagacoBottle.scale = 1;
    bagacoBottle.status = 1;

    block miniWaterBottle(0); // Create mini water
    miniWaterBottle.xi = SCREEN_WIDTH/2-10;
    miniWaterBottle.yi = SCREEN_HEIGHT/2+20;
    miniWaterBottle.scale = 4;
    miniWaterBottle.status = 1;

    block waterBottle(0); // Create water Bottle
    waterBottle.xi = 50;
    waterBottle.yi = 180;
    waterBottle.scale = 1;
    waterBottle.status = 1;

    pspDebugScreenClear();
    pspDebugScreenPrintf("Para apanhares a puta nada melhor do que uns bons menus do 7,\n");
    pspDebugScreenPrintf("que espero nao ser preciso lembrar mas consistem de uma mini\n");
    pspDebugScreenPrintf("Super Bock e um bagaco:\n");
    graph::swapBuffers();
    graph::clearKeep(40, BLUE_LIGHT);
    myPlayer.draw();
    miniBagacoBottle.draw();
    miniSuperBottle.draw();
    superBottle.draw();
    bagacoBottle.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("Neste jogo se conseguires apanhar uma (1) mini e \n");
    pspDebugScreenPrintf("um (1) bagaco por esta ordem ganhas um (1) alcool!\n");
    pspDebugScreenPrintf("Quando conseguires apanhar dez (10) alcoois(?)\n");
    pspDebugScreenPrintf("apanhas a farda e passas de nivel!\n");
    graph::swapBuffers();
    graph::clearKeep(40, BLUE_LIGHT);
    myPlayer.draw();
    miniBagacoBottle.draw();
    miniSuperBottle.draw();
    superBottle.draw();
    bagacoBottle.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();


    pspDebugScreenClear();
    pspDebugScreenPrintf("Mas C U I D A D O !!!!\n");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("Os migos querem poupar dinheiro e comprar whisky barato...\n");
    pspDebugScreenPrintf("Se tu apanhares um whisky barato o teu figado vai\n");
    pspDebugScreenPrintf("sofrer um pouquinho e perdes um (-1) de vida!\n");
    graph::swapBuffers();
    graph::clearKeep(30, BLUE_LIGHT);
    myPlayer.draw();
    whiskyBottle.draw();
    miniWhiskyBottle.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();

    pspDebugScreenClear();
    pspDebugScreenPrintf("A boa noticia e que podes apanhar as garrafinhas\n");
    pspDebugScreenPrintf("de agua e assim recuperar mais um (1) de vida!\n");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    waterBottle.draw();
    miniWaterBottle.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();

    return;
}