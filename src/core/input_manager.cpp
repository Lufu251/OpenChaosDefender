#include <core/input_manager.hpp>

#include <raylib.h>
#include <raymath.h>

InputManager::InputManager(){}
InputManager::~InputManager(){}

void InputManager::Bind(Action action, KeyboardKey key){
    bindings[action] = key;
}

void InputManager::SetMouse(const Vector2& position){
    mouse = position;
}

Vector2& InputManager::GetMouse(){
    return mouse;
}

bool InputManager::IsActionContinuos(Action action){
    return IsKeyDown(bindings[action]);
}

bool InputManager::IsActionTriggered(Action action){
    return IsKeyPressed(bindings[action]);
}

void InputManager::Cleanup(){
    bindings.clear();
}