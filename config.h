static const unsigned int borderpx  = 1;
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;
static const int topbar             = 0;
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_blk1[]        = "#000000";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3,  col_blk1,  col_blk1 },
	[SchemeSel]  = { col_cyan,   col_blk1,  col_gray1  },
};
static const char *tags[] = {
    "1", "2", "3", "4", "5", "6", "7", "8", "9",
    "xoo", /* 9*/
    "xml", /* 10*/
    "xau", /* 11*/
    "xrd", /* 12*/ 
    "xmj", /* 13*/
};
static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};
static const float mfact     = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const Layout layouts[] = {
	{ "[]=",      tile },    /* default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};
#define MODKEY Mod1Mask
#define MODKY1 Mod4Mask
#define TAGKEYS(MKEY,KEY,TAG) \
	{ MKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define shcmd(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, null } }
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
#define DMU_DEFS \
    "-b", \
    "-fn", dmenufont, \
    "-nb", "black", \
    "-nf", "#efef8f", \
    "-sb", "black", \
    "-sf", "white"
    /*"-m", dmenumon,*/
static const char *vol_inc[]   = { "pamixer", "--allow-boost", "-i", "5", NULL };
static const char *vol_dec[]   = { "pamixer", "--allow-boost", "-d", "5", NULL };
static const char *termcmd[]   = { "st", NULL };
static const char *dmenucmd[]  = { "dmenu_run", DMU_DEFS, NULL };
static const char *dmu_cmd[]   = { "dmenu_run", DMU_DEFS, NULL };
static const char *dmu_pas[]   = { "passmenu",  DMU_DEFS, NULL };
static const char *dmu_blu[]   = { "dmenu-bluetooth",      "-l", "20", DMU_DEFS, NULL };
static const char *dmu_nwm[]   = { "networkmanager_dmenu", "-l", "20", DMU_DEFS, NULL };
static const char *app_qba[]   = { "qb", NULL };
static const char *app_gpt[]   = { "qb", "w.gpt", NULL };
static const char *app_goo[]   = { "google-chrome-stable", NULL };
static const char *app_aux[]   = { "st", "-c", "au", "-e", "vimpc", "&", NULL };
static const char *app_mlx[]   = { "st", "-c", "mlx", "neomutt", "-e", "\"push \'<change-folder>=ii<enter>\'\"", NULL };
static const Key keys[] = {
	/* modifier                     key        function        argument */
    { MODKEY|ControlMask,           XK_k,      spawn,          {.v = vol_inc } },
	{ MODKEY|ControlMask,           XK_j,      spawn,          {.v = vol_dec } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmu_cmd } },
    { MODKY1,                       XK_p,      spawn,          {.v = dmu_pas } },
    { ControlMask|MODKY1,           XK_p,      spawn,          {.v = dmu_blu } },
    { MODKY1|MODKEY,                XK_p,      spawn,          {.v = dmu_nwm } },
	{ MODKY1,                       XK_b,      spawn,          {.v = app_qba } },
    { MODKY1|MODKEY,                XK_b,      spawn,          {.v = app_goo } },
	{ MODKEY,                       XK_a,      spawn,          {.v = app_gpt } },
    { MODKY1|MODKEY,                XK_a,      spawn,          {.v = app_aux } },
    { MODKY1|MODKEY,                XK_m,      spawn,          {.v = app_mlx } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKY1,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	TAGKEYS(MODKEY,                 XK_1,                      0)
	TAGKEYS(MODKEY,                 XK_2,                      1)
	TAGKEYS(MODKEY,                 XK_3,                      2)
	TAGKEYS(MODKEY,                 XK_4,                      3)
	TAGKEYS(MODKEY,                 XK_5,                      4)
	TAGKEYS(MODKEY,                 XK_6,                      5)
	TAGKEYS(MODKEY,                 XK_7,                      6)
	TAGKEYS(MODKEY,                 XK_8,                      7)
	TAGKEYS(MODKEY,                 XK_9,                      8)
    TAGKEYS(MODKEY,                 XK_o,                      9)  /*xoo odos*/
    TAGKEYS(MODKY1,                 XK_m,                      10) /*xml mail/coms*/
    TAGKEYS(MODKY1,                 XK_a,                      11) /*xau*/
    TAGKEYS(MODKY1,                 XK_r,                      12) /*xrd*/
    TAGKEYS(MODKY1,                 XK_o,                      13) /*xmj*/
};
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
/* i3 convert - todo
bindsym Ctrl+$mdb+l       $exn mpc toggle
bindsym $mda+s            $exn flameshot gui
bindsym Print             $exn maimx screen
# todo - dmenu script to select a unique screenshot method
bindsym $mdb+p            $exn i3-dmenu-desktop --dmenu='dmenu -b $dmc'
# float screens
bindsym $mdb+i            $isf nnf1
bindsym $mdb+Shift+i      $ixx nnf1
bindsym $mda+i            $isf nnf2
bindsym $mda+Shift+i      $ixx nnf2
bindsym $mdb+Ctrl+i       $isf nnf3
bindsym $mdb+Ctrl+Shift+i $ixx nnf3
*/
