#ifndef DREAMDISC_UI_H
#define DREAMDISC_UI_H

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


    const int     uitype;
    const char **items;
    Texture2D texture;
    int itemCount;
    int selectedItem;
    bool dropActive;

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
} uidropdown_t;



typedef union ui
{
    uidropdown_t* Drop;
    uibutton_t* Button;
    
} uielement_t;




#endif