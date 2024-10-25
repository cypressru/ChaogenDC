
#include "scene.h"
#include "scenes/mainmenu.h"


scene_t current_scene;

void update_current_scene(void){
    static void(*update_scene_functions[])(void) = { [MAINMENU] = update_mainmenu_scene };     
    update_scene_functions[current_scene]();
};

void draw_current_scene(void){
    static void (*draw_scene_functions[])(void) = { [MAINMENU] = draw_mainmenu_scene };
    draw_scene_functions[current_scene]();
}