#define PERMISSIVE_HOLD

// Always send Escape if CTRL is pressed, e.g. for Task Manager
#define GRAVE_ESC_CTRL_OVERRIDE

// Turn off RGB when computer goes to sleep
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#endif // RGBLIGHT_ENABLE