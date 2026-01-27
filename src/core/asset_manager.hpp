#pragma once

#include <raylib.h>
#include <unordered_map>
#include <string>

struct AssetManager{
    std::unordered_map<std::string, Texture2D> textures;
    std::unordered_map<std::string, Font> fonts;

    AssetManager();
    ~AssetManager();

    // Asset path and directory names
    std::string assetPath = "Null";
    std::string texturesDirectory = "Null";
    std::string fontDirectory = "Null";

    // Set directories and asset path
    void SearchAssetPath(std::string folderName, size_t searchDepth);

    // Texture
    void SetTexturesDirectory(const std::string& name);
    void LoadTexture(const std::string& fileName, const std::string& assetName);
    Texture2D& GetTexture(const std::string& name);

    // Font
    void SetFontDirectory(const std::string& name);
    void LoadFont(const std::string& fileName, const std::string& assetName, const int size);
    Font& GetFont(const std::string& name);

    // Unload
    void Cleanup();
};