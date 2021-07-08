#include "graph.hpp"
namespace graph
{
    uint32_t *draw_buffer;
    uint32_t *display_buffer;

    void init()
    {
        draw_buffer = static_cast<uint32_t*>(sceGeEdramGetAddr());
        display_buffer = static_cast<uint32_t*>(sceGeEdramGetAddr()) + (512 * SCREEN_HEIGHT * sizeof(uint32_t));

        sceDisplaySetMode(0, SCREEN_WIDTH, SCREEN_HEIGHT);
        sceDisplaySetFrameBuf(display_buffer,512, PSP_DISPLAY_PIXEL_FORMAT_8888, 1);
    }
    
    void clear(uint32_t color)
    {
        for(int i = 0; i< 512 * SCREEN_HEIGHT; i++)
        {
            draw_buffer[i] = color;
        }
    }
    
    void clearKeep(uint32_t off, uint32_t color)
    {
        for(int i = 512*off; i< 512 * SCREEN_HEIGHT; i++)
        {
            draw_buffer[i] = color;
        }
    }

    void swapBuffers()
    {
        uint32_t* temp = display_buffer;
        display_buffer = draw_buffer;
        draw_buffer = temp;
        sceKernelDcacheWritebackInvalidateAll();
        sceDisplaySetFrameBuf(display_buffer,512, PSP_DISPLAY_PIXEL_FORMAT_8888, PSP_DISPLAY_SETBUF_NEXTFRAME);
    }
    
    void drawRect(int x, int y, int w, int h, uint32_t color)
    {
        if(x > SCREEN_WIDTH || x < 0)
        {
            x = SCREEN_WIDTH;
        }
        if(y > SCREEN_HEIGHT || y < 0)
        {
            y = SCREEN_HEIGHT;
        }

        if (x + w > SCREEN_WIDTH || x + w < 0)
        {
            w = SCREEN_WIDTH - x -1;
            if(w<0){w=0;}
        }
        if (y + h > SCREEN_HEIGHT || y + h < 0)
        {
            h = SCREEN_HEIGHT - y -1;
            if(h<0){h=0;}
        }

        int off = x + (y*512);
        
        for(int i = 0; i<w; i++)
        {
            for(int j = 0; j < h; j++)
            {
                draw_buffer[i + j*512 + off] = color;
            }
        }

    }
}