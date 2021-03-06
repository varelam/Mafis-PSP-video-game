// PSP includes
#include <pspkernel.h>
#include <pspdebug.h>

// Load Module
PSP_MODULE_INFO("PRENDAAA",0,1,0); // Version 1.0

// C++ includes
#include <unistd.h>
#include <cstdint>
#include <stdlib.h>
#include <cstdint>
#include <unistd.h>
#include <time.h>

// Project
#include "mafis.hpp"
#include "player.hpp"
#include "graph.hpp"
#include "01_psp_boot.hpp"
#include "02_start.hpp"
#include "03_intro.hpp"
#include "04_tutorial.hpp"
#include "05_77.hpp"
#include "06_tutorial2.hpp"
#include "07_tinder.hpp"
#include "08_end.hpp"

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
  player myPlayer(100,100,1,15,3,2,3,10,0);

  // Screen begins
  graph::init();

  // Levels!
  State03(myPlayer);
  State04(myPlayer);

  bool playAgain = true;
  int victory;

  while(playAgain)
  {
    victory = State05(myPlayer);
    if(victory != 0)
    {
      
      graph::swapBuffers();
      graph::clearKeep(20, BLUE_LIGHT);
      pspDebugScreenPrintf("Queres jogar outra vez?\n");
      myPlayer.draw();
      graph::swapBuffers();
      pspDelay();

      if(PressXorC())
      {
        playAgain = true;
      }
      else
      {
        playAgain = false;
      }
    }
    else 
    {
      playAgain = false;
      graph::swapBuffers();
      graph::clearKeep(20, BLUE_LIGHT);
      myPlayer.draw();
      graph::swapBuffers();
      pspDelay();
      PressX();
    }
  }
 
  if(victory != 0)
  {
    sceKernelExitGame();
  }

  State06(myPlayer);

  playAgain = true;
  while(playAgain)
  {
    victory = State07(myPlayer);
    if(victory < 0)
    {
      graph::swapBuffers();
      graph::clearKeep(20, WHITE);
      pspDebugScreenPrintf("Queres jogar outra vez?\n");
      myPlayer.draw();
      graph::swapBuffers();
      pspDelay();

      if(PressXorC())
      {
        playAgain = true;
      }
      else
      {
        playAgain = false;
      }
    }
    else 
    {
      playAgain = false;
      graph::swapBuffers();
      graph::clearKeep(20, WHITE);
      pspDebugScreenPrintf("Boa! Conseguimos uma boa Tinder run! \n");
      myPlayer.draw();
      graph::swapBuffers();
      pspDelay();
      PressX();
    }
  }

  if(victory <0)
  {
    sceKernelExitGame();
  }

  State08(myPlayer);
  sceKernelExitGame();	
}
