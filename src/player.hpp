#ifndef __PLAYER__
#define __PLAYER__

#include "mafis.hpp"
#include "graph.hpp"
#include <cstdint>

class player {       // The class
  public:             // Access specifier
    
    uint32_t hairColor;
    uint32_t headColor;
    uint32_t torsoColor;
    uint32_t armsColor;
    uint32_t legsColor;
    uint32_t shoeColor;
    
    // Constructor
    player(int hairIdx, int headIdx, int torsoIdx, int armsIdx, int legsIdx, int shoeIdx);
    void updateColor(int *bodyColors);
    void draw(uint32_t xi, uint32_t yi, uint32_t scale);
};

#endif