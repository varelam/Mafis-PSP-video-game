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
    pspDebugScreenPrintf("Aqui vais viver a tua melhor vida de estudante aka apanhar a puta todos os santos dias\n");
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();
    
    block whiskyBottle(3); // Create whisky

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

    block waterBottle(0); // Create water Bottle

    pspDebugScreenClear();
    pspDebugScreenPrintf("Para apanhares a puta nada melhor do que uns bons menus do 7, que espero nao ser preciso lembrar\n");
    pspDebugScreenPrintf("consistem de uma mini Super Bock e um bagaco:\n");
    graph::swapBuffers();
    graph::clearKeep(40, BLUE_LIGHT);
    myPlayer.draw();
    miniSuperBottle.draw();
    superBottle.draw();

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
            // clkCounter = 0;
            // blockCounter++;
            oneBlock.activate();
            blockCounter++;
            // oneBlock.deploy();
            // if(blockCounter>1){blockCounter=1;}
        }

        //for (int i = 0; i<blockCounter; i++)
        //{
            oneBlock.update();
            if (oneBlock.yi > SCREEN_HEIGHT){oneBlock.deactivate();} 
        //}
        

        graph::clearKeep(20, BLUE_LIGHT); 
        oneBlock.draw();
        myPlayer.draw();
        graph::swapBuffers();

        
    }
    
}