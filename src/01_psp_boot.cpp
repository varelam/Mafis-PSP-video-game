#include "01_psp_boot.hpp"

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