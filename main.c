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

#include "src/scene.h"
#include "src/scenes/mainmenu.h"
#include "src/ui.h"

#define screenWidth 640
#define screenHeight 480

#define CHAO_DATA 0x3000

#define DEBUG_EXIT

void init(void) {
    InitWindow(screenWidth, screenHeight, "ChaoGenDC");
    SetTargetFPS(60);
}

void update(void) {
    #ifdef DEBUG_EXIT
    if(IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT) && IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){
        arch_exit();
    }
    #endif
    update_current_scene();
}

void draw(void) {
    BeginDrawing();
    draw_current_scene();
    EndDrawing();
}


int main(){
    init();
    while(1)
    {
        update();
        draw();
    };
    return 0;
}