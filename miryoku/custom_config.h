// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// Gaming layer: left half sends plain keys with no hold-tap, except the thumbs,
// which tap Esc/Space/Tab and hold Alt/Ctrl/Shift (no layer keys on this half).
// Right half is transparent so it keeps the Base hold-taps and layer keys.
// Enter: hold Nav (Space) or Mouse (Tab) and double-tap T.
// Exit: hold Sym/Num/Fun (right thumbs) and double-tap the Base key (U position).
#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun") \
MIRYOKU_X(GAME,   "Game")

#define U_BASE   0
#define U_EXTRA  1
#define U_TAP    2
#define U_BUTTON 3
#define U_NAV    4
#define U_MOUSE  5
#define U_MEDIA  6
#define U_NUM    7
#define U_SYM    8
#define U_FUN    9
#define U_GAME   10

#define MIRYOKU_LAYERMAPPING_GAME MIRYOKU_MAPPING

// QWERTY left half
#define MIRYOKU_LAYER_GAME \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &trans,            &trans,            &trans,            &trans,            &trans,            \
&kp A,             &kp S,             &kp D,             &kp F,             &kp G,             &trans,            &trans,            &trans,            &trans,            &trans,            \
&kp Z,             &kp X,             &kp C,             &kp V,             &kp B,             &trans,            &trans,            &trans,            &trans,            &trans,            \
U_NP,              U_NP,              U_MT(LALT, ESC),   U_MT(LCTRL, SPACE),U_MT(LSHFT, TAB),  &trans,            &trans,            &trans,            U_NP,              U_NP

#define MIRYOKU_LAYER_NAV \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      &u_to_U_GAME,      U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              &u_caps_word,      &kp LEFT,          &kp DOWN,          &kp UP,            &kp RIGHT,         \
U_NA,              &kp RALT,          &u_to_U_NUM,       &u_to_U_NAV,       U_NA,              &kp INS,           &kp HOME,          &kp PG_DN,         &kp PG_UP,         &kp END,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp RET,           &kp BSPC,          &kp DEL,           U_NP,              U_NP

// Dynamic macros, ported from the QMK fork (DM_REC1/DM_REC2/DM_RSTP/DM_PLY1/DM_PLY2).
// Requires the zmk-dynamic-macros module (modules: Anodynous/zmk-dynamic-macros/v0.3).
// Guarded so builds without the module fall back to the stock mouse layer.
#if __has_include(<behaviors/dynamic_macro.dtsi>)
#include <dt-bindings/zmk/dynamic_macros.h>
#include <behaviors/dynamic_macro.dtsi>

#define U_DM_STP &dm DM_STP 0
#define U_DM_REC &dm DM_REC 0
#define U_DM_DEL &dm DM_DEL 0
#define U_DM_PLY1 &dm DM_SLOT_RAM 0
#define U_DM_PLY2 &dm DM_SLOT_RAM 1

#define MIRYOKU_LAYER_MOUSE \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      &u_to_U_GAME,      U_DM_STP,          U_DM_REC,          U_DM_DEL,          U_CUT,             U_UND,             \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         U_NA,              U_NU,              U_DM_PLY1,         U_DM_PLY2,         U_MS_U,            U_MS_R,            \
U_NA,              &kp RALT,          &u_to_U_SYM,       &u_to_U_MOUSE,     U_NA,              U_NU,              U_WH_L,            U_WH_D,            U_WH_U,            U_WH_R,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_BTN2,            U_BTN1,            U_BTN3,            U_NP,              U_NP
#endif
