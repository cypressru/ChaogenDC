#include "game.h"
#include "../controller.h"







testhing_t Test;

void UpdateTestThing(void){

    
}

void init_game_scene(){
    Test.rect = (Rectangle){200, 200, 50, 50};
    Test.rotation = 0.0f;
    Test.speed = 3;
    Test.origin = (Vector2){Test.rect.width / 2, Test.rect.height / 2};
    Test.color = RED;

}

void DrawTestThing(void){

    DrawRectanglePro(Test.rect, Test.origin, Test.rotation, Test.color);
    DrawRectanglePro(Test.rect, Test.origin, (Test.rotation + 45.0f), Test.color);
}





void update_game_scene(){
    //UpdateController_GAME();

    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)){
        Test.rect.x = (Test.rect.x - Test.speed);
        Test.rotation = (Test.rotation - Test.speed);
    }
    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)){
        Test.rect.x = (Test.rect.x + Test.speed);
        Test.rotation = (Test.rotation + Test.speed);
    }

    if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)){
        Test.color = (Test.color.r == RED.r) ? BLUE : RED;

    }


}



void draw_game_scene(){


    //draw_background();
    ClearBackground(BLACK);
    
    DrawTestThing();


}