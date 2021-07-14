#ifndef __PLAYER__
#define __PLAYER__

#include "mafis.hpp"
#include "graph.hpp"
#include <cstdint>
#include <stdlib.h>
#include <pspdebug.h>
#include <pspctrl.h>

class player {       // The class
  public:             // Access specifier
    
    int xi; // pos x
    int yi; // pos y
    int vx; // vel x
    int vy; // vel y
    int scale; // drawing scale
    int dir;  // face direction
    int acc;  // gravity acceleration

    uint32_t hairColor;
    uint32_t headColor;
    uint32_t torsoColor;
    uint32_t armsColor;
    uint32_t legsColor;
    uint32_t shoeColor;

    int health;
    int alcohol;

    // Levels for Tinder game
    int levelAge;
    int levelSign;
    int levelPol;
    int levelMusic;
    int levelFunny;
    
    // Constructor
    player(int x0, int y0, int scale0, uint32_t hairIdx, uint32_t headIdx, uint32_t torsoIdx, uint32_t armsIdx, uint32_t legsIdx, uint32_t shoeIdx);
    void updateColor(int *bodyColors);
    void setPos(int x0, int y0, int scale0);
    void setVel(int vx0, int vy0);
    void setGravity(int g0);
    void updatePos();
    void updateVel(int vxi, int vyi);
    void slowDown();
    void increaseHealth();
    void decreaseHealth();
    void increaseAlcohol();
    void decreaseAlcohol();
    void draw();
    void drawBoy();
    void drawHealth();
    void drawAlcohol();
    void drawCombo();
    int moveAround();
    void drawHitBox();
    

    void randomizeLevels();
    void printBio();
};

#endif