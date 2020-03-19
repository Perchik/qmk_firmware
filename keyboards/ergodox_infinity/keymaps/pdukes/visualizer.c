/*
Copyright 2017 Fred Sundvik

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "simple_visualizer.h"
#include "util.h"
#define L_BASE 0 /* Default Layer. */
#define L_SHRT 1 /* Shortcuts */
#define L_MDIA 2/* Numpad, Media & Mouse Keys. */
#define L_NUM 3 /* Numbers. */
#define L_FN 4 /* FN. */
// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    uint8_t layer = biton32(state->status.layer);

    switch (layer) {
        case L_MDIA:
            // green
            state->target_lcd_color = LCD_COLOR(85, 255, 128);
            state->layer_text       = "Mouse, Numpad";
            break;
        case L_NUM:
            // orange
            state->target_lcd_color = LCD_COLOR(28, 255, 230);
            state->layer_text       = "Home - numbers";
            break;
        case L_FN:
            // blue
            state->target_lcd_color = LCD_COLOR(149, 255, 192);
            state->layer_text       = "Fn v1.2";
            break;
        case L_SHRT:
            state->target_lcd_color = LCD_COLOR(60,100,100);
            state->layer_text = " Shortcuts";
            break;
        default:
            // orange
            state->target_lcd_color = LCD_COLOR(28, 255, 230);
            state->layer_text       = "Home";
            break;
    }
}
