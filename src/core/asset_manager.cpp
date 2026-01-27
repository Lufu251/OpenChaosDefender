#include <core/asset_manager.hpp>

#include <filesystem>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

AssetManager::AssetManager(){}
AssetManager::~AssetManager(){}

// Set directories and asset path
void AssetManager::SearchAssetPath(std::string folderName, size_t searchDepth){
    std::filesystem::path currentDir = GetWorkingDirectory();
    std::cout << "Searching " << folderName << " directory starting from " << currentDir << std::endl;
    
    for (size_t i = 0; i < searchDepth; i++){
        std::filesystem::path potentialPath = currentDir / folderName;
        if (std::filesystem::exists(potentialPath) && std::filesystem::is_directory(potentialPath)) {
            assetPath = potentialPath.string(); // Folder found exit for loop
            std::cout << "Path to directory " << folderName << " found. Path is " << assetPath << std::endl;
            break;
        }
        currentDir = currentDir.parent_path(); // Move up one level
    }

    if(assetPath == ""){
        throw std::runtime_error("Failed to find directory: " + folderName);
    }
}

// Texture
void AssetManager::SetTexturesDirectory(const std::string& name){
    texturesDirectory = name;
}

void AssetManager::LoadTexture(const std::string& fileName, const std::string& assetName){
    std::string path = assetPath + "/" + texturesDirectory + "/" + fileName;
    
    std::cout << "Loading texture: " << path << std::endl;
    Texture2D texture{};
    texture = ::LoadTexture((path).c_str());

    if(IsTextureValid(texture)){
        textures.insert({assetName, texture});
    }
}

Texture& AssetManager::GetTexture(const std::string& name){
    if(textures.count(name) == 0){
        std::cerr << "GetTexture: " << name << " is not load" << std::endl;
    }
    return textures[name];
}

// Font
void AssetManager::SetFontDirectory(const std::string& name){
    fontDirectory = name;
}

void AssetManager::LoadFont(const std::string& fileName, const std::string& assetName, const int size){
    std::string path = assetPath + "/" + fontDirectory + "/" + fileName;
    
    std::cout << "Loading font: " << path << std::endl;
    Font font{};

    font = ::LoadFontEx((path).c_str(), size, NULL, 0);

    if(IsFontValid(font)){
        fonts.insert({assetName, font});
    }
}

Font& AssetManager::GetFont(const std::string& name){
    if(fonts.count(name) == 0){
        std::cerr << "GetFont: " << name << " is not load" << std::endl;
    }
    return fonts[name];
}

void AssetManager::Cleanup(){
    // Unload and clear textures
    for(auto texture : textures){UnloadTexture(texture.second);}
    textures.clear();

    // Unload and clear fonts
    for(auto font : fonts){UnloadFont(font.second);}
    fonts.clear();
}