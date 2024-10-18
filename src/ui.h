#ifndef CHAOGEN_UI_H
#define CHAOGEN_UI_H

#include <raylib.h>
#include <stdint.h>

#define MAX_COLUMNS 12
#define MAX_ROWS 3

typedef struct UIButton {
    const Vector2 pos;
    const Vector2 size;
    const uint8_t column; 
    const uint8_t row;
    const uint8_t layers;
    const char    *text;
    bool dropActive;
    int itemCount;
} uibutton_t;

void move_cursor(char direction);

bool do_button(uibutton_t button, bool is_active);



typedef struct DropdownMenu{
    Rectangle rect;
    const char **items;
    int itemCount;
    int selectedItem;
    bool active;
    Texture2D texture;
} DropdownMenu;

// change the texture based on what's selected
// maybe by changing a number on an array or sum

// typedef struct MenuButtons { 
//     UIButton type1;
//     DropdownMenu type2;
// } MenuButtons;

#endif