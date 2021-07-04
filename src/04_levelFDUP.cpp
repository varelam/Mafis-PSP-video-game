#include "04_levelFDUP.hpp"



void IntroState04(player &myPlayer)
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

void State04(player &myPlayer)
{
    IntroState04(myPlayer);

    myPlayer.setGravity(2);

    // Generate blocks
    int blockCounter = 0;
    int maxBlocks = 1;
    block oneBlock(rand() % 3);

    // Measure time
    clock_t t_start;
    clock_t t_current;
    double timeTaken;
    t_start = clock();


    // Force clear
    graph::swapBuffers();
    graph::clear(BLUE_LIGHT);
    graph::swapBuffers();
    graph::clear(BLUE_LIGHT);
    myPlayer.setPos(SCREEN_WIDTH/2,SCREEN_HEIGHT,4);
    myPlayer.draw();
    graph::swapBuffers();

    // Game loop
    while(myPlayer.moveAround() >= 0)
    {
        t_current = clock();
        timeTaken = ((double)(t_current - t_start))/CLOCKS_PER_SEC;
        if(timeTaken > 2 && blockCounter < maxBlocks) // Regularly generate blocks
        {
            // blockCounter++;
            oneBlock.activate();
            blockCounter++;
            // if(blockCounter>1){blockCounter=1;}
        }

        //for (int i = 0; i<blockCounter; i++)
        //{
            oneBlock.update();
            if (oneBlock.yi > SCREEN_HEIGHT){oneBlock.deactivate();} 

            bool colision = oneBlock.detectColision(myPlayer);
            if(colision){return;}
            
            
        //}
        

        graph::clearKeep(20, BLUE_LIGHT); 
        oneBlock.draw();
        myPlayer.draw();
        graph::swapBuffers();
    }
    
}