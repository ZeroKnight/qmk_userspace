#define PERMISSIVE_HOLD

// Always send Escape if CTRL is pressed, e.g. for Task Manager
#define GRAVE_ESC_CTRL_OVERRIDE

// Turn off RGB when computer goes to sleep
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#endif // RGBLIGHT_ENABLE

// Change Command mode keys to LShift + RShift + LCtrl
// Makes it less likely to accidentally trigger this mode when using Space Cadet
#define IS_COMMAND() (get_mods() == (MOD_MASK_SHIFT | MOD_BIT(KC_LCTL)))

#ifdef CAPS_WORD_ENABLE
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#endif // CAPS_WORD_ENABLE
