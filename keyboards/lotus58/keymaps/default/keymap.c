// Copyright 2022 Markus Knutsson (@TweetyDaBird)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

void keyboard_post_init_user(void) {
	autoshift_disable();
}

enum layers {
    _QWERTY,
    _NUM,
    _FN,
    _SYS,
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _FN, _NUM, _SYS);
}

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_NUMERIC,
    KC_FUNCTION,
	KC_SYSTEM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
//      											     				_______       _______
// .----------.----------.----------.----------.----------.----------. /       \     /       \ .----------.----------.----------.----------.----------.----------.
// |   Esc    |    1     |    2     |    3     |    4     |    5     |(  Media  )   (  Media  )|    6     |    7     |    8     |    9     |    0     |    -     |
      KC_ESC, 	 KC_1, 	    KC_2,      KC_3,	   KC_4,     KC_5,  	KC_MPLY,      KC_MPLY,    KC_6,  	 KC_7,   	KC_8,       KC_9,      KC_0,    KC_MINS,
// |----------+----------+----------+----------+----------+----------| \_______/     \_______/ |----------+----------+----------+----------+----------+----------|
// |   Tab    |    Q     |    W     |    E     |    R     |    T     |                         |    Y     |    U     |    I     |    O     |    P     |   [ (Å)  |
      KC_TAB, 	 KC_Q, 	    KC_W,      KC_E,      KC_R,      KC_T,                     		       KC_Y,     KC_U,      KC_I,      KC_O,       KC_P,    KC_LBRC,
// |----------+----------+----------+----------+----------+----------|                         |----------+----------+----------+----------+----------+----------|
// |  Capslk  |    A     |    S     |    D     |    F     |    G     |                         |    H     |    J     |    K     |    L     |  ; (Ö)   |   ' (Ä)  |
      KC_LCTL, 	 KC_A, 	    KC_S,       KC_D,      KC_F,    KC_G,                     			   KC_H, 	 KC_J,      KC_K,       KC_L,    KC_SCLN,   KC_QUOT,
// |----------+----------+----------+----------+----------+----------+-----------. .-----------+----------+----------+----------+----------+----------+----------|
// | <-  Ctrl |    Z     |    X     |    C     |    V     |    B     |   Down    | |    Up     |    N     |    M     |    ,     |    .     |    /     | Ctrl  -> |
	 KC_LSFT,     KC_Z,	    KC_X,      KC_C,      KC_V,       KC_B,     KC_DOWN,       KC_MPLY,      KC_N,	KC_M,       KC_COMM,   KC_DOT,    KC_SLSH, KC_RSFT,
// '----------'----------'----------+----------+----------+----------+-.---------' '---------.-+----------+----------+----------+----------'----------'----------'
//                                	|   Win    |   Lower  |   Alt    |/  Space  /   \  Enter  \|   AltGr  |  Raise   |   Bksp   |
//									|		   |	      |	         |  Shift  /     \  Shift  |          |          |          |
								      KC_LALT,   KC_LCTL,   KC_SPC,   MO(_FN),			MO(_NUM), KC_BSPC,   KC_ENT,    KC_LGUI
                                                                  //                                  '----------'----------'----------'--------'       '--------'----------'----------'----------'
),

//      											     				_______       _______
// .----------.----------.----------.----------.----------.----------. /       \     /       \ .----------.----------.----------.----------.----------.----------.
// |   Esc    |    1     |    2     |    3     |    4     |    5     |(  Media  )   (  Media  )|    6     |    7     |    8     |    9     |    0     |    -     |
// |----------+----------+----------+----------+----------+----------| \_______/     \_______/ |----------+----------+----------+----------+----------+----------|
// |   Tab    |    Q     |    W     |    E     |    R     |    T     |                         |    Y     |    U     |    I     |    O     |    P     |   [ (Å)  |
// |----------+----------+----------+----------+----------+----------|                         |----------+----------+----------+----------+----------+----------|
// |  Capslk  |    A     |    S     |    D     |    F     |    G     |                         |    H     |    J     |    K     |    L     |  ; (Ö)   |   ' (Ä)  |
// |----------+----------+----------+----------+----------+----------+-----------. .-----------+----------+----------+----------+----------+----------+----------|
// | <-  Ctrl |    Z     |    X     |    C     |    V     |    B     |   Down    | |    Up     |    N     |    M     |    ,     |    .     |    /     | Ctrl  -> |
// '----------'----------'----------+----------+----------+----------+-.---------' '---------.-+----------+----------+----------+----------'----------'----------'
//                                	|   Win    |   Lower  |   Alt    |/  Space  /   \  Enter  \|   AltGr  |  Raise   |   Bksp   |
//									|		   |	      |	         |  Shift  /     \  Shift  |          |          |          |
//                                  '----------'----------'----------'--------'       '--------'----------'----------'----------'


