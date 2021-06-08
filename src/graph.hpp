#include <cstdint>
#include "pspge.h"
#include "pspdisplay.h"
#include "psputils.h"

#include "mafis.hpp"


namespace graph
{
    void init();
    void clear(uint32_t color);
    void swapBuffers();
    void drawRect(int x, int y, int w, int h, uint32_t color);
}