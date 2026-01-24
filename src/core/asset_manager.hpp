#pragma once

#include <raylib.h>
#include <map>
#include <string>

struct AssetManager{
    std::map<std::string, Font> fonts;
    std::map<std::string, Texture2D> textures;
    std::map<std::string, Sound> sounds;
    std::map<std::string, Music> music;

    AssetManager();
    ~AssetManager();

    // Asset path and directory names
    std::string assetPath = "not set";
    std::string texturesDirectory = "textures";
    std::string soundsDirectory = "sounds";
    std::string fontsDirectory = "fonts";
    std::string musicDirectory = "music";

    // Set directories and asset path
    void SearchAssetPath(std::string folderName, size_t searchDepth);
    void SetFontDirectory(const std::string& folderName);
    void SetTexturesDirectory(const std::string& folderName);
    void SetSoundDirectory(const std::string& folderName);
    void SetMusicDirectory(const std::string& folderName);

    // Load
    void LoadFont();
    void LoadTexture();
    void LoadSound();
    void LoadMusic();

    // Get asset
    Font& GetFont();
    Texture2D& GetTexture();
    Sound& GetSound();
    Music& GetMusic();

    // Unload
    void ClearAllCaches();
};