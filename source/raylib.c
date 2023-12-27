#if defined(_MSC_VER)
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define NOUSER
#endif

#define HL_NAME(n) raylib_##n

#include <hl.h>
#include "raylib.h"

// WINDOW RELATED FUNCTIONS
HL_PRIM void HL_NAME(init_window)(int width, int height, vstring* title) {
    InitWindow(width, height, hl_to_utf8(title->bytes));
}
DEFINE_PRIM(_VOID, init_window, _I32 _I32 _STRING)

HL_PRIM void HL_NAME(close_window)() {
    CloseWindow();
}
DEFINE_PRIM(_VOID, close_window, _NO_ARG)

HL_PRIM bool HL_NAME(window_should_close)(){
    return WindowShouldClose();
}
DEFINE_PRIM(_BOOL, window_should_close, _NO_ARG);


// DRAWING-RELATED FUNCTIONS
HL_PRIM void HL_NAME(clear_background)(Color* color) {
    ClearBackground(*color);
}
DEFINE_PRIM(_VOID, clear_background, _STRUCT)

HL_PRIM void HL_NAME(begin_drawing)() {
    BeginDrawing();
}
DEFINE_PRIM(_VOID, begin_drawing, _NO_ARG)

HL_PRIM void HL_NAME(end_drawing)() {
    EndDrawing();
}
DEFINE_PRIM(_VOID, end_drawing, _NO_ARG)