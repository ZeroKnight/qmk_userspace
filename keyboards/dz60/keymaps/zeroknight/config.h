#define PERMISSIVE_HOLD

// Always send Escape if CTRL is pressed, e.g. for Task Manager
#define GRAVE_ESC_CTRL_OVERRIDE

#ifdef RGBLIGHT_ENABLE
// Default to solid color, desaturated Chartreuse Green
#define RGBLIGHT_DEFAULT_HUE 64
#define RGBLIGHT_DEFAULT_SAT 200
#define RGBLIGHT_DEFAULT_VAL 255

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_RETAIN_VAL

/* DZ60 underglow LEDs are ordered like a backward 'C'. In other words, the
 * bottom row is in reverse order.
 */
#define RGBLIGHT_LED_COUNT 16
#define RGBLIGHT_LED_MAP {0, 1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8}

// Turn off RGB when computer goes to sleep
#define RGBLIGHT_SLEEP
#endif // RGBLIGHT_ENABLE

// Change Command mode keys to LShift + RShift + LCtrl
// Makes it less likely to accidentally trigger this mode when using Space Cadet
#define IS_COMMAND() (get_mods() == (MOD_MASK_SHIFT | MOD_BIT(KC_LCTL)))

#ifdef CAPS_WORD_ENABLE
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#endif // CAPS_WORD_ENABLE
