// PSP includes
#include <pspkernel.h>
#include <pspdebug.h>
// #include <>

// Load Module
PSP_MODULE_INFO("PRENDAAA",0,1,0); // Version 1.0

// Home button Callback
int exitCallback(int arg1, int arg2, void *common)
{
  // Exit Game
  sceKernelExitGame();
  return 0;
}

// Callback Thread, sleeping until home button is pressed
int callbackThread(SceSize args, void *argp)
{
  int cbid = sceKernelCreateCallback("Exit Callback", exitCallback, nullptr);

  sceKernelRegisterExitCallback(cbid);

  sceKernelSleepThreadCB();

  return 0;
}

// Sets up Thread for callback
void setupCallbacks()
{

  int thid = sceKernelCreateThread("update thread", callbackThread, 0x11, 0xFA0,0, nullptr);
  if(thid >= 0)
  {
    sceKernelStartThread(thid,0,nullptr);
  }
}

auto main() -> int
{
  // Home button callback
  setupCallbacks();

  // Start Debug Screen
  pspDebugScreenInit();

  // Printf in Debug Sreen
  pspDebugScreenPrintf("Boas mpts bros\n");

  
}
