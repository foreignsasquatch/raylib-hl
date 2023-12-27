function main() {
    Rl.initWindow(1280, 720, "Test");
    while(!Rl.windowShouldClose()) {
        Rl.beginDrawing();
        Rl.clearBackground({r: 255, g: 0, b: 0, a: 255});
        Rl.endDrawing();
    }
    Rl.closeWindow();
}