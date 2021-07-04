#ifndef __BLOCKS__
#define __BLOCKS__

#include "mafis.hpp"
#include "player.hpp"
#include "graph.hpp"
#include <cstdint>
#include <stdlib.h>
#include <pspdebug.h>
#include <pspctrl.h>

class block {       // The class
  public:             // Access specifier
    
    int status; // status for block: <0 = inactive
    int kind;
    int xi; // pos x
    int yi; // pos y
    int vx; // vel x
    int vy; // vel y
    int scale; // drawing scale

    // Constructor
    block(int kind0);
    void activate();
    void deactivate();
    void update();
    void draw();

    void drawWhisky();    // kind > 3 Takes -1 health
    void drawWater();     // kind = 0 Gives health
    void drawSuperBock(); // kind = 1 Combo ready
    void drawBagaco();    // kind = 2 Completes combo
    
    bool detectColision(player &myPlayer);
    // void drawRedbull();   // Gives you speed
    // void drawAbsinto(); // Instant death
    // void drawHidromel(); // Higher score
    // void drawBlunt();  // Makes you slower
    
};

#endif