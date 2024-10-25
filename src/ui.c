#include "ui.h"

uint8_t selected_column = 0;
uint8_t selected_row    = 0;
uint8_t selected_layer  = 0;

uint8_t row_count[MAX_COLUMNS] = {0};
uint8_t column_count[MAX_ROWS] = {0};

const Color ui_background_color      = { 1, 17, 35, 180 };
const Color ui_button_color          = { 1, 35, 69, 200 };
const Color ui_button_selected_color = { 230, 230, 230, 222 };

// Layer Atlas
// 0 is default
// 1 is yes or no

int uiClamp(int value, uint8_t *max){
    // min is never gonna be lower than 1 so we can just use 1 instead of min
    // todo: check if there's a better way to do this lmfao
    if (value < 1) return 1;
    if (value > *max) return *max;
};

void move_cursor(char direction) {
    if (selected_layer == 1){
        row_count[0] = 1;
        column_count[0] = 2;
    }
        switch (direction) {
        case 'L':
            selected_column--;
            uiClamp(selected_column, column_count);
            break;
        case 'R':
            selected_column++;
            uiClamp(selected_column, column_count);
            break;
        case 'U':
            selected_row--;
            uiClamp(selected_row, row_count);
            break;
        case 'D':
            selected_row++;
            uiClamp(selected_row, row_count);
            break;
        default:
            break;
    }
}





// static bool is_button_selected(uielement_t type){
//     switch(type){
//         case Drop
//     }
// };