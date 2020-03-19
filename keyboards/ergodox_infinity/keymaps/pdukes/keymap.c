#include QMK_KEYBOARD_H

#define L_BASE 0 /* Default Layer. */
#define L_SHRT 1 /* Shortcuts */
#define L_MDIA 2/* Numpad, Media & Mouse Keys. */
#define L_NUM 3 /* Numbers. */
#define L_FN 4 /* FN. */

// TODO: Add g4 button somewhere
// Implement these keycodes
enum custom_keycodes {
	SCN_SFA,    // screen  shift-A
	SCN_C,
	SCN_QOT, // Screen quotes
    SCN_CLN, // Screen colon
	SCN_ESC,
	CDR_G,  // Ctrl+/ g
	CDR_RT, // ctrl+/ r t  switch to test
	CDR_RI, // Ctrl+/ r i implemntation
	CDR_RS, // Ctrl+/ r s (Open in cs/)
	CDR_RB, // Ctrl+/ r b (BUILD)
	CDR_J,  // Ctrl+/ j  (fix imports)
	CDR_SS, // Ctrl+/ s s (sort lines)
	CDR_F, // Ctrl+Shft+f (format)
	P_G4, // g4
	P_HJJ // custom text, java/com/google/gws/plugins/horizon/jobs/
};
//Tap Dance Declarations
enum {
  TD_ESC = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCN_SFA:
            if (record->event.pressed) {
                // when keycode SCN_SFA is pressed
                SEND_STRING(SS_LCTL("a") SS_DELAY(150) SS_LSFT("a"));
            }
            break;

        case SCN_C:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(150) "c");
            }
            break;
        case SCN_QOT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(150) SS_TAP(X_QUOTE));
            }
            break;
        case SCN_CLN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(150) ":");
            }
            break;


        case SCN_ESC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_DELAY(150) SS_TAP(X_ESC));
            }
            break;
    //     case CDR_G:
    //         if (record->event.pressed) {
    //             SEND_STRING(SS_LCTL("/") SS_DELAY(150) "g");
    //         }
    //         break;
    //     case CDR_RT:
    //         if (record->event.pressed) {
    //             SEND_STRING(SS_LCTL("/") SS_DELAY(150) "r" SS_DELAY(150) "t");
    //         }
    //         break;
    //     case CDR_RI:
    //         if (record->event.pressed) {
    //             SEND_STRING(SS_LCTL("/") SS_DELAY(150) "r" SS_DELAY(150) "i");
    //         }
    //         break;
    // }
    //     case CDR_RS:
    //         if (record->event.pressed) {
    //             SEND_STRING(SS_LCTL("/") SS_DELAY(150) "r" SS_DELAY(150) "s");
    //         }
    //         break;
    //     case CDR_RB:
    //         if (record->event.pressed) {
    //             SEND_STRING(SS_LCTL("/") SS_DELAY(150) "r" SS_DELAY(150) "b");
    //         }
    //         break;
    //     case CDR_J:
    //         if (record->event.pressed) {
    //             SEND_STRING(SS_LCTL("/") SS_DELAY(150) "j");
    //         }
    //         break;
    //     case CDR_SS:
    //         if (record->event.pressed) {
    //             SEND_STRING(SS_LCTL("/") SS_DELAY(150) "g");
    //         }
    //         break;
    //     case CDR_F:
    //         if (record->event.pressed) {
    //             SEND_STRING(SS_LCTL("/") SS_DELAY(150) "g");
    //         }
    //         break;
        case P_G4:
            if (record->event.pressed) {
                SEND_STRING("g4");
            }
            break;
        case P_HJJ:
            if (record->event.pressed) {
                SEND_STRING("//java/com/google/gws/plugins/horizon/jobs/");
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_BASE] = LAYOUT_ergodox(
/**Left Hand */
KC_MINS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  OSL(L_FN),
KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_LCBR,
MO(L_NUM),KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_LBRC,
KC_LCTL,  KC_LGUI,  KC_LALT,  KC_GRV,   KC_APP,

                                                  TG(L_MDIA), KC_NO ,
                                                        	  MO(L_SHRT),
                                        KC_BSPC,  KC_DEL,     KC_LCTL,


/**Right Hand */
TD_ESC,   KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_EQL,
KC_RCBR,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
KC_RBRC,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
          KC_HOME,  KC_UP,    KC_DOWN,  KC_END,   KC_ENT,

KC_LEFT,  KC_RGHT,
KC_PGUP,
KC_PGDN,  KC_ENT,   KC_SPC),

[L_SHRT] = LAYOUT_ergodox(
/**Left Hand */
KC_NO,    P_HJJ,    KC_NO,    KC_3,     P_G4,      KC_NO,    KC_NO,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    CDR_RT,  KC_WSCH,
KC_NO,    SCN_SFA,  CDR_RS,   KC_NO,    CDR_F,    CDR_G,
KC_NO,    KC_NO,    KC_NO,    SCN_C,    KC_NO,    CDR_RB,   KC_NO,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,

                                                  KC_NO,    KC_TRNS,
                                                            KC_NO,
                                        KC_NO,    KC_NO,    KC_NO,

/**Right Hand */
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
KC_NO,    KC_NO,    KC_NO,    CDR_RI,   KC_NO,    KC_NO,    KC_NO,
KC_NO,    CDR_J,    KC_NO,    KC_NO,    SCN_CLN, SCN_QOT,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,

KC_NO,    KC_NO,
KC_NO,
KC_NO,    KC_NO,    KC_NO),

[L_NUM] = LAYOUT_ergodox(
/**Left Hand */
KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                  KC_TRNS,  KC_TRNS,
                                                            KC_TRNS,
                                        KC_TRNS,  KC_TRNS,  KC_TRNS,

/**Right Hand */
KC_TRNS,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

KC_TRNS,  KC_TRNS,
KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS),

[L_MDIA] = LAYOUT_ergodox(
/**Left Hand */
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
KC_NO,    KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_NO,    KC_NO,    BL_STEP,
KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,    KC_NO,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_SPC,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,

                                                  KC_TRNS,  KC_MUTE,
                                                            KC_VOLU,
                                        KC_MRWD,  KC_MFFD,  KC_VOLD,

/**Right Hand */
KC_NO,    KC_NO,    KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  KC_EQL,
BL_STEP,  KC_NO,    KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_NO,
KC_NO,    KC_P1,    KC_P2,    KC_P3,    KC_PCMM,  KC_PENT,
KC_BSPC,  KC_NO,    KC_P0,    KC_P0,    KC_PDOT,  KC_PEQL,  KC_NO,
          KC_LEFT,  KC_UP,    KC_DOWN,  KC_RGHT,  KC_NO,

KC_NO,    KC_BTN3,
KC_WH_U,
KC_WH_D,  KC_BTN1,  KC_BTN2),

[L_FN] = LAYOUT_ergodox(
/**Left Hand */
KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_NO,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    RESET,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,

                                                  KC_NO,    KC_NO,
                                                            KC_NO,
                                        KC_NO,    KC_NO,    KC_NO,

/**Right Hand */
KC_NO,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
RESET,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
          KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,

KC_NO,    KC_NO,
KC_NO,
KC_NO,    KC_NO,    KC_NO)
};
