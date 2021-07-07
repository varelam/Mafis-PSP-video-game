#include "blocks.hpp"

block::block(int kind0)
{
    status = -1;
    kind = kind0; // Random out of three kinds
    xi = -100;
    yi = -100;
    vx = 0;
    vy = 1;
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
    // Add Random position in x
    xi = 20 + rand() % (SCREEN_WIDTH - 20);
    yi = 0;
    status = 1;
}

void block::deactivate()
{
    status = -1;
    xi = 0;
    yi = 0;
}
void block::increaseSpeed()
{
    vy++;
}

void block::drawWhisky()
{
    graph::drawRect(xi + 15/scale, yi, 20/scale, 60/scale, GREEN);//top
    graph::drawRect(xi, yi + 60/scale, 50/scale, 90/scale, GREEN);//body
    graph::drawRect(xi, yi + 100/scale, 40/scale, 30/scale, YELLOW);//label
}
void block::drawWater()
{
    graph::drawRect(xi + 10/scale, yi, 20/scale, 10/scale, BLUE);//top
    graph::drawRect(xi, yi + 10/scale, 40/scale, 50/scale, WHITE);//body
}
void block::drawSuperBock()
{
    graph::drawRect(xi + 10/scale, yi, 20/scale, 40/scale, BROWN);//top
    graph::drawRect(xi, yi + 40/scale, 40/scale, 80/scale, BROWN);//body
    graph::drawRect(xi, yi + 70/scale, 30/scale, 30/scale, RED);//label
}
void block::drawBagaco()
{
    graph::drawRect(xi, yi, 20/scale, 30/scale, WHITE);//top
    graph::drawRect(xi+5/scale, yi + 10/scale, 10/scale, 15/scale, YELLOW);//body
}

void block::draw()
{
    if (status > 0)
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
            case 2:
            {
                drawBagaco();
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


int block::detectColision(player &myPlayer)
{
    int colision = -1;
    int xp = 20; // Player half size, real size = 80 x 140
    int yp = 70;
    int xcp = myPlayer.xi + xp/myPlayer.scale; // Player hit box centroid
    int ycp = myPlayer.yi - yp/myPlayer.scale;
    

    int xb ; // Block half size
    int yb;
    int xcb; // Block centroid
    int ycb;
    
    switch(kind)
    {
        case 0:
        {
            // Water 50 x 60
            xb = 25;
            yb = 30;
        }
        break;
        case 1:
        {
            // SuperBock 40 x 120
            xb = 20;
            yb = 60;
        }
        break;
        case 2:
        {
            // Bagaco 20 x 30
            xb = 10;
            yb = 15;
        }
        break;
        default:
        {
            // Whisky 50 x 75
            xb = 25;
            yb = 75;
        }
        break;
    }

    xcb = xi + xb/scale;
    ycb = yi + yb/scale;

    // Condition1: bottom left block corner is inside square
    if( xcb - xb/scale > xcp - xp/myPlayer.scale && xcb - xb/scale < xcp + xp/myPlayer.scale &&
        ycb + yb/scale < ycp + yp/myPlayer.scale && ycb + yb/scale > ycp - yp/myPlayer.scale) 
    {
        colision = kind;
    }
    // Condition2: bottom right block corner is inside square
    else if( xcb + xb/scale > xcp - xp/myPlayer.scale && xcb + xb/scale < xcp + xp/myPlayer.scale &&
        ycb + yb/scale < ycp + yp/myPlayer.scale && ycb + yb/scale > ycp - yp/myPlayer.scale) 
    {
        colision = kind;
    }
    // Condition3 : top left block corner is inside square
    else if( xcb - xb/scale > xcp - xp/myPlayer.scale && xcb - xb/scale < xcp + xp/myPlayer.scale &&
        ycb - yb/scale < ycp + yp/myPlayer.scale && ycb - yb/scale > ycp - yp/myPlayer.scale) 
    {
        colision = kind;
    }
    // Condition4 : top right block corner is inside square
    else if( xcb + xb/scale > xcp - xp/myPlayer.scale && xcb + xb/scale < xcp + xp/myPlayer.scale &&
        ycb - yb/scale < ycp + yp/myPlayer.scale && ycb - yb/scale > ycp - yp/myPlayer.scale) 
    {
        colision = kind;
    }
    else
    {
        colision = -1;
    }

    return colision;
}