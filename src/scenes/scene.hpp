#pragma once

#include <raylib.h>
#include <core/input_manager.hpp>
#include <core/asset_manager.hpp>

struct Scene{
    InputManager& r_inputManager;
    AssetManager& r_assetManager;

    Scene(InputManager& input, AssetManager& assets)
    : r_inputManager(input), r_assetManager(assets){}
    
    virtual ~Scene(){}

    virtual void Enter() = 0;
    virtual void Update(float& dt) = 0;
    virtual void Draw(RenderTexture2D& screen) = 0;
    virtual void Exit() = 0;
};