#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#include <kos.h>
#include <kos/init.h>
#include <kos/thread.h>
#include <kos/dbgio.h>
#include <dc/sound/sound.h>
#include <dc/sound/sfxmgr.h>
#include <dc/maple.h>
#include <dc/maple/controller.h>
#include <dc/maple/vmu.h>
#include <arch/arch.h>

#include <raylib.h>
#include "src/save.h"
#include "src/scene.h"
#include "src/scenes/mainmenu.h"
#include "src/scenes/game.h"
#include "src/ui.h"
#include "src/controller.h"



#define screenWidth 640
#define screenHeight 480

#define CHAO_DATA 0x3000


#define DebugExit


void init(void) {
    InitWindow(screenWidth, screenHeight, "DREAMDISC");
    SetTargetFPS(60);
}

void update(void) {

    update_current_scene();
}

void draw(void) {
    BeginDrawing();
    draw_current_scene();

    EndDrawing();
}


int main(int argc, char **argv){
    init();
    for(; ;)
    {
        #ifdef DebugExit
        if(IsGamepadButtonDown(0, (GAMEPAD_BUTTON_MIDDLE_RIGHT))){
            arch_exit();
            
        };
        if(IsGamepadButtonDown(0, (GAMEPAD_BUTTON_RIGHT_FACE_UP))){
            isSaving = 1;
            
        };
        if(IsGamepadButtonReleased(0, (GAMEPAD_BUTTON_RIGHT_FACE_UP))){
            isSaving = 0;
            
        };
        #endif
        update();
        draw();
    };
    return 0;
}