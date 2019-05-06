#ifdef _WINDOW_CONFIG

/* default window dimensions (overwritten via -g option): */
enum {
	WIN_WIDTH  = 960,
	WIN_HEIGHT = 1080
};

/* bar font:
 * (see fonts-conf(5) subsection "FONT NAMES" for valid values)
 */
static const char * const BAR_FONT = "monospace:size=8";

/* colors:
 * overwritten by 'background' and 'foreground' X resource properties.
 * (see X(7) section "COLOR NAMES" for valid values)
 */
static const char * const BG_COLOR = "#555555";
static const char * const FG_COLOR = "#555555";

#endif
#ifdef _IMAGE_CONFIG

/* levels (in percent) to use when zooming via '-' and '+':
 * (first/last value is used as min/max zoom level)
 */
static const float zoom_levels[] = {
  3.0,   6.0,   9.0,  12.0,  15.0,  18.0,  21.0,  24.0,  27.0,  30.0,  33.0,  36.0,  39.0,  42.0,  45.0,  48.0,  51.0,  54.0,  57.0,  60.0,  63.0,  66.0,  69.0,  72.0,  75.0,  78.0,  81.0,  84.0,  87.0,  90.0,  93.0,  96.0,    
100.0, 110.0, 120.0, 130.0, 140.0, 150.0, 160.0, 170.0, 180.0, 190.0, 200.0, 210.0, 220.0, 230.0, 240.0, 250.0, 260.0, 270.0, 280.0, 290.0, 300.0, 310.0, 320.0, 330.0, 340.0, 350.0, 360.0, 370.0, 380.0, 390.0, 400.0,
};

/* default slideshow delay (in sec, overwritten via -S option): */
enum { SLIDESHOW_DELAY = 5 };

/* gamma correction: the user-visible ranges [-GAMMA_RANGE, 0] and
 * (0, GAMMA_RANGE] are mapped to the ranges [0, 1], and (1, GAMMA_MAX].
 * */
static const double GAMMA_MAX   = 10.0;
static const int    GAMMA_RANGE = 32;

/* command i_scroll pans image 1/PAN_FRACTION of screen width/height */
static const int PAN_FRACTION = 2;

/* if false, pixelate images at zoom level != 100%,
 * toggled with 'a' key binding
 */
static const bool ANTI_ALIAS = true;

/* if true, use a checkerboard background for alpha layer,
 * toggled with 'A' key binding
 */
static const bool ALPHA_LAYER = false;

#endif
#ifdef _THUMBS_CONFIG

/* thumbnail sizes in pixels (width == height): */
static const int thumb_sizes[] = { 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480, 512, 544, 576, 608, 640, 672, 704, 736, 768, 800, 832, 864, 896, 928, 960, 992, 1024, };

/* thumbnail size at startup, index into thumb_sizes[]: */
static const int THUMB_SIZE = 5;

#endif
#ifdef _MAPPINGS_CONFIG

