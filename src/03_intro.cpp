#include "03_intro.hpp"

void State03()
{
    graph::clear(BLUE_LIGHT);
    graph::drawRect(50,50,50,50,YELLOW);
    graph::swapBuffers();

    sceDisplayWaitVblankStart();

    sleep(3);

    graph::drawRect(20,150,20,100,YELLOW_LIGHT);
    graph::swapBuffers();
    sleep(3);

    graph::drawRect(20,150,20,100,RED);
    graph::swapBuffers();
    sleep(3);

    graph::drawRect(120,150,20,130,RED_LIGHT);
    graph::swapBuffers();
    sleep(3);

    graph::drawRect(220,150,650,100,PINK);
    graph::swapBuffers();
    sleep(3);

    graph::drawRect(420,450,270,10,PINK_LIGHT);
    graph::swapBuffers();
    sleep(3);

    graph::drawRect(50,450,230,130,ORANGE);
    graph::swapBuffers();
    sleep(3);

    graph::drawRect(220,250,250,200,PURPLE);
    graph::swapBuffers();
    sleep(3);

    graph::drawRect(320,10,20,300,GREEN_LIGHT);
    graph::swapBuffers();
    sleep(3);

    graph::drawRect(20,150,20,20,GREEN);
    graph::swapBuffers();
    sleep(3);

    

    

    
    return;
}