[_NUM] = LAYOUT(
_______,	XXXXXXX,	XXXXXXX,	KC_LBRC, 	KC_RBRC, 	KC_GRAVE, 	_______, 	_______,	KC_BSPC, 	KC_CALC, 	KC_ASTR, 	KC_PSLS, 	XXXXXXX, 	XXXXXXX,
_______,	XXXXXXX,	XXXXXXX, 	KC_LCBR, 	KC_RCBR, 	KC_EQL,                         	KC_PMNS,    KC_KP_7,    KC_KP_8,    KC_KP_9, 	XXXXXXX, 	XXXXXXX,
_______,	XXXXXXX, 	XXXXXXX, 	KC_LPRN, 	KC_RPRN, 	KC_PLUS,                         	KC_PPLS,    KC_KP_4,    KC_KP_5,    KC_KP_6, 	KC_KP_0, 	XXXXXXX,
_______,	XXXXXXX,	XXXXXXX, 	KC_LT, 		KC_GT,  	KC_BSLS, 	_______, 	_______,  	KC_KP_DOT,	KC_KP_1, 	KC_KP_2,    KC_KP_3, 	XXXXXXX, 	_______,
							_______, 	_______, 	_______, 	_______,				_______, 	_______, 	_______, 	_______ 
),

[_FN] = LAYOUT(
//      											     				_______       _______
// .----------.----------.----------.----------.----------.----------. /       \     /       \ .----------.----------.----------.----------.----------.----------.
// |   Esc    |    1     |    2     |    3     |    4     |    5     |(  Media  )   (  Media  )|    6     |    7     |    8     |    9     |    0     |    -     |
	  KC_F12,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     _______,      _______,    KC_F6,    KC_F7,      KC_F8,     KC_F9,    KC_F10,    KC_F11,
// |----------+----------+----------+----------+----------+----------| \_______/     \_______/ |----------+----------+----------+----------+----------+----------|
// |   Tab    |    Q     |    W     |    E     |    R     |    T     |                         |    Y     |    U     |    I     |    O     |    P     |   [ (Å)  |
     _______,   _______,   _______,   KC_UP,       _______,   _______,                             _______,   _______,   KC_PGUP,   _______,   _______,   _______,
// |----------+----------+----------+----------+----------+----------|                         |----------+----------+----------+----------+----------+----------|
// |  Capslk  |    A     |    S     |    D     |    F     |    G     |                         |    H     |    J     |    K     |    L     |  ; (Ö)   |   ' (Ä)  |
     _______,   _______,   KC_LEFT,    KC_DOWN,  KC_RIGHT,   _______,                             _______,   KC_HOME,   KC_PGDN,   KC_END,   _______,   _______,
// |----------+----------+----------+----------+----------+----------+-----------. .-----------+----------+----------+----------+----------+----------+----------|
// | <-  Ctrl |    Z     |    X     |    C     |    V     |    B     |   Down    | |    Up     |    N     |    M     |    ,     |    .     |    /     | Ctrl  -> |
     _______,   _______,   _______,   _______,   _______,   _______,    _______,      _______,   _______,   _______,   _______,   _______,   _______,   _______,
// '----------'----------'----------+----------+----------+----------+-.---------' '---------.-+----------+----------+----------+----------'----------'----------'
//                                	|   Win    |   Lower  |   Alt    |/  Space  /   \  Enter  \|   AltGr  |  Raise   |   Bksp   |
//									|		   |	      |	         |  Shift  /     \  Shift  |          |          |          |
            					      _______,   _______,   _______,  _______,         _______,  KC_DEL,   _______,   _______
//                                  '----------'----------'----------'--------'       '--------'----------'----------'----------'
),

[_SYS] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX ,  XXXXXXX, XXXXXXX, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_SAI, RGB_TOG,
  QK_BOOT, XXXXXXX, KC_QWERTY, XXXXXXX, XXXXXXX, KC_ASTG,                       XXXXXXX, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_SAD, RGB_M_P,
  QK_REBOOT, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_CAPS,                       XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_VAI, RGB_M_B,
  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_VAD, RGB_M_R,
								_______, _______, _______, _______,     _______, _______, _______, _______  \
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NUM] = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN] = { ENCODER_CCW_CW(KC_A, KC_B), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_SYS] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif



