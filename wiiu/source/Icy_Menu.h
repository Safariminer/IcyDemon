// ################################
// #          ICY DEMON           #
// #     MENUS DISPLAY SYSTEM     #
// #          WRITTEN BY          #
// #          SAFARIMINER         #
// ################################

// Initializing basic stuff like malloc and WUT basic headers for printing text;
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

#include <coreinit/screen.h>
#include <coreinit/cache.h>
#include <whb/log_cafe.h>
#include <whb/log_udp.h>
#include <whb/log.h>
#include <whb/proc.h>

#include "Icy_err.h"


void Icy_initmenu(char gameTitle[]){

        if(gameTitle == ""){Icy_Error(3);}
        else{
        OSScreenPutFontEx(SCREEN_TV, 0, 0, gameTitle);
        OSScreenPutFontEx(SCREEN_TV, 0, 2, "Press:");
        OSScreenPutFontEx(SCREEN_TV, 0, 3, "A to play");
        OSScreenPutFontEx(SCREEN_TV, 0, 4, "HOME to quit to HBL");

        OSScreenPutFontEx(SCREEN_DRC, 0, 0, gameTitle);
        OSScreenPutFontEx(SCREEN_DRC, 0, 2, "Press:");
        OSScreenPutFontEx(SCREEN_DRC, 0, 3, "A to play");
        OSScreenPutFontEx(SCREEN_DRC, 0, 4, "HOME to quit to HBL");
        }
        
}