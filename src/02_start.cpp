#include "02_start.hpp"

void State02()
{
    // Printf in Debug Sreen
    pspDebugScreenPrintf("Boas Mafis...\n\n");

    // Delay a bit for suspanse
    sleep(3);

    pspDebugScreenPrintf("Preparei um pequeno jogo para ti, \nnao podes simplesmente 'ter' uma prenda ...\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Imagina, receber prendas do namorado sem dar nada em troca...\n\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("\t\t\t\t\tRUDE\n\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Conto contigo para passares este jogo, senao nao ha prenda...\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Espero que te divirtas, pois eu vou divertir-me muito...\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("\t\t\t\tMUAHAHAHAHAHAH!\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("Bem, ate jaaaaaaaaaaaaaaa\n\n\n\n");
    sleep(3);

    pspDebugScreenPrintf("(Prime x para continuar tho...\(\^\^ \"\))\n\n");

    

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