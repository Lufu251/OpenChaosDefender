#include <core/input_manager.hpp>

#include <raylib.h>
#include <raymath.h>

InputManager::InputManager(){}
InputManager::~InputManager(){}

void InputManager::CalculateMousePosition(){
    // Calculate mouseposition inside game window
    Vector2 mouse = GetMousePosition();
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