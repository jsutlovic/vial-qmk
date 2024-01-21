#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL_L 1
#define _FL_W 2
#define _FL_M 3
#define _GAME 4
#define _RGB  5

#define SPCFN LT(_FL_L, KC_SPC)

#define OS_COUNT 3
#define OS_LENGTH 10
#define OS_LINUX 1
#define OS_WIN 2
#define OS_MAC 3
#define OS_SWITCH_FLASH_DELAY 200

#define SPACE_ROW 4
#define SPACE_COL 5
#define SPACE_LED 0x3D
#define CAPS_LED 8
#define LGUI_LED 0x3B
#define RGUI_LED 0x3F

#define OS_LAYER() ((uint8_t) (dynamic_keymap_get_keycode(_BL, 4, 5) >> 8) & 0xF)

// Macro defns
enum {
    TB_PREV = SAFE_RANGE,
    TB_NEXT,
    SP_PREV,
    SP_NEXT,
    WN_PREV,
    WN_NEXT,
    OS_CYCL,
    OS_PRNT,
    OS_PRNTL,
    J_DBG,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |Ent |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|Play|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |       SpaceFn         |Alt|Win|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_65_ansi(
  KC_GRAVE,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,   KC_BSPC, KC_ESC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  KC_LCTL,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,        KC_ENT,  KC_PENT, \
  KC_LSFT,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,     KC_RSFT,KC_UP,  KC_MPLY, \
  KC_LCTL, KC_LGUI,KC_LALT,                     SPCFN,                      KC_RALT,KC_RGUI, KC_NO ,KC_LEFT,KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer (Common)
   * ,----------------------------------------------------------------.
   * |Esc|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Prnt|
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |PgU|   |Sp<|Tb<|Tb>|Sp>|Wn<|Wn>|     |Ins |
   * |----------------------------------------------------------------|
   * |      |SA+|SA-|   |   |PgD| < | v | ^ | > |   | ` |        |End |
   * |----------------------------------------------------------------|
   * |        |HUE|MOD|BR-|RGB|BR+|Spc|MUT|VO-|VO+|   |     |Cycl|    |
   * |----------------------------------------------------------------|
   * |RESET|REEP|    |                      |DBG|   |   |Prev|Prt|Next|
   * `----------------------------------------------------------------'
   */
[_FL_L] = LAYOUT_65_ansi(
  KC_ESC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7, KC_F8 , KC_F9 , KC_F10 ,KC_F11,KC_F12,   KC_DEL ,OS_PRNT,  \
  _______,_______,_______,_______,_______,_______,KC_PGUP,USER01,USER03,USER04,USER02,USER05,USER06, TO(_BL), KC_INS, \
  _______   ,RGB_SAI,RGB_SAD,_______,_______,KC_PGDN,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______, KC_GRV,        _______, KC_END, \
  _______     ,RGB_HUI,RGB_MOD,RGB_VAD,RGB_TOG,RGB_VAI, KC_SPC,KC_MUTE,KC_VOLD,KC_VOLU,_______,     _______, USER00, _______, \
  _______,EEP_RST,_______,                _______                       ,     J_DBG,_______, RESET ,KC_MPRV,OS_PRNTL, KC_MNXT
),

[_FL_W] = LAYOUT_65_ansi(
  KC_ESC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7, KC_F8 , KC_F9 , KC_F10 ,KC_F11,KC_F12,   KC_DEL ,OS_PRNT,  \
  _______,_______,_______,_______,_______,_______,KC_PGUP,USER01,USER03,USER04,USER02,USER05,USER06, TO(_BL), KC_INS, \
  _______   ,RGB_SAI,RGB_SAD,_______,_______,KC_PGDN,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______, KC_GRV,        _______, KC_END, \
  _______     ,RGB_HUI,RGB_MOD,RGB_VAD,RGB_TOG,RGB_VAI, KC_SPC,KC_MUTE,KC_VOLD,KC_VOLU,_______,     _______, USER00, _______, \
  _______,EEP_RST,_______,                _______                       ,     J_DBG,_______, RESET ,KC_MPRV,OS_PRNTL, KC_MNXT
),

[_FL_M] = LAYOUT_65_ansi(
  KC_ESC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7, KC_F8 , KC_F9 , KC_F10 ,KC_F11,KC_F12,   KC_DEL ,OS_PRNT,  \
  _______,_______,_______,_______,_______,_______,KC_PGUP,USER01,USER03,USER04,USER02,USER05,USER06, TO(_BL), KC_INS, \
  _______   ,RGB_SAI,RGB_SAD,_______,_______,KC_PGDN,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______, KC_GRV,        _______, KC_END, \
  _______     ,RGB_HUI,RGB_MOD,RGB_VAD,RGB_TOG,RGB_VAI, KC_SPC,KC_MUTE,KC_VOLD,KC_VOLU,_______,     _______, USER00, _______, \
  _______,EEP_RST,_______,                _______                       ,     J_DBG,_______, RESET ,KC_MPRV,OS_PRNTL, KC_MNXT
),


  /* Keymap _GAME: (Base Layer) Game Layer - no SpaceFn
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |Ent |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|Play|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt|Win|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_GAME] = LAYOUT_65_ansi(
  KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,   KC_BSPC, KC_ESC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  KC_LCTL,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,        KC_ENT,  KC_PENT, \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,KC_SLSH,    KC_RSFT,KC_UP,  KC_MPLY, \
  KC_LCTL, KC_LGUI,KC_LALT,                      KC_SPC,                    KC_RALT,KC_RGUI,KC_RCTRL,KC_LEFT,KC_DOWN, KC_RGHT),

    [_RGB] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),
    [6] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),
    [7] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    )
};


static unsigned char os_layer = 0;
static char os_names[OS_COUNT][OS_LENGTH] = {
    "Linux",
    "Windows",
    "macOS",
};
char rgb_debug_str[24];

typedef union {
    uint32_t raw;
    struct {
        unsigned char current_os :3;
    };
} user_config_t;

user_config_t user_config;

void rgb_matrix_indicators_user(void)
{
    if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK))
    {
        rgb_matrix_set_color(CAPS_LED, 0xFF, 0xFF, 0xFF);
    }

    if (!rgb_matrix_get_suspend_state() && rgb_matrix_is_enabled()) {

        uint8_t current_layer = OS_LAYER();
        switch (current_layer) {
            case _FL_L:
                rgb_matrix_set_color(SPACE_LED, 3,6,7);
                break;
            case _FL_W:
                rgb_matrix_set_color(SPACE_LED, 0,5,7);
                break;
            case _FL_M:
                rgb_matrix_set_color(SPACE_LED, 7,3,7);
                break;
            default:
                // Error
                rgb_matrix_set_color(SPACE_LED, 10,0,0);
                break;
        }

        switch (biton32(layer_state)) {
            // This needs to be rewritten to check what SpaceFn is set to
            /*
            case _BL:
            case _FL:
                switch (os_layer) {
                    case OS_LINUX:
                        rgb_matrix_set_color(35, 3,6,7);
                        break;
                    case OS_WIN:
                        rgb_matrix_set_color(35, 0,5,7);
                        break;
                    case OS_MAC:
                        rgb_matrix_set_color(35, 7,3,7);
                        break;
                    default:
                        // Error
                        rgb_matrix_set_color(35, 10,0,0);
                        break;
                }
                break;
            */
            case _GAME:
                rgb_matrix_set_color(LGUI_LED, 10,0,0);
                rgb_matrix_set_color(RGUI_LED, 10,0,0);
                break;
        }
    }
}

