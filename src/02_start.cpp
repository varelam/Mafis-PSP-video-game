#include "02_start.hpp"

void State02()
{
    // Printf in Debug Sreen
    pspDebugScreenPrintf("Boas Mafis...\n\n");

    // Delay a bit for suspanse
    sleep(3);

    pspDebugScreenPrintf("Preparei um pequeno jogo para ti, \nnao podes simplesmente 'ter' uma prenda ...\n\n");
    sleep(3);

    pspDebugScreenPrintf("Imagina, receber prendas do namorado sem dar nada em troca...\n\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("RUDE\n\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Espero que te divirtas, pois eu vou divertir-me muito...\n\n");
    sleep(3);

    pspDebugScreenPrintf("MUAHAHAHAHAHAH!\n\n");
    sleep(3);

    pspDebugScreenPrintf("Bem, ate jaaaaaaaaaaaaaaa\n\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("(Prime x para avançar tho...)\n\n");

    // Initiate controls
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    SceCtrlData ctrlData;

    bool b_exit = false;

    while(!b_exit)
    {
        // Read buttons
        sceCtrlReadBufferPositive(&ctrlData, 1);

        // Select cross
        if(ctrlData.Buttons & PSP_CTRL_CROSS)
        {
            b_exit = true;
        }
    }

    pspDebugScreenClear();
    return;
}