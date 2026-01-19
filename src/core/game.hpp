#pragma once

#include <raylib.h>
#include <core/window_manager.hpp>
#include <core/scene_manager.hpp>

struct Game {
    // Logic
    bool running = true;

    WindowManager windowManager;

    Game();
    ~Game();

    bool Initialize();
    void Run();
    void Shutdown();

    void InitializeWindow();
    void DrawCanvasToWindow();
};