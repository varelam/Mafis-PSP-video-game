#include "07_tinder.hpp"

void drawStats(int* score)
{   /*
    int levelAge;
    int levelSign;
    int levelPol;
    int levelMusic;
    int levelFunny;
    */

    for (int i = 0; i<score[0] ; i++){graph::drawRect(SCREEN_WIDTH-50,SCREEN_HEIGHT-60 - i*10, 10, 10, RED_LIGHT);}
    for (int i = 0; i<score[1] ; i++){graph::drawRect(SCREEN_WIDTH-40,SCREEN_HEIGHT-60 - i*10, 10, 10, YELLOW);}
    for (int i = 0; i<score[2] ; i++){graph::drawRect(SCREEN_WIDTH-30,SCREEN_HEIGHT-60 - i*10, 10, 10, GREEN_LIGHT);}
    for (int i = 0; i<score[3] ; i++){graph::drawRect(SCREEN_WIDTH-20,SCREEN_HEIGHT-60 - i*10, 10, 10, BLUE_LIGHT);}
    for (int i = 0; i<score[4] ; i++){graph::drawRect(SCREEN_WIDTH-10,SCREEN_HEIGHT-60 - i*10, 10, 10, PURPLE);}
}

int State07(player &myPlayer)
{
    int scaleii = 1;
    int xii = SCREEN_WIDTH/2 + 50;
    int yii = SCREEN_HEIGHT/2 + 80;
    // Set player properties for this level
    myPlayer.setPos(xii,yii,scaleii);

    // Create a random tinder match
    player someBoy(xii,yii,scaleii ,0,0,0,0,0,0);

    int score[5] = {0,0,0,0,0};
    int swipeValue = 0;
    bool superLike = true;
    bool exit = false;
    bool victory = false;

    while(!exit)
    {
        // Generate graphics and player
        int hairColor = 15;
        int hairColorSel = rand() % 3;
        switch (hairColorSel)
        {
            case 0: // blonde
                hairColor = 5;
                break;
            case 1: // brown
                hairColor = 7;
                break;
            default:// black
                hairColor = 15; 
                break;
        }
        int skinColor = rand() % 2;
        int skinColorSel = rand() % 2;
        switch (skinColorSel)
        {
            case 0: // dark
                skinColor = 7;
                break;
            default:// light
                skinColor = 3; 
                break;
        }

        int clothesColor = rand() % 15;
        int pantsColor = rand() % 15;
        int shoeColor = rand() % 15;
        int bodyColors[6] = {hairColor,skinColor ,clothesColor,clothesColor, pantsColor,shoeColor};
        someBoy.updateColor(bodyColors);
        someBoy.randomizeLevels();


        // Draw
        graph::swapBuffers();
        graph::clearKeep(20, WHITE);
        someBoy.printBio();
        someBoy.drawBoy();
        drawStats(score);
        graph::swapBuffers();
        sceDisplayWaitVblankStart();

        // Handle swipes
        int swipeValue = swipe();
        if(swipeValue == 0){victory = false; exit = true;}
        if(swipeValue>5){if(superLike){superLike=false;}else{swipeValue=5;pspDebugScreenPrintf("JA USASTE O SUPER LIKE!");}}
        score[0] += swipeValue*someBoy.levelAge;
        score[1] += swipeValue*someBoy.levelSign;
        score[2] += swipeValue*someBoy.levelPol;
        score[3] += swipeValue*someBoy.levelMusic;
        score[4] += swipeValue*someBoy.levelFunny;
        for(int i=0;i<5; i++){if(score[i]<0){score[i]=0;}}

        // Check for game completion
        victory = true;
        for(int i=0;i<5; i++){if(score[i]<15){victory = false;}}
        if(victory){exit = true;}

        // Draw swipe result
        graph::swapBuffers();
        if(swipeValue<0){graph::clear(RED_LIGHT);}
        else if (swipeValue>10){graph::clear(BLUE);}
        else{graph::clear(GREEN_LIGHT);}
        
        graph::swapBuffers();
        sceDisplayWaitVblankStart();
        pspDelay();
    }

    if(victory){return 1;}else{return -1;}
}