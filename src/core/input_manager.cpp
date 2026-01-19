#include <core/input_manager.hpp>

#include <raylib.h>
#include <raymath.h>

InputManager::InputManager(){}
InputManager::~InputManager(){}

void InputManager::CalculateGameMousePosition(WindowManager& windowManager){
    // Calculate mouseposition inside game window
    Vector2 mouse = GetMousePosition();

    gameMousePosition.x = static_cast<int>((mouse.x - windowManager.targetGameWindowRec.x) / windowManager.targetGameWindowScale);
    gameMousePosition.y = static_cast<int>((mouse.y - windowManager.targetGameWindowRec.y) / windowManager.targetGameWindowScale);

    gameMousePosition = Vector2Clamp(
        gameMousePosition, 
        {0, 0}, 
        {static_cast<float>(windowManager.gameWindowWidth), static_cast<float>(windowManager.gameWindowHeight)}
    );
}

void InputManager::Bind(Action action, KeyboardKey key){
    bindings[action] = key;
}

Vector2 InputManager::GetGameMousePosition(){
    return gameMousePosition;
}

bool InputManager::IsActionTriggered(Action action){
    return IsKeyDown(bindings[action]);
}