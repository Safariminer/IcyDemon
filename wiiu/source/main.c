#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>

#include <coreinit/screen.h>
#include <coreinit/thread.h>
#include <coreinit/time.h>
#include <coreinit/cache.h>
#include <whb/log_cafe.h>
#include <whb/log_udp.h>
#include <whb/log.h>
#include <whb/proc.h>
#include <stdlib.h>
#include <vpad/input.h>
#include <string.h>

#include "Icy_Menu.h"



int main(int argc, char** argv) {
    
    WHBLogCafeInit();
    WHBLogUdpInit();
    WHBLogPrint("Hello World! Logging initialised.");
    WHBProcInit();

    OSScreenInit();

    size_t tvBufferSize = OSScreenGetBufferSizeEx(SCREEN_TV);
    size_t drcBufferSize = OSScreenGetBufferSizeEx(SCREEN_DRC);
    WHBLogPrintf("Will allocate 0x%X bytes for the TV, " \
        "and 0x%X bytes for the DRC.",
        tvBufferSize, drcBufferSize);

    void* tvBuffer = memalign(0x100, tvBufferSize);
    void* drcBuffer = memalign(0x100, drcBufferSize);

    if (!tvBuffer || !drcBuffer) {
        WHBLogPrint("Out of memory!");

        if (tvBuffer) free(tvBuffer);
        if (drcBuffer) free(drcBuffer);

        OSScreenShutdown();
        WHBProcShutdown();

        WHBLogPrint("Quitting.");
        WHBLogCafeDeinit();
        WHBLogUdpDeinit();
        return 1;
    }

    OSScreenSetBufferEx(SCREEN_TV, tvBuffer);
    OSScreenSetBufferEx(SCREEN_DRC, drcBuffer);

    OSScreenEnableEx(SCREEN_TV, true);
    OSScreenEnableEx(SCREEN_DRC, true);
    VPADStatus status;
    VPADReadError error;
    int displaySplashScreen = 1;
    int displayer = -1;

    while (WHBProcIsRunning()) {
        OSScreenClearBufferEx(SCREEN_TV, 0x00000000);
        OSScreenClearBufferEx(SCREEN_DRC, 0x00000000);
        if(displaySplashScreen == 1){
        OSScreenPutFontEx(SCREEN_TV, 0, 0, "ICY DEMON GAME ENGINE");
        OSScreenPutFontEx(SCREEN_TV, 0, 1, "CODED BY SAFARIMINER");
        OSScreenPutFontEx(SCREEN_TV, 0, 3, "Check DRC for tech infos.");
        OSScreenPutFontEx(SCREEN_TV, 0, 6, "ICYDEMON V.1.0.0 alpha");
        OSScreenPutFontEx(SCREEN_TV, 0, 7, "Made by Safariminer in 2021");
        OSScreenPutFontEx(SCREEN_TV, 0, 8, "IcyDemon is a game engine made and designed for homebrew on the Wii U.");
        OSScreenPutFontEx(SCREEN_TV, 0, 9, "For more infos, visit 'fairlyoutdated.rf.gd/icy'");
        OSScreenPutFontEx(SCREEN_TV, 0, 11, "This splashscreen is present on games made with ICYDEMON, but can be removed");
        OSScreenPutFontEx(SCREEN_TV, 0, 12, "by changing options in the editor(coming soon) or by modifying the source ");
        OSScreenPutFontEx(SCREEN_TV, 0, 13, "code of the game engine on Github.");

        OSScreenPutFontEx(SCREEN_DRC, 0, 0, "ICY DEMON GAME ENGINE");
        OSScreenPutFontEx(SCREEN_DRC, 0, 1, "CODED BY SAFARIMINER");
        OSScreenPutFontEx(SCREEN_DRC, 0, 3, "Check TV for general infos.");
        OSScreenPutFontEx(SCREEN_DRC, 0, 6, "Running version V.1.0.0.0.102 alpha(pre-release)");
        OSScreenPutFontEx(SCREEN_DRC, 0, 7, "Engine made in C.");
        OSScreenPutFontEx(SCREEN_DRC, 0, 9, "For more infos, visit 'fairlyoutdated.rf.gd/icy'");
        OSScreenPutFontEx(SCREEN_DRC, 0, 11, "This splashscreen is present on games made with ICYDEMON, but can be removed");
        OSScreenPutFontEx(SCREEN_DRC, 0, 12, "by changing options in the editor(coming soon) or by modifying the source ");
        OSScreenPutFontEx(SCREEN_DRC, 0, 13, "code of the game engine on Github.");

        // Icy_Error(2);

        DCFlushRange(tvBuffer, tvBufferSize);
        DCFlushRange(drcBuffer, drcBufferSize);

        OSScreenFlipBuffersEx(SCREEN_TV);
        OSScreenFlipBuffersEx(SCREEN_DRC);

        OSSleepTicks(OSMillisecondsToTicks(5000));
        displaySplashScreen = 0;
         }

         if(displayer == -1){
        Icy_initmenu("ICYDEMON TECH DEMO");   

        DCFlushRange(tvBuffer, tvBufferSize);
        DCFlushRange(drcBuffer, drcBufferSize);

        OSScreenFlipBuffersEx(SCREEN_TV);
        OSScreenFlipBuffersEx(SCREEN_DRC);
        if (status.hold & VPAD_BUTTON_A) {
            displaySplashScreen = 1;
}
        }
        


    }

    WHBLogPrint("Got shutdown request!");

    /*  It's vital to free everything - under certain circumstances, your memory
        allocations can stay allocated even after you quit. */
    if (tvBuffer) free(tvBuffer);
    if (drcBuffer) free(drcBuffer);

    /*  Deinit everything */
    OSScreenShutdown();
    WHBProcShutdown();

    WHBLogPrint("Quitting.");
    WHBLogCafeDeinit();
    WHBLogUdpDeinit();

    /*  Your exit code doesn't really matter, though that may be changed in
        future. Don't use -3, that's reserved for HBL. */
    return 1;
}