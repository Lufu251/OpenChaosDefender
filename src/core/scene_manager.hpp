#pragma once

#include <map>
#include <memory>
#include <scenes/scene.hpp>
#include <scenes/main_menu_scene.hpp>

enum class SceneType {
    NONE,
    MAINMENU,
    PLAY
};

struct SceneManager{
    // Scenes
    SceneType currentSceneType = SceneType::NONE;
    Scene* currentScene = nullptr; // Raw pointer to the currently active scene
    std::map<SceneType, std::unique_ptr<Scene>> scenes; // Owns the scene objects

    SceneManager();
    ~SceneManager();

    void CreateScenes();
    void SetScene(SceneType newSceneType);
    void CloseScenes();


};