/*
void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    os_layer = user_config.current_os;
}

void eeconfig_init_user(void) {
    // EEPROM has been reset, set defaults here
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(136, 96, 52);
    rgb_matrix_sethsv_noeeprom(136, 255, 20);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    user_config.current_os = 0;
}
*/

void flash_backlight(void) {
    uint8_t mode = rgb_matrix_config.mode;
    if (mode == RGB_MATRIX_NONE) {
        rgb_matrix_sethsv_noeeprom(0,0,255);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    } else {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
    }
    wait_ms(OS_SWITCH_FLASH_DELAY);
    rgb_matrix_mode_noeeprom(mode);
}

/*
// Combos
enum combo_events {
    BL_SWITCH,
};

const uint16_t PROGMEM switch_combo[] = {KC_LGUI, KC_RGUI, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [BL_SWITCH] = COMBO_ACTION(switch_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
    if (!pressed) return;
    switch(combo_index) {
        case BL_SWITCH:
            if (layer_state_is(_GAME)) {
                layer_clear();
            } else {
                layer_move(_GAME);
            }
            // flash_backlight();
            break;
    }
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    os_layer = OS_LAYER();

    switch (keycode) {
        case SP_PREV:
        case USER01:
            switch (os_layer) {
                case OS_LINUX:
                    SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_H))));
                    break;
                case OS_MAC:
                    SEND_STRING(SS_LCTRL(SS_TAP(X_LEFT)));
                    break;
                case OS_WIN:
                    SEND_STRING(SS_LGUI(SS_LCTRL(SS_TAP(X_LEFT))));
                    break;
            }
            break;
        case SP_NEXT:
        case USER02:
            switch (os_layer) {
                case OS_LINUX:
                    SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_L))));
                    break;
                case OS_MAC:
                    SEND_STRING(SS_LCTRL(SS_TAP(X_RIGHT)));
                    break;
                case OS_WIN:
                    SEND_STRING(SS_LGUI(SS_LCTRL(SS_TAP(X_RIGHT))));
                    break;
            }
            break;
        case TB_PREV:
        case USER03:
            switch (os_layer) {
                case OS_LINUX:
                case OS_WIN:
                    SEND_STRING(SS_LCTRL(SS_TAP(X_PGUP)));
                    break;
                case OS_MAC:
                    SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_LBRACKET))));
                    break;
            }
            break;
        case TB_NEXT:
        case USER04:
            switch (os_layer) {
                case OS_LINUX:
                case OS_WIN:
                    SEND_STRING(SS_LCTRL(SS_TAP(X_PGDOWN)));
                    break;
                case OS_MAC:
                    SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_RBRACKET))));
                    break;
            }
            break;
        case WN_PREV:
        case USER05:
            switch (os_layer) {
                case OS_LINUX:
                    SEND_STRING(SS_LGUI(SS_TAP(X_H)));
                    break;
                case OS_WIN:
                    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_TAB))));
                    break;
            }
            break;
        case WN_NEXT:
        case USER06:
            switch (os_layer) {
                case OS_LINUX:
                    SEND_STRING(SS_LGUI(SS_TAP(X_L)));
                    break;
                case OS_WIN:
                    SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                    break;
            }
            break;
        case OS_CYCL:
        case USER00:
            if (record->event.pressed) {
                os_layer++;
                if (os_layer > _FL_M) os_layer = _FL_L;
#if defined(VIA_ENABLE)
                dynamic_keymap_set_keycode(_BL, SPACE_ROW, SPACE_COL, LT(os_layer, KC_SPC));
                layer_move(_BL);
                clear_keyboard_but_mods();
#else
                user_config.current_os = os_layer;
                eeconfig_update_user(user_config.raw);
                flash_backlight();
#endif
            }
            return false;
            break;
        case OS_PRNT:
            if (record->event.pressed) {
                send_string((char[]) {'0' + os_layer, '\0'});
            }
            return false;
            break;
        case OS_PRNTL:
            if (record->event.pressed) {
                if (os_layer > OS_COUNT) {
                    send_string("Error!");
                } else {
                    send_string(os_names[os_layer-1]);
                }
            }
            return false;
            break;
        case J_DBG:
            if (record->event.pressed) {
                /*
                // RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);
                uprintf("{H:%d S:%d V:%d} ",
                        rgb_matrix_config.hsv.h,
                        rgb_matrix_config.hsv.s,
                        rgb_matrix_config.hsv.v);
                uprintf("{R:%d G:%d B:%d} ",
                        rgb.r, rgb.g, rgb.b);
                uprintf("M: %d ", rgb_matrix_config.mode);
                uprintf("OS: %d ", os_layer);
                uprintln();
                */
            }
            return false;
            break;
    }
    return true;
}
