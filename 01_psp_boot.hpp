#include <pspkernel.h>
#include <pspdebug.h>

// Home button Callback
int exitCallback(int arg1, int arg2, void *common);
int callbackThread(SceSize args, void *argp);
void setupCallbacks();