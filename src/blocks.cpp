#include "blocks.hpp"

block::block(int kind0)
{
    status = -1;
    kind = kind0; // Random out of three colors
    xi = -100;
    yi = -100;
    vx = 0;
    vy = 2;
    scale = 4;
}

void block::update()
{
    if(status > 0)
    {
        xi += vx;
        yi += vy;
        if(xi>SCREEN_WIDTH){xi = 0;}
        if(xi<0){xi =SCREEN_WIDTH;}
        if(yi>SCREEN_HEIGHT){yi = SCREEN_HEIGHT;}
        if(yi<0){yi = SCREEN_HEIGHT;}
    }
    else
    {
        
    }
}

void block::activate()
{
    // Add Random position in xy
    xi = 40 + rand() % (SCREEN_WIDTH - 40);
    yi = 0;
    status = 1;
}

void block::deactivate()
{
    status = -1;
    xi = -100;
    yi = -100;
}

void block::drawWhisky()
{
    graph::drawRect(xi + 10/scale, yi, 20/scale, 40/scale, GREEN);//top
    graph::drawRect(xi, yi + 40/scale, 40/scale, 80/scale, GREEN);//body
    graph::drawRect(xi, yi + 70/scale, 30/scale, 30/scale, YELLOW);//label
}
void block::drawWater()
{
    graph::drawRect(xi + 10/scale, yi, 20/scale, 40/scale, GREEN);//top
    graph::drawRect(xi, yi + 40/scale, 40/scale, 80/scale, GREEN);//body
    graph::drawRect(xi, yi + 70/scale, 30/scale, 30/scale, YELLOW);//label
}
void block::drawSuperBock()
{
    graph::drawRect(xi + 10/scale, yi, 20/scale, 40/scale, BROWN);//top
    graph::drawRect(xi, yi + 40/scale, 40/scale, 80/scale, BROWN);//body
    graph::drawRect(xi, yi + 70/scale, 30/scale, 30/scale, RED);//label
}

void block::draw()
{
    if (status >0)
    {
        switch(kind)
        {
            case 0:
            {
                drawWater();
            }
            break;
            case 1:
            {
                drawSuperBock();
            }
            break;
            default:
            {
                drawWhisky();
            }
        break;
        }
        
    }  
}