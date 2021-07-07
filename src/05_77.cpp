#include "05_77.hpp"

void State05(player &myPlayer)
{
    // Generate blocks
    int blockCounter = 0;
    int maxBlocks = 1000;

    // PSP C++ does not support <vector> of objects so I will do
    // something very, very, very ugly. But hey it works
    block *blocks = reinterpret_cast<block*>(malloc(sizeof(block*) * maxBlocks));

    for(int i = 0; i<maxBlocks; i++)
    {
        block newBlock(rand() % 7);
        blocks[i] = newBlock;
    }
 
    // Measure time
    clock_t t_start;
    clock_t t_current;
    double timeTaken;
    double timeBlocks = 0.5;
    t_start = clock();

    // Force clear
    graph::swapBuffers();
    graph::clear(BLUE_LIGHT);
    graph::swapBuffers();
    graph::clear(BLUE_LIGHT);
    myPlayer.setPos(SCREEN_WIDTH/2,SCREEN_HEIGHT,4);
    myPlayer.draw();
    graph::swapBuffers();
    
    // Others
    myPlayer.setGravity(2);
    int colision;
    bool combo = false;
    bool exit = false;
    bool victory = false;

    /////////////////////////////////////  Game loop  ///////////////////////////////////////
    while(!exit)
    {
        if(myPlayer.moveAround()<0){exit=true;victory=false;}

        t_current = clock();
        timeTaken = ((double)(t_current - t_start))/CLOCKS_PER_SEC;

        // Regularly generate blocks
        if(timeTaken > timeBlocks && blockCounter < maxBlocks) 
        {
            blocks[blockCounter].activate();
            blockCounter++;
            t_start = t_current;

            if(blockCounter == maxBlocks){exit=true;victory=false;}
        }

        // Handle blocks
        for (int i = 0; i<blockCounter; i++)
        {
            if(blocks[i].status > 0)
            {
                blocks[i].update();
                if (blocks[i].yi > SCREEN_HEIGHT - 1){blocks[i].deactivate();} 

                colision = blocks[i].detectColision(myPlayer);
                if(colision >= 0)
                {
                    blocks[i].deactivate();
                    switch(colision)
                    {
                        case 0:
                        {
                            // Water 50 x 60
                            myPlayer.increaseHealth();
                        }
                        break;
                        case 1:
                        {
                            // SuperBock 40 x 120
                            combo = true;
                        }
                        break;
                        case 2:
                        {
                            // Bagaco 20 x 30
                            if(combo)
                            {
                                myPlayer.increaseAlcohol();
                                for (int i = 0; i<maxBlocks; i++)
                                {
                                    blocks[i].increaseSpeed();
                                }
                                timeBlocks=timeBlocks - 0.10;
                                if(myPlayer.alcohol>4)
                                {
                                    exit = true; victory = true;
                                }
                            }
                            else
                            {   
                                myPlayer.decreaseHealth();
                                if(myPlayer.health < 1)
                                {
                                    exit = true; victory = false;
                                }
                            }
                            combo = false;
                        }
                        break;
                        default:
                        {
                            // Whisky 50 x 75
                            myPlayer.decreaseHealth();
                            if(myPlayer.health < 1)
                            {
                                exit = true; victory = false;
                            }
                            combo = false;
                        }
                        break;
                    }
                
                }
            }
            
        }
        
        // Draw stuff
        graph::clear(BLUE_LIGHT);
        myPlayer.draw();
        myPlayer.drawHealth();
        myPlayer.drawAlcohol();
        if(combo){myPlayer.drawCombo();}
        for (int i = 0; i<blockCounter; i++)
        {
            blocks[i].draw();
        }
        // myPlayer.drawHitBox();
        graph::swapBuffers();
    }
    
    free(blocks);

    pspDebugScreenClear();
    if(victory)
    {
        pspDebugScreenPrintf("B O A\n");
    }
    else
    {
        pspDebugScreenPrintf("Tenta outra vez...\n");
    }
    graph::swapBuffers();
    graph::clearKeep(20, BLUE_LIGHT);
    myPlayer.draw();
    graph::swapBuffers();
    pspDelay();
    PressX();
}