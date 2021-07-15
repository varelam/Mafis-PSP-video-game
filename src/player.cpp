#include "player.hpp"

player::player(int x0, int y0, int scale0, uint32_t hairIdx, uint32_t headIdx, uint32_t torsoIdx, uint32_t armsIdx, uint32_t legsIdx, uint32_t shoeIdx)
{
    uint32_t colorVec[NUM_COLORS] = {RED, RED_LIGHT, PINK, PINK_LIGHT, ORANGE, YELLOW, YELLOW_LIGHT, BROWN, GREEN, GREEN_LIGHT, BLUE, BLUE_LIGHT, PURPLE, GREY, GREY_LIGHT, BLACK, WHITE};

    xi = x0;
    yi = y0;
    vx = 0;
    vy = 0;
    scale = scale0;
    dir = 0;
    acc = 0;
    
    uint32_t hairColor  = colorVec[hairIdx];
    uint32_t headColor  = colorVec[headIdx];
    uint32_t torsoColor = colorVec[torsoIdx];
    uint32_t armsColor  = colorVec[torsoIdx];
    uint32_t legsColor  = colorVec[legsIdx];
    uint32_t shoeColor  = colorVec[shoeIdx];

    health  = 5;
    alcohol = 0;

    levelAge = 0;
    levelSign = 0;
    levelPol = 0;
    levelMusic = 0;
    levelFunny = 0;
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

void player::switchDir()
{
    if(dir>0){dir=0;}else{dir = 1;}
}

void player::increaseHealth()
{
    health++;
    if(health > 5){health=5;}
}

void player::decreaseHealth()
{
    health--;
    if(health < 0){health=0;}
}

void player::increaseAlcohol()
{
    alcohol++;
    if(alcohol > 5){alcohol=5;}
}

void player::decreaseAlcohol()
{
    alcohol--;
    if(alcohol < 0){alcohol=0;}
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

void player::drawBoy()
{
    // Draw Shoes
    graph::drawRect(xi, yi, 40/scale, 10/scale, shoeColor);
    // Draw Legs
    graph::drawRect(xi + 10/scale, yi -50/scale, 20/scale, 50/scale, legsColor);
    // Draw Hair
    graph::drawRect(xi -7/scale, yi -140/scale, 54/scale, 40/scale, hairColor);
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

void player::drawHealth()
{
    for (int i = 0; i<health ; i++)
    {
        graph::drawRect(5,SCREEN_HEIGHT-60 - i*10, 10, 5, RED_LIGHT);
    }
    
}
void player::drawAlcohol()
{
    for (int i = 0; i<alcohol ; i++)
    {
        graph::drawRect(25,SCREEN_HEIGHT-60 - i*10, 10, 5, YELLOW_LIGHT);
    }
}

void player::drawCombo()
{
    graph::drawRect(45,SCREEN_HEIGHT-20 , 20, 20, GREEN_LIGHT);
}

void player::drawHitBox()
{
    int xp = 20; // Player half size, real size = 80 x 140
    int yp = 70;
    int xcp = xi + xp/scale; // Player hit box centroid
    int ycp = yi - yp/scale;
    graph::drawRect(xcp-xp/scale,ycp-yp/scale,2*xp/scale,2*yp/scale,PURPLE);
}

void player::randomizeLevels()
{
    levelAge =  (rand() % 3) - 1;
    levelSign = (rand() % 3) - 1;
    levelPol =  (rand() % 3) - 1;
    levelMusic = (rand() % 3) - 1;
    levelFunny = (rand() % 3) - 1;
}


void player::printBio()
{
    pspDebugScreenClear();
    pspDebugScreenPrintf("O MEU PERFIL:\n\n\n\n");

    if(levelAge>0)
    {   switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("IDADE:\t21\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("IDADE:\t22\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("IDADE:\t23\n\n\n\n");break;
            default:pspDebugScreenPrintf("IDADE:\t24\n\n\n\n");break;
        }
    }
    else if(levelAge <0)
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("IDADE:\t18\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("IDADE:\t27\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("IDADE:\t28\n\n\n\n");break;
            default:pspDebugScreenPrintf("IDADE:\t29\n\n\n\n");break;
        }
    }
    else
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("IDADE:\t19\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("IDADE:\t20\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("IDADE:\t25\n\n\n\n");break;
            default:pspDebugScreenPrintf("IDADE:\t26\n\n\n\n");break;
        }
    }

    pspDebugScreenPrintf("SIGNO SOLAR:\n");
    if(levelSign>0)
    {   
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Touro\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("Escorpiao\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("Virgem\n\n\n\n");break;
            default:pspDebugScreenPrintf("Peixes\n\n\n\n");break;
        }    
    }
    else if(levelSign <0)
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Carneiro\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("Aquario\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("Sagitario\n\n\n\n");break;
            default:pspDebugScreenPrintf("Libra\n\n\n\n");break;
        }   
    }
    else  
    {
        switch ((rand() % 4))
        {   
            case 0: pspDebugScreenPrintf("Gemeos\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("Leao\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("Capricornio\n\n\n\n");break;
            default:pspDebugScreenPrintf("Caranguejo\n\n\n\n");break;
        }
    }

    pspDebugScreenPrintf("INTERESSES:\n");
    if(levelPol>0)
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Coisas techy\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("Acampar com os migos\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("Ir a manifs\n\n\n\n");break;
            default:pspDebugScreenPrintf("Puppies\n\n\n\n");break;
        }
    }
    else if(levelPol <0)
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Ir ao gym\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("Saudades queima\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("Jantares do PSD\n\n\n\n");break;
            default:pspDebugScreenPrintf("Jogos do FCP!!!\n\n\n\n");break;
        }
    }
    else
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Fumar esse\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("Jogar playstation\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("Ver bue anime\n\n\n\n");break;
            default:pspDebugScreenPrintf("Chillar no McDonalds\n\n\n\n");break;
        }
    }


    pspDebugScreenPrintf("SPOTIFY:\n");
    if(levelMusic>0)
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Taylor Swift\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("Rock, Indie e Jazz!\n\n\n\n");break;
            case 2: pspDebugScreenPrintf("Ze Mario Branco\n\n\n\n");break;
            default:pspDebugScreenPrintf("Tudo da Cuca Monga\n\n\n\n");break;
        }
    }
    else if(levelMusic <0)
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Arianna Grande\n\n\n\n");break;
            case 1: pspDebugScreenPrintf("Piruka\n\n\n\n");;break;
            case 2: pspDebugScreenPrintf("John Mayer\n\n\n\n");break;
            default:pspDebugScreenPrintf("Justin Bieber\n\n\n\n");break;
        }
    }
    else
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Hip hop\n\n\n");break;
            case 1: pspDebugScreenPrintf("Bandas do NOS Alive\n\n\n");break;
            case 2: pspDebugScreenPrintf("Tame Impala\n\n\n");break;
            default:pspDebugScreenPrintf("Queens of the Stone Age\n\n\n");break;
        }  
    }

    pspDebugScreenPrintf("BIO:\n");
    if(levelFunny>0)
    {
       switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Alguem para partilhar um gelado\n\n");break;
            case 1: pspDebugScreenPrintf("Companhia para concertos, alguem?\n\n");break;
            case 2: pspDebugScreenPrintf("Nada como uma boa manif! BLM, LGBTQ+\n\n");break;
            default:pspDebugScreenPrintf("Date na baixa ao por do sol?\n\n");break;
        }       
    }
    else if(levelFunny <0)
    {
        switch ((rand() % 4))
        {
            case 0: pspDebugScreenPrintf("Uma noite louca ;)\n\n");break;
            case 1: pspDebugScreenPrintf("Nao sou como os outros homens\n\n");break;
            case 2: pspDebugScreenPrintf("Nao mando msg primeiro\n\n");break;
            default:pspDebugScreenPrintf("Somos um casal, queremos +1\n\n");break;
        }   
    }
    else
    {
        pspDebugScreenPrintf("\n\n");

    }
    
    graph::drawRect(SCREEN_WIDTH/2,0, SCREEN_WIDTH/2,SCREEN_HEIGHT, WHITE);
    sceDisplayWaitVblankStart();
}