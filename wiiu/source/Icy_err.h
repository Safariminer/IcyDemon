// ################################
// #          ICY DEMON           #
// #     ERROR DISPLAY SYSTEM     #
// #          WRITTEN BY          #
// #          SAFARIMINER         #
// ################################

/*
Notes: DO NOT INCLUDE THIS FILE IN YOUR MAIN.C

*/

// Initializing basic stuff like malloc and WUT basic headers for printing text;
#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>

#include <coreinit/screen.h>
#include <coreinit/cache.h>
#include <whb/log_cafe.h>
#include <whb/log_udp.h>
#include <whb/log.h>
#include <whb/proc.h>

void Icy_Error(int errType){

    OSScreenPutFontEx(SCREEN_DRC, 0, 0, "ICY DEMON CRASH");
    
    
    switch(errType){
        case(1):
          OSScreenPutFontEx(SCREEN_DRC, 0, 1, "Error 1 : ");
          OSScreenPutFontEx(SCREEN_DRC, 0, 2, "The game you're trying to execute doesn't have any code.");
          OSScreenPutFontEx(SCREEN_DRC, 0, 3, "Please press the HOME button.");
          break;
        case(2):
          OSScreenPutFontEx(SCREEN_DRC, 0, 1, "Error 2 : ");
          OSScreenPutFontEx(SCREEN_DRC, 0, 2, "The game you're trying to execute doesn't exist.");
          OSScreenPutFontEx(SCREEN_DRC, 0, 3, "Please press the HOME button.");
          break;
        case(3):
          OSScreenPutFontEx(SCREEN_DRC, 0, 1, "Error 3 : ");
          OSScreenPutFontEx(SCREEN_DRC, 0, 2, "The game you're trying to execute is untitled.");
          OSScreenPutFontEx(SCREEN_DRC, 0, 3, "Try naming the game 'untitled' in the code.");
          OSScreenPutFontEx(SCREEN_DRC, 0, 4, "Please press the HOME button.");

    }
    
    
    
}