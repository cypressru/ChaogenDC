
#include "scene.h"
#include "scenes/mainmenu.h"
#include "scenes/game.h"
#include "ui.h"




scene_t current_scene;

extern uint8_t selected_column;
extern uint8_t selected_row;
extern uint8_t selected_layer;
extern uint8_t row_count[];
extern uint8_t column_count[];



void change_scene(scene_t scene) {
    static const void (*init_scene_functions[])(void) = {  [MAINMENU] = init_mainmenu_scene,[GAME] = init_game_scene};

    for (int i = 0; i < MAX_COLUMNS; i++) {
        column_count[i] = 0;
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        row_count[i] = 0;
    }

    selected_column = 0;
    selected_row    = 0;
    selected_layer  = 0;

    //vmu_current_frame = 0;

    // switch (scene) {
    //     case GAME:
    //         if (current_scene == GAME) {
    //             start_timer(&save_popup_timer, 2.0f);
    //             thd_create(1, save_game_wrapper, NULL);
    //         }
    //         break;
    //     case MAINMENU:
    //         start_timer(&vmu_menu_text_update_cooldown, 0.5f); // First frame is longer to give the player time to look at the VMU
    //         vmu_menu_text_frame = 0;
    //         if (current_scene != LOADING && current_scene != CREDITS) {
    //             start_timer(&save_popup_timer, 2.0f);
    //             thd_create(1, save_game_wrapper, NULL);
    //         }
    //         if (current_scene == CREDITS) {
    //             unload_credits_images();
    //         }
    //     default:
    //         break;
    // }
    init_scene_functions[scene]();
    current_scene = scene;
}

void update_current_scene(void){
    static void(*update_scene_functions[])(void) = { [MAINMENU] = update_mainmenu_scene, [GAME] = update_game_scene };     
    update_scene_functions[current_scene]();
};

void draw_current_scene(void){
    static void (*draw_scene_functions[])(void) = { [MAINMENU] = draw_mainmenu_scene, [GAME] = draw_game_scene };
    draw_scene_functions[current_scene]();
}