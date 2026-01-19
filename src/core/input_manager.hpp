#pragma once

#include <raylib.h>
#include <map>

#include <core/window_manager.hpp>

enum class Action { 
    Jump, 
    Shoot, 
    MoveLeft, 
    MoveRight 
};

struct InputManager{
    Vector2 gameMousePosition;
    std::map<Action, KeyboardKey> bindings;

    InputManager();
    ~InputManager();

    void CalculateGameMousePosition(WindowManager& windowManager);
    
    void Bind(Action action, KeyboardKey key);
    Vector2 GetGameMousePosition();
    bool IsActionTriggered(Action action);
};