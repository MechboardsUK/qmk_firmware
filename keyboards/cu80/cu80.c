/* Copyright 2019 Elliot Powell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
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
#include "cu80.h"
#include "config.h"
#include <print.h>
#include "is31fl3741.h"
#include "i2c_master.h"

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, K_12,   J_12,   L_12},
    {0, K_11,   J_11,   L_11},
    {0, K_10,   J_10,   L_10},
    {0, K_9,    J_9,    L_9},
    {0, K_8,    J_8,    L_8},
    {0, K_7,    J_7,    L_7},
    {0, K_6,    J_6,    L_6},
    {0, K_5,    J_5,    L_5},
    {0, K_4,    J_4,    L_4},
    {0, K_3,    J_3,    L_3},
    {0, K_2,    J_2,    L_2},
    {0, K_1,    J_1,    L_1},

    {0, K_13,   J_13,   L_13},
    {0, K_14,   J_14,   L_14},

    {0, H_12,   G_12,   I_12},
    {0, H_11,   G_11,   I_11},
    {0, H_10,   G_10,   I_10},
    {0, H_9,    G_9,    I_9},
    {0, H_8,    G_8,    I_8},
    {0, H_7,    G_7,    I_7},
    {0, H_6,    G_6,    I_6},
    {0, H_5,    G_5,    I_5},
    {0, H_4,    G_4,    I_4},
    {0, H_3,    G_3,    I_3},
    {0, H_2,    G_2,    I_2},
    {0, H_1,    G_1,    I_1},

    {0, H_13,   G_13,   I_13},
    {0, H_14,   G_14,   I_14},

    {0, E_12,   D_12,   F_12},
    {0, E_11,   D_11,   F_11},
    {0, E_10,   D_10,   F_10},
    {0, E_9,    D_9,    F_9},
    {0, E_8,    D_8,    F_8},
    {0, E_7,    D_7,    F_7},
    {0, E_6,    D_6,    F_6},
    {0, E_5,    D_5,    F_5},
    {0, E_4,    D_4,    F_4},
    {0, E_3,    D_3,    F_3},
    {0, E_2,    D_2,    F_2},
    {0, E_1,    D_1,    F_1},

    {0, E_13,   D_13,   F_13},
    {0, E_14,   D_14,   F_14},

    {0, B_12,   A_12,   C_12},
    {0, B_11,   A_11,   C_11},
    {0, B_10,   A_10,   C_10},
    {0, B_9,    A_9,    C_9},
    {0, B_8,    A_8,    C_8},
    {0, B_7,    A_7,    C_7},
    {0, B_6,    A_6,    C_6},
    {0, B_5,    A_5,    C_5},
    {0, B_4,    A_4,    C_4},
    {0, B_3,    A_3,    C_3},
    {0, B_2,    A_2,    C_2},
    {0, B_1,    A_1,    C_1}

};

led_config_t g_led_config = { {
    {  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  15,  14, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
    {  39,  38,  37,  36,  35,  34,  33,  32,  31,  30,  29,  28, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {  53,  52,  51,  50,  49,  48,  47,  46,  45,  44,  43,  42, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
    {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED}
}, {
    { 223,   0 }, { 203,   0 }, { 183,   0 }, { 162,   0 }, { 142,   0 }, { 122,   0 }, { 101,   0 }, {  81,   0 }, {  61,   0 }, {  40,   0 }, {  20,   0 }, {   0,   0 },
    { 223,  10 }, {   0,  10 }, { 223,  21 }, { 203,  21 }, { 183,  21 }, { 162,  21 }, { 142,  21 }, { 122,  21 }, { 101,  21 }, {  81,  21 }, {  61,  21 }, {  40,  21 },
    {  20,  21 }, {   0,  21 }, { 223,  31 }, {   0,  31 }, { 223,  42 }, { 203,  42 }, { 183,  42 }, { 162,  42 }, { 142,  42 }, { 122,  42 }, { 101,  42 }, {  81,  42 },
    {  61,  42 }, {  40,  42 }, {  20,  42 }, {   0,  42 }, { 223,  53 }, {   0,  53 }, { 223,  63 }, { 203,  63 }, { 183,  63 }, { 162,  63 }, { 142,  63 }, { 122,  63 },
    { 101,  63 }, {  81,  63 }, {  61,  63 }, {  40,  63 }, {  20,  63 }, {   0,  63 }
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    4, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1
} };

uint8_t data[8];

void matrix_init_kb(void) {
    i2c_init();
    if (i2c_readReg(0b1100001, 0xfc, data, 8, 100) == -2) {
        print("\nFAAAAAIIIIILLLLLEEEEEED\n");
    }else{
       print("woooooooo");
    }
    print("i2c user");
    IS31FL3741_init( DRIVER_ADDR_1, 0);
    matrix_init_user();
    print("test");
}
void matrix_scan_kb(void) {
    matrix_scan_user();
}
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    return process_record_user(keycode, record);
}
void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}



