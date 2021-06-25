#include "player.hpp"

player::player(int hairIdx, int headIdx, int torsoIdx, int armsIdx, int legsIdx, int shoeIdx)
{
    uint32_t colorVec[NUM_COLORS] = {RED, RED_LIGHT, PINK, PINK_LIGHT, ORANGE, YELLOW, YELLOW_LIGHT, BROWN, GREEN, GREEN_LIGHT, BLUE, BLUE_LIGHT, PURPLE, GREY, GREY_LIGHT, BLACK, WHITE};

    uint32_t hairColor  = colorVec[hairIdx];
    uint32_t headColor  = colorVec[headIdx];
    uint32_t torsoColor = colorVec[torsoIdx];
    uint32_t armsColor  = colorVec[torsoIdx];
    uint32_t legsColor  = colorVec[legsIdx];
    uint32_t shoeColor  = colorVec[shoeIdx];
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

void player::draw(uint32_t xi, uint32_t yi, uint32_t scale)
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
    graph::drawRect(xi + 3/scale, yi -130/scale, 26/scale, 25/scale, headColor);
    
}