/* keyboard mappings for image and thumbnail mode: */
static const keymap_t keys[] = {
	/* modifiers    key               function              argument */
	{ 0,            XK_q,             g_quit,               None },
	{ 0,            XK_Return,        g_switch_mode,        None },
	{ 0,            XK_f,             g_toggle_fullscreen,  None },
	{ 0,            XK_b,             g_toggle_bar,         None },
	{ ControlMask,  XK_x,             g_prefix_external,    None },
	{ 0,            XK_Home,          g_first,              None },
	{ 0,            XK_End,           g_n_or_last,          None },
	{ 0,            XK_r,             g_reload_image,       None },
	{ 0,            XK_D,             g_remove_image,       None },
	{ ControlMask,  XK_h,             g_scroll_screen,      DIR_LEFT },
	
	{ ControlMask,  XK_j,             g_scroll_screen,      DIR_DOWN },
	
	{ ControlMask,  XK_k,             g_scroll_screen,      DIR_UP },
	
	{ ControlMask,  XK_l,             g_scroll_screen,      DIR_RIGHT },
	
	{ 0,            XK_w,             g_zoom,               +1 },
	{ 0,            XK_Up,            g_zoom,               +1 },
	{ 0,            XK_s,             g_zoom,               -1 },
	{ 0,            XK_Down,          g_zoom,               -1 },
	{ 0,            XK_m,             g_toggle_image_mark,  None },
	{ 0,            XK_M,             g_mark_range,         None },
	{ ControlMask,  XK_m,             g_reverse_marks,      None },
	{ ControlMask,  XK_u,             g_unmark_all,         None },
	{ 0,            XK_N,             g_navigate_marked,    +1 },
	{ 0,            XK_P,             g_navigate_marked,    -1 },
	{ 0,            XK_KP_Home,        g_change_gamma,       -1 },
	{ 0,            XK_KP_Prior,      g_change_gamma,       +1 },
	{ 0,            XK_KP_Up,         g_change_gamma,        0 },

	{ 0,            XK_h,             t_move_sel,           DIR_LEFT },
	{ ShiftMask,    XK_Left,          t_move_sel,           DIR_LEFT },
	{ 0,            XK_j,             t_move_sel,           DIR_DOWN },
	{ ShiftMask,    XK_Down,          t_move_sel,           DIR_DOWN },
	{ 0,            XK_k,             t_move_sel,           DIR_UP },
	{ ShiftMask,    XK_Up,            t_move_sel,           DIR_UP },
	{ 0,            XK_l,             t_move_sel,           DIR_RIGHT },
	{ ShiftMask,    XK_Right,         t_move_sel,           DIR_RIGHT },
	{ 0,            XK_R,             t_reload_all,         None },

	{ 0,            XK_n,             i_navigate,           +1 },
	{ 0,            XK_n,             i_scroll_to_edge,     DIR_LEFT | DIR_UP },
	{ 0,            XK_Right,         i_navigate,           +1 },
	{ 0,            XK_Left,          i_navigate,           -1 },
	{ 0,            XK_p,             i_scroll_to_edge,     DIR_LEFT | DIR_UP },
	{ 0,            XK_BackSpace,     i_navigate,           -1 },
	{ 0,            XK_Next,          i_navigate,           +10 },
	{ 0,            XK_Prior,         i_navigate,           -10 },
	{ ControlMask,  XK_6,             i_alternate,          None },
	{ ControlMask,  XK_n,             i_navigate_frame,     +1 },
	{ ControlMask,  XK_p,             i_navigate_frame,     -1 },
	{ ControlMask,  XK_space,         i_toggle_animation,   None },
	{ 0,            XK_h,             i_scroll,             DIR_LEFT },
	{ ShiftMask,    XK_Left,          i_scroll,             DIR_LEFT },
	{ 0,            XK_j,             i_scroll,             DIR_DOWN },
	{ ShiftMask,    XK_Down,          i_scroll,             DIR_DOWN },
	{ 0,            XK_k,             i_scroll,             DIR_UP },
	{ ShiftMask,    XK_Up,            i_scroll,             DIR_UP },
	{ 0,            XK_l,             i_scroll,             DIR_RIGHT },
	{ ShiftMask,    XK_Right,         i_scroll,             DIR_RIGHT },
	{ 0,            XK_H,             i_scroll_to_edge,     DIR_LEFT },
	{ 0,            XK_J,             i_scroll_to_edge,     DIR_DOWN },
	{ 0,            XK_K,             i_scroll_to_edge,     DIR_UP },
	{ 0,            XK_L,             i_scroll_to_edge,     DIR_RIGHT },

	{ 0,            XK_KP_Enter,      i_fit_to_win,         SCALE_FIT },
	{ 0,            XK_KP_Add,        i_rotate,             DEGREE_90 },
	{ 0,            XK_KP_Insert,     i_flip,               FLIP_HORIZONTAL },
	{ 0,            XK_KP_Delete,     i_flip,               FLIP_VERTICAL },
	{ 0,            XK_a,             i_toggle_antialias,   None },
	{ 0,            XK_A,             i_toggle_alpha,       None },
	{ ControlMask,  XK_s,             i_slideshow,          None },
};

/* mouse button mappings for image mode: */
static const button_t buttons[] = {
	/* modifiers    button            function              argument */
	{ 0,            1,                i_cursor_navigate,    None },
	{ 0,            1,                i_drag,               DRAG_RELATIVE },
	{ ControlMask,  1,                i_drag,               DRAG_RELATIVE },
	{ 0,            2,                g_switch_mode,        None },
	{ 0,            4,                g_zoom,               +1 },
	{ 0,            5,                g_zoom,               -1 },
	{ ControlMask,  3,                i_flip,               FLIP_VERTICAL },
	{ 0,            3,                i_flip,               FLIP_HORIZONTAL },
        { 0,            8,                i_rotate,             DEGREE_90 },
	{ 0,            9,     		  i_fit_to_win,         SCALE_FIT },
};

#endif
