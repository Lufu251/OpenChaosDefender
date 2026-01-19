#include <raylib.h>

#include <core/input_manager.hpp>

InputManager::InputManager(){}
InputManager::~InputManager(){}

void InputManager::Bind(Action action, KeyboardKey key){
    bindings[action] = key;
}

Vector2 GetGameMousePosition(){
    Vector2 gameMousePosition; // = GetMouthePosition();
    
    // Subtract notch from gameMousePosition
    // Multiply with scale
    // clamp to canvas

    return gameMousePosition;
}

bool IsActionTriggered(){

    return true;
}