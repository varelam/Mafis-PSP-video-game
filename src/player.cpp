#include "player.hpp"

player::player(int x0, int y0, int scale0, uint32_t hairIdx, uint32_t headIdx, uint32_t torsoIdx, uint32_t armsIdx, uint32_t legsIdx, uint32_t shoeIdx)
{
    uint32_t colorVec[NUM_COLORS] = {RED, RED_LIGHT, PINK, PINK_LIGHT, ORANGE, YELLOW, YELLOW_LIGHT, BROWN, GREEN, GREEN_LIGHT, BLUE, BLUE_LIGHT, PURPLE, GREY, GREY_LIGHT, BLACK, WHITE};

    int xi = x0;
    int yi = y0;
    int vx = 0;
    int vy = 0;
    int scale = scale0;
    dir = 0;
    acc = 0;
    
    uint32_t hairColor  = colorVec[hairIdx];
    uint32_t headColor  = colorVec[headIdx];
    uint32_t torsoColor = colorVec[torsoIdx];
    uint32_t armsColor  = colorVec[torsoIdx];
    uint32_t legsColor  = colorVec[legsIdx];
    uint32_t shoeColor  = colorVec[shoeIdx];
}

void player::setPos(int x0, int y0, int scale0)
{
    xi = x0;
    yi = y0;
    scale = scale0;
}

void player::setVel(int vx0, int vy0)
{
    vx = vx0;
    vy = vy0;
    if(vx0 >0){dir = 1;}else if(vx0 < 0){dir = 0;}
}

void player::setGravity(int g0)
{
    acc = g0;
}
void player::updatePos()
{
    xi += vx;
    yi += vy;

    if(xi>SCREEN_WIDTH){xi = 0;}
    if(xi<0){xi =SCREEN_WIDTH;}
    if(yi>SCREEN_HEIGHT){yi = SCREEN_HEIGHT;}
    if(yi<0){yi = SCREEN_HEIGHT;}

    if(vx >0){dir = 1;}else if(vx < 0){dir = 0;}
}

void player::updateVel(int vxi, int vyi)
{
    vx += vxi;
    vy += vyi + acc;

    if(vx>7){vx = 7;}
    if(vx<-7){vx = -7;}
    if(vy>20){vy = 20;}
    if(vy<-25){vy = -25;}
}

void player::slowDown()
{
    if(vx>0){vx--;}
    if(vx<0){vx++;}
    if(vy>0){vy--;}
    if(vy<0){vy++;}
}

void player::updateColor(int *bodyColors)
{
    uint32_t colorVec[NUM_COLORS] = {RED, RED_LIGHT, PINK, PINK_LIGHT, ORANGE, YELLOW, YELLOW_LIGHT, BROWN, GREEN, GREEN_LIGHT, BLUE, BLUE_LIGHT, PURPLE, GREY, GREY_LIGHT, BLACK, WHITE};

    hairColor  = colorVec[bodyColors[0]];
    headColor  = colorVec[bodyColors[1]];
    torsoColor = colorVec[bodyColors[2]];
    armsColor  = colorVec[bodyColors[3]];
    legsColor  = colorVec[bodyColors[4]];
    shoeColor  = colorVec[bodyColors[5]];
}

void player::draw()
{
    // Draw Shoes
    graph::drawRect(xi, yi, 40/scale, 10/scale, shoeColor);
    // Draw Legs
    graph::drawRect(xi + 10/scale, yi -50/scale, 20/scale, 50/scale, legsColor);
    // Draw Hair
    graph::drawRect(xi -7/scale, yi -140/scale, 54/scale, 70/scale, hairColor);
    // Draw Arms
    graph::drawRect(xi -5/scale, yi -90/scale, 50/scale, 40/scale, armsColor);
    // Draw Torso
    graph::drawRect(xi + 5/scale, yi -100/scale, 30/scale, 60/scale, torsoColor);
    // Draw Face
    graph::drawRect(xi + 3/scale + dir*5, yi -130/scale, 26/scale, 25/scale, headColor);
}

int player::moveAround()
{
    int result = 0;

    while(true)
    {
        // Read commands
        SceCtrlData ctrlData;
        bool b_exit = false;
        while(!b_exit)
        {
            // Read buttons
            sceCtrlReadBufferPositive(&ctrlData, 1);

            // Select cross
            if(ctrlData.Buttons & ctrlData.Buttons & PSP_CTRL_CROSS) // Go up
            {
                if(yi >= SCREEN_HEIGHT){updateVel(0,-25);}else{updateVel(0,0);} // if on ground
                b_exit = true;
            }
            else if(ctrlData.Buttons & PSP_CTRL_DOWN) // Go down
            {
                updateVel(0,2);
                b_exit = true;
            }
            else if(ctrlData.Buttons & PSP_CTRL_RIGHT) // Go right
            {
                updateVel(2,0);
                b_exit = true;
            }
            else if(ctrlData.Buttons & PSP_CTRL_LEFT) // Go Left
            {   
                updateVel(-2,0);
                b_exit = true;
            }
            else if(ctrlData.Buttons & PSP_CTRL_CIRCLE) // Exit
            {
                result = -1;
                b_exit = true;
            }
            else
            {
                slowDown();
                updateVel(0,0);
                b_exit = true;
            }
        }

        updatePos();
        return result;
    }
}