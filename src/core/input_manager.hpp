#pragma once

#include <raylib.h>
#include <map>

enum class Action { 
    Jump, 
    Shoot, 
    MoveLeft, 
    MoveRight 
};

struct InputManager{
    Vector2 mouse;

    std::map<Action, KeyboardKey> bindings;

    InputManager();
    ~InputManager();

    void Bind(Action action, KeyboardKey key);

    void SetMouse(const Vector2& position);
    Vector2& GetMouse();

    bool IsActionContinuos(Action action);
    bool IsActionTriggered(Action action);

    void Cleanup();
};