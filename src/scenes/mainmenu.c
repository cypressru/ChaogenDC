#include "raylib.h"
#include "raymath.h"
#include "../background.h"
#include "../scene.h"
#include "../controller.h"


#define MAX_TRIANGLES 8


void init_mainmenu_scene(){

}
void update_mainmenu_scene(){
 float fuckyou = Lerp(0.1f, 0.2f, 0.3f);
    UpdateController_MAINMENU();

}



void draw_mainmenu_scene(){
    

    draw_background();


}