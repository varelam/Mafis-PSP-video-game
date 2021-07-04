#include "05_77.hpp"

void State05(player &myPlayer)
{
    // Generate blocks
    int blockCounter = 0;
    int maxBlocks = 100;

    // PSP C++ does not support <vector> of objects so I will do
    // something very, very, very ugly. But hey it works
    block *blocks = reinterpret_cast<block*>(malloc(sizeof(block*) * maxBlocks));

    for(int i = 0; i<maxBlocks; i++)
    {
        block newBlock(rand() % 15);
        blocks[i] = newBlock;
    }
 
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
    
    myPlayer.setGravity(2);

    /////////////////////////////////////  Game loop  ///////////////////////////////////////
    while(myPlayer.moveAround() >= 0)
    {
        t_current = clock();
        timeTaken = ((double)(t_current - t_start))/CLOCKS_PER_SEC;

        // Regularly generate blocks
        if(timeTaken > 0.2 && blockCounter < maxBlocks) 
        {
            blocks[blockCounter].activate();
            blockCounter++;
            t_start = t_current;
        }

        // Handle blocks
        for (int i = 0; i<blockCounter; i++)
        {
            blocks[i].update();
            if (blocks[i].yi > SCREEN_HEIGHT - 20){blocks[i].deactivate();} 
            if(blocks[i].detectColision(myPlayer)){return;}
        }
        
        // Draw stuff
        graph::clear(BLUE_LIGHT);
        myPlayer.draw();
        for (int i = 0; i<blockCounter; i++)
        {
            blocks[i].draw();
        } 
        graph::swapBuffers();
    }
    
    free(blocks);
}