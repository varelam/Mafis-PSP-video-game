#include "03_intro.hpp"

void State03()
{
    graph::clear(BLUE_LIGHT);

    graph::drawRect(50,50,50,50,YELLOW);

    graph::swapBuffers();

    sceDisplayWaitVblankStart();
    return;
}