#ifndef CHAOGEN_SCENE_H
#define CHAOGEN_SCENE_H


typedef enum Scene { MAINMENU, SA1, SA2 } scene_t;

void change_screen(scene_t scene);
void update_current_scene(void);
void draw_current_scene(void);


#endif