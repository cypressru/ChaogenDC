#include "controller.h"
#include "scene.h"
#include "raylib.h"
#include "scenes/game.h"




void UpdateController_MAINMENU(){

        if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
        {
            change_scene(GAME);
        }


}

void UpdateController_GAME(){
    if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)){
        
    }


}