// PSP includes
#include <pspkernel.h>
#include <pspdebug.h>

// Load Module
PSP_MODULE_INFO("PRENDAAA",0,1,0); // Version 1.0

// C++ includes
#include <unistd.h> // sleep
#include <cstdint>

// Project
#include "mafis.hpp"
#include "player.hpp"
#include "graph.hpp"
#include "01_psp_boot.hpp"
#include "02_start.hpp"
#include "03_intro.hpp"
#include "04_tutorial.hpp"
#include "05_77.hpp"

auto main() -> int
{
  // Home button callback
  setupCallbacks();

  // Start Debug Screen
  pspDebugScreenInit();

  // Initiate controls
  sceCtrlSetSamplingCycle(0);
  sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

  // Start of the game print
  State02();
 
  // Create a player
  player myPlayer(100,100,2,15,3,2,3,10,0);

  // Screen begins
  graph::init();

  // Levels!
  State03(myPlayer);
  State04(myPlayer);
  State05(myPlayer);

  sceKernelExitGame();	
}
