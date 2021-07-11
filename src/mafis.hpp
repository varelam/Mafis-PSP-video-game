#ifndef __MAFIS__
#define __MAFIS__

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 272

// Colors
#define RED 0x0A038E
#define RED_LIGHT 0x1225FF

#define PINK 0xBA75FF
#define PINK_LIGHT 0xDBBAFF

#define ORANGE 0x00A7FF

#define YELLOW 0x0AFCFC
#define YELLOW_LIGHT 0x8BECFF

#define BROWN 0x003F7F

#define GREEN 0x407F15
#define GREEN_LIGHT 0xB9FF81

#define BLUE 0xB15B39
#define BLUE_LIGHT 0xFFAE78

#define PURPLE 0xF730AB

#define GREY 0x545454
#define GREY_LIGHT 0xB4B4B4

#define BLACK 0x000000
#define WHITE 0xFFFFFF

#define NUM_COLORS 17

#include <pspctrl.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <time.h> // nanosleep

void pspDelay();
void PressX();
bool PressXorC();

#endif