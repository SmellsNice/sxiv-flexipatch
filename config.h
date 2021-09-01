#ifdef _WINDOW_CONFIG

/* default window dimensions (overwritten via -g option): */
enum {
	WIN_WIDTH  = 800,
	WIN_HEIGHT = 600
};

/* colors and font are configured with 'background', 'foreground' and
 * 'font' X resource properties.
 * See X(7) section Resources and xrdb(1) for more information.
 */

#endif
#ifdef _IMAGE_CONFIG

/* levels (in percent) to use when zooming via '-' and '+':
 * (first/last value is used as min/max zoom level)
 */
static const float zoom_levels[] = {
         10.0, 	20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 
	100.0, 110.0, 120.0, 130.0, 140.0, 150.0, 160.0, 170.0, 180.0, 190.0, 200.0, 225.0, 250.0, 275.0, 300.0, 325.0, 350.0, 375.0, 400.0, 450.0, 500.0, 550.0, 600.0, 650.0, 700.0, 750.0, 800.0, 850.0, 900.0, 950.0, 1000.0
};

/* default slideshow delay (in sec, overwritten via -S option): */
enum { SLIDESHOW_DELAY = 5 };

/* gamma correction: the user-visible ranges [-GAMMA_RANGE, 0] and
 * (0, GAMMA_RANGE] are mapped to the ranges [0, 1], and (1, GAMMA_MAX].
 * */
static const double GAMMA_MAX   = 10.0;
static const int    GAMMA_RANGE = 32;

/* command i_scroll pans image 1/PAN_FRACTION of screen width/height */
static const int PAN_FRACTION = 25;

/* if false, pixelate images at zoom level != 100%,
 * toggled with 'a' key binding
 */
static const bool ANTI_ALIAS = true;

/* if true, use a checkerboard background for alpha layer,
 * toggled with 'A' key binding
 */
static const bool ALPHA_LAYER = false;

#if SVG_IMAGE_SUPPORT_PATCH
/* fallback height and width for svg documents,
 * use these values in case svg document does not specify height and width.
 */
enum {
	FB_SVG_HEIGHT = 512,
	FB_SVG_WIDTH  = 512
};
#endif // SVG_IMAGE_SUPPORT_PATCH

#endif
#ifdef _THUMBS_CONFIG

/* thumbnail sizes in pixels (width == height): */
static const int thumb_sizes[] = { 32, 64, 96, 128, 160 };

#if THUMBS_PADDING_PATCH
const int THUMB_BORDERS[] = { 2, 2, 2, 2, 2 };
const int THUMB_MARGIN = -1;
const int THUMB_PADDING = 2;
#endif // THUMBS_PADDING_PATCH

/* thumbnail size at startup, index into thumb_sizes[]: */
static const int THUMB_SIZE = 3;

#endif
#ifdef _MAPPINGS_CONFIG

