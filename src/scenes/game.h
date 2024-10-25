#ifndef DREAMDISC_GAME_H
#define DREAMDISC_GAME_H

#include <raylib.h>
#include <stdint.h>

typedef struct TestThing {
    Rectangle rect;
    float rotation;
    int8_t speed;
    Vector2 origin;
    Color color;

} testhing_t;

extern void init_game_scene(void);
extern void update_game_scene(void);
extern void draw_game_scene(void);

extern testhing_t Test;


#endif