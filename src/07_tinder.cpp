#include "07_tinder.hpp"

void State07(player &myPlayer)
{
    int scaleii = 1;
    int xii = SCREEN_WIDTH/2 + 50;
    int yii = SCREEN_HEIGHT/2 + 80;
    // Set player properties for this level
    myPlayer.setPos(xii,yii,scaleii);

    // Create a random tinder match
    player someBoy(xii,yii,scaleii ,0,0,0,0,0,0);

    int score[5] = {0,0,0,0,0};
    while(PressXorC())
    {
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

        // Swipe function

        if (true)
        {
            score[0] += someBoy.levelAge;
            score[1] += someBoy.levelSign;
            score[2] += someBoy.levelPol;
            score[3] += someBoy.levelMusic;
            score[4] += someBoy.levelFunny;
        }
        

        // Draw
        graph::swapBuffers();
        graph::clearKeep(20, WHITE);
        someBoy.printBio();
        someBoy.drawBoy();

        graph::swapBuffers();
        sceDisplayWaitVblankStart();

    }

}