/* keyboard mappings for image and thumbnail mode: */
static const keymap_t keys[] = {
	/* modifiers    key               function              argument */
	{ 0,            XK_q,             g_quit,               None },
  	{ ControlMask,  XK_c,             g_quit,               None },
        #if DMENU_LIKE_BEHAVIOUR_PATCH
	{ 0,            XK_Return,        g_switch_mode,        0 },
	{ ControlMask,  XK_Return,        g_switch_mode,        1 },
	#else
	{ 0,            XK_Return,        g_switch_mode,        None },
	#endif // DMENU_LIKE_BEHAVIOUR_PATCH
	{ 0,            XK_f,             g_toggle_fullscreen,  None },
	{ 0,            XK_b,             g_toggle_bar,         None },
	{ ControlMask,  XK_x,             g_prefix_external,    None },
	{ 0,            XK_g,             g_first,              None },
	{ 0,            XK_G,             g_n_or_last,          None },
	{ 0,            XK_r,             g_reload_image,       None },
	{ 0,            XK_D,             g_remove_image,       None },
	{ ShiftMask,    XK_h,             i_scroll_to_edge,     DIR_LEFT },
	{ ShiftMask,    XK_j,             i_scroll_to_edge,     DIR_DOWN },
	{ ShiftMask,    XK_k,             i_scroll_to_edge,     DIR_UP },
	{ ShiftMask,    XK_l,             i_scroll_to_edge,     DIR_RIGHT },
	{ ShiftMask,    XK_Left,          i_scroll_to_edge,     DIR_LEFT },
	{ ShiftMask,    XK_Down,          i_scroll_to_edge,     DIR_DOWN },
	{ ShiftMask,    XK_Up,            i_scroll_to_edge,     DIR_UP },
	{ ShiftMask,    XK_Right,         i_scroll_to_edge,     DIR_RIGHT },

	{ 0,            XK_m,             g_toggle_image_mark,  None },
	{ 0,            XK_M,             g_mark_range,         None },
	{ ControlMask,  XK_m,             g_reverse_marks,      None },
	{ ControlMask,  XK_M,             g_unmark_all,         None },
	{ 0,            XK_N,             i_navigate,           +10 },
	{ 0,            XK_P,             i_navigate,           -10 },
	{ ControlMask,  XK_n,             g_navigate_marked,    +1 },
	{ ControlMask,  XK_p,             g_navigate_marked,    -1 },
	{ 0,            XK_bracketleft,   g_change_gamma,       -1 },
	{ 0,            XK_bracketright,  g_change_gamma,       +1 },
	{ 0,            XK_braceleft,     g_change_gamma,        0 },
	{ 0,            XK_braceright,    g_change_gamma,        0 },

	{ ControlMask,  XK_h,             t_move_sel,           DIR_LEFT },
	{ ControlMask,  XK_j,             t_move_sel,           DIR_DOWN },
	{ ControlMask,  XK_k,             t_move_sel,           DIR_UP },
	{ ControlMask,  XK_l,             t_move_sel,           DIR_RIGHT },
	{ ControlMask,  XK_Left,          t_move_sel,           DIR_LEFT },
	{ ControlMask,  XK_Down,          t_move_sel,           DIR_DOWN },
	{ ControlMask,  XK_Right,         t_move_sel,           DIR_RIGHT },
	{ ControlMask,  XK_Up,            t_move_sel,           DIR_UP },
	{ 0,            XK_R,             t_reload_all,         None },

	{ 0,            XK_n,             i_navigate,           +1 },
	{ 0,            XK_space,         i_navigate,           +1 },
	{ 0,            XK_Right,         i_navigate,           +1 },
        { 0,            XK_p,             i_navigate,           -1 },
	{ 0,            XK_BackSpace,     i_navigate,           -1 },
	{ ShiftMask,    XK_space,         i_navigate,           -1 },
        { 0,            XK_Left,          i_navigate,           -1 },
        { ControlMask,  XK_6,             i_alternate,          None },
	{ ControlMask,  XK_space,         i_toggle_animation,   None },
	#if NAVIGATE_IF_NOT_SCROLL_PATCH
	{ 0,            XK_h,             i_scroll_or_navigate, DIR_LEFT },
	{ 0,            XK_Left,          i_scroll_or_navigate, DIR_LEFT },
	{ 0,            XK_j,             i_scroll_or_navigate, DIR_DOWN },
	{ 0,            XK_Down,          i_scroll_or_navigate, DIR_DOWN },
	{ 0,            XK_k,             i_scroll_or_navigate, DIR_UP },
	{ 0,            XK_Up,            i_scroll_or_navigate, DIR_UP },
	{ 0,            XK_l,             i_scroll_or_navigate, DIR_RIGHT },
	{ 0,            XK_Right,         i_scroll_or_navigate, DIR_RIGHT },
	#else
	{ ControlMask,  XK_h,             i_scroll,             DIR_LEFT },
	{ ControlMask,  XK_Left,          i_scroll,             DIR_LEFT },
	{ ControlMask,  XK_j,             i_scroll,             DIR_DOWN },
	{ ControlMask,  XK_Down,          i_scroll,             DIR_DOWN },
	{ ControlMask,  XK_k,             i_scroll,             DIR_UP },
	{ ControlMask,  XK_Up,            i_scroll,             DIR_UP },
	{ ControlMask,  XK_l,             i_scroll,             DIR_RIGHT },
	{ ControlMask,  XK_Right,         i_scroll,             DIR_RIGHT },
	#endif // NAVIGATE_IF_NOT_SCROLL_PATCH
	{ 0,            XK_J,             g_zoom,               -1 },
	{ 0,            XK_K,             g_zoom,               +1 },	
	{ 0,            XK_Down,          g_zoom,               -1 },
	{ 0,            XK_Up,            g_zoom,               +1 },
	{ 0,            XK_KP_Subtract,   g_zoom,               -1 },
	{ 0,            XK_KP_Add,        g_zoom,               +1 },
        { 0,            XK_minus,         g_zoom,               -1 },
	{ 0,            XK_plus,          g_zoom,               +1 },
        { 0,            XK_equal,         i_set_zoom,           100 },
	{ 0,            XK_W,             i_fit_to_win,         SCALE_DOWN },
	{ 0,            XK_w,             i_fit_to_win,         SCALE_FIT },
	#if SCALE_FILL_MODE_PATCH
	{ 0,            XK_F,             i_fit_to_win,         SCALE_FILL },
	#endif // SCALE_FILL_MODE_PATCH
	{ 0,            XK_e,             i_fit_to_win,         SCALE_WIDTH },
	{ 0,            XK_E,             i_fit_to_win,         SCALE_HEIGHT },
	{ 0,            XK_comma,         i_rotate,             DEGREE_270 },
	{ 0,            XK_period,        i_rotate,             DEGREE_90 },
	{ 0,            XK_less,          i_flip,               FLIP_HORIZONTAL },
	{ 0,            XK_greater,       i_flip,               FLIP_VERTICAL },
	{ 0,            XK_a,             i_toggle_antialias,   None },
	{ 0,            XK_A,             i_toggle_alpha,       None },
	{ 0,            XK_s,             i_slideshow,          None },
};

/* mouse button mappings for image mode: */
static const button_t buttons[] = {
	/* modifiers    button            function              argument */
	{ 0,            1,                i_cursor_navigate,    None },
	{ 0,            2,                i_drag,               DRAG_ABSOLUTE },
	{ 0,            3,                g_switch_mode,        None },
	{ 0,            4,                g_zoom,               +1 },
	{ 0,            5,                g_zoom,               -1 },
};

#if ALLOW_ESCAPE_KEY_IN_EXTERNAL_KEY_HANDLER_PATCH
/* If false, sxiv will send all key combos to the external keyhandler until the keyhandler
 * returns 1 as its exit status.
 * The example external keyhandler uses the escape key for this.
 */
static const bool one_extkeyhandler_cmd = true;
#endif // ALLOW_ESCAPE_KEY_IN_EXTERNAL_KEY_HANDLER_PATCH

#endif
