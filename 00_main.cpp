// PSP includes
#include <pspkernel.h>
#include <pspdebug.h>

// Load Module
PSP_MODULE_INFO("PRENDAAA",0,1,0); // Version 1.0

// C++ includes
#include <unistd.h> // sleep

// Project
#include "mafis.hpp"
#include "graph.hpp"
#include "01_psp_boot.hpp"
#include "02_start.hpp"
#include "03_intro.hpp"


auto main() -> int
{
  // Home button callback
  setupCallbacks();

  // Start Debug Screen
  pspDebugScreenInit();

  // Start of the game print
  // State02();
  
  // Screen begins, lots of pink
  graph::init();
  State03();

  return 0;
}
