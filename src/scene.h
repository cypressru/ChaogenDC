#ifndef CHAOGEN_SCENE_H
#define CHAOGEN_SCENE_H


typedef enum Scene { MAINMENU, GAME } scene_t;

void change_scene(scene_t scene);
void update_current_scene(void);
void draw_current_scene(void);

extern scene_t current_scene;

#endif