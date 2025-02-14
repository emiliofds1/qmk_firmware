/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "waterfowl.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) { // Left roller
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    } else if (index == 1) { // Left encoder
        if (clockwise) {
          tap_code16(C(KC_Y));
        } else {
          tap_code16(C(KC_Z));
        }
    } else if (index == 2) { // Right roller
        if (clockwise) {
            tap_code16(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    } else if (index == 3) { // Right encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }

    return true;
}
#endif



#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}
bool oled_task_kb(void) {
   if (is_keyboard_master()) {
       // Host Keyboard Layer Status
       oled_write_P(PSTR("LAYER:\n"), false);
       oled_write_P(PSTR("\n"), false);

       switch (get_highest_layer(layer_state)) {
           case 0:
               oled_write_P(PSTR("DEFAULT\n\n\n\n"), false);
               break;
           case 1:
               oled_write_P(PSTR("SYMBOLS\n\n\n\n"), false);
               break;
           case 2:
               oled_write_P(PSTR("NAVIGATION\n\n\n\n"), false);
               break;
           case 3:
               oled_write_P(PSTR("FUNCTION\n\n\n\n"), false);
               break;
           case 4:
               oled_write_P(PSTR("GAME\n\n\n\n"), false);
               break;
           case 5:
               oled_write_P(PSTR("WOW\n\n\n\n"), false);
               break;
           case 6:
               oled_write_P(PSTR("WOW2\n\n\n\n"), false);
               break;
           default:
               oled_write_ln_P(PSTR("Undefined"), false);
       }
   } else {
        static const char PROGMEM wow_logo[] = {
            // Paste the code from the previous step below this line!
            // 'waterfowl for OLED', 64x128px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x00,
        	0x00, 0x10, 0x01, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x18, 0x03, 0xff, 0xff, 0x80, 0x30, 0x00,
        	0x00, 0x1c, 0x07, 0xff, 0xff, 0xc0, 0x70, 0x00, 0x00, 0x1e, 0x0f, 0xff, 0xff, 0xe1, 0xf0, 0x00,
        	0x00, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
        	0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
        	0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
        	0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00,
        	0x00, 0x3f, 0xff, 0xf8, 0x7f, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xe0, 0x1f, 0xff, 0xf8, 0x00,
        	0x00, 0x7f, 0xff, 0xc0, 0x0f, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x03, 0xff, 0xfc, 0x00,
        	0x00, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0xff, 0xfe, 0x00,
        	0x01, 0xff, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x3f, 0xff, 0x80,
        	0x03, 0xff, 0xf0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0xc0,
        	0x07, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xff, 0xe0,
        	0x1f, 0xff, 0xc0, 0x01, 0x00, 0x07, 0xff, 0xf0, 0x1f, 0xff, 0x80, 0x03, 0x80, 0x07, 0xff, 0xf0,
        	0x3f, 0xff, 0x80, 0x03, 0xc0, 0x07, 0xff, 0xf8, 0x3f, 0xff, 0x80, 0x07, 0xc0, 0x07, 0xff, 0xfc,
        	0x7f, 0xff, 0x80, 0x0f, 0xe0, 0x03, 0xff, 0xfc, 0x7f, 0xff, 0x00, 0x1f, 0xf0, 0x03, 0xff, 0xf0,
        	0x0f, 0xff, 0x00, 0x1f, 0xf0, 0x03, 0xff, 0xe0, 0x03, 0xff, 0x00, 0x3f, 0xf8, 0x03, 0xff, 0x80,
        	0x01, 0xff, 0x00, 0x7f, 0xfc, 0x03, 0xff, 0x00, 0x00, 0xff, 0x00, 0x7f, 0xfc, 0x03, 0xfe, 0x00,
        	0x00, 0x7f, 0x00, 0xff, 0xfc, 0x03, 0xfc, 0x00, 0x00, 0x3f, 0x00, 0x7f, 0xfc, 0x03, 0xfc, 0x00,
        	0x00, 0x3f, 0x00, 0x7f, 0xfc, 0x03, 0xf8, 0x00, 0x00, 0x1f, 0x80, 0x7f, 0xf8, 0x03, 0xf8, 0x00,
        	0x00, 0x1f, 0x80, 0x3f, 0xf8, 0x03, 0xf0, 0x00, 0x00, 0x0f, 0x80, 0x3f, 0xf0, 0x03, 0xf0, 0x01,
        	0x40, 0x0f, 0x80, 0x1f, 0xf0, 0x03, 0xf0, 0x03, 0x60, 0x0f, 0x80, 0x1f, 0xf0, 0x07, 0xf0, 0x06,
        	0x78, 0x0f, 0xc0, 0x0f, 0xe0, 0x07, 0xe0, 0x0e, 0x3c, 0x0f, 0xc0, 0x0f, 0xe0, 0x07, 0xe0, 0x3e,
        	0x3f, 0x8f, 0xe0, 0x07, 0xc0, 0x07, 0xe0, 0x7c, 0x3f, 0xff, 0xe0, 0x07, 0xc0, 0x0f, 0xe1, 0xfc,
        	0x1f, 0xff, 0xe0, 0x03, 0x80, 0x0f, 0xff, 0xfc, 0x1f, 0xff, 0xf0, 0x03, 0x80, 0x1f, 0xff, 0xf8,
        	0x1f, 0xff, 0xf8, 0x01, 0x80, 0x1f, 0xff, 0xf8, 0x0f, 0xff, 0xf8, 0x01, 0x00, 0x3f, 0xff, 0xf0,
        	0x0f, 0xff, 0xfc, 0x00, 0x00, 0x3f, 0xff, 0xf0, 0x07, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0xf0,
        	0x07, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xe0,
        	0x03, 0xf8, 0x7f, 0x00, 0x01, 0xfe, 0x3f, 0xc0, 0x01, 0xf0, 0x3f, 0x00, 0x01, 0xfc, 0x1f, 0xc0,
        	0x00, 0xe0, 0x3f, 0x00, 0x03, 0xfc, 0x0f, 0x80, 0x00, 0x40, 0x1f, 0x80, 0x03, 0xf8, 0x07, 0x80,
        	0x00, 0x00, 0x1f, 0x80, 0x03, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x03, 0xf0, 0x03, 0x00,
        	0x00, 0x00, 0x0f, 0xc0, 0x07, 0xf0, 0x02, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x07, 0xe0, 0x00, 0x00,
        	0x00, 0x00, 0x07, 0xc0, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x07, 0xc0, 0x00, 0x00,
        	0x00, 0x00, 0x07, 0xe0, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x07, 0xc0, 0x00, 0x00,
        	0x00, 0x00, 0x03, 0xe0, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x07, 0x80, 0x00, 0x00,
        	0x00, 0x00, 0x03, 0xe0, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x07, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x03, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x07, 0x00, 0x00, 0x00,
        	0x00, 0x02, 0x03, 0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0xf0, 0x07, 0x00, 0x00, 0x00,
        	0x00, 0x01, 0xe7, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x0f, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0xff, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf8, 0x0e, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0xff, 0xf8, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x0e, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x7f, 0xf8, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x0e, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x3f, 0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x0f, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x3f, 0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x0f, 0x80, 0x00, 0x00,
        	0x00, 0x00, 0x1f, 0xf8, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x0f, 0xc0, 0x00, 0x00,
        	0x00, 0x00, 0x0f, 0xf0, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x0f, 0xfc, 0x00, 0x00,
        	0x00, 0x00, 0x07, 0xf0, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf0, 0x00, 0x00,
        	0x00, 0x00, 0x03, 0xe0, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x0f, 0xe0, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0xe0, 0x0f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x0f, 0xc0, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x40, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
        	0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
                };

        static const char PROGMEM my_logo[] = {
                // Paste the code from the previous step below this line!
                // 'waterfowl for OLED', 64x128px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x80, 0xc0, 0x40, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x80, 0xc0, 0x40, 0x20, 0x10, 0x10, 0x08, 0x0c, 0x04, 0x04, 0x02, 0x02, 0x02, 0x01,
            0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x1a, 0x26, 0x40,
            0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0,
            0x1c, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x1e, 0x16, 0x1c, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x0c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xfc, 0xff,
            0x78, 0xf8, 0xfc, 0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xfc,
            0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x1e, 0x1c, 0x1c, 0x14, 0x10, 0x10, 0x08, 0x08, 0x10, 0x10,
            0x10, 0x10, 0x10, 0x30, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x38, 0x7c, 0x7e, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x03,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0xc0, 0x38, 0x0e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38,
            0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x3c, 0x03, 0x80,
            0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x7f, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x04, 0x0c, 0x0c, 0x0c, 0x04, 0x07, 0x02, 0x03, 0x01,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x02, 0x06, 0x06, 0x06,
            0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                    };

        switch (get_highest_layer(layer_state)) {
            case 5:
                oled_write_P(wow_logo, false);
                break;
            case 6:
                oled_write_P(wow_logo, false);
                break;
            default:
                oled_write_P(my_logo, false);
        }
   }
    return true;
}
#endif
