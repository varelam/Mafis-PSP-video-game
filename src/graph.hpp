#ifndef __GRAPH__
#define __GRAPH__

#include <cstdint>
#include "pspge.h"
#include "pspdisplay.h"
#include "psputils.h"

#include "mafis.hpp"
namespace graph
{
    void init();
    void clear(uint32_t color);
    void clearKeep(uint32_t off, uint32_t color);
    void swapBuffers();
    void drawRect(int x, int y, int w, int h, uint32_t color);
}
#endif