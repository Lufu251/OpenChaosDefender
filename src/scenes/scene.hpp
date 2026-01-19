#pragma once

#include <raylib.h>

struct Scene{
    Scene(){}
    ~Scene(){}

    virtual void Enter() = 0;
    virtual void Update(float& dt) = 0;
    virtual void Draw(RenderTexture2D& gameWindow) = 0;
    virtual void Exit() = 0;
};