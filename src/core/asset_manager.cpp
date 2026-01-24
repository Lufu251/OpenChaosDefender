#include <core/asset_manager.hpp>

#include <filesystem>
#include <iostream>

AssetManager::AssetManager(){}
AssetManager::~AssetManager(){}

// Set directories and asset path
void AssetManager::SearchAssetPath(std::string folderName, size_t searchDepth){
    std::filesystem::path currentDir = GetWorkingDirectory();
    std::cout << "Searching for " << folderName << " directory starting from " << currentDir << std::endl;
    
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

void AssetManager::SetFontDirectory(const std::string& folderName){
    fontsDirectory = folderName;
}

void AssetManager::SetTexturesDirectory(const std::string& folderName){
    texturesDirectory = folderName;
}

void AssetManager::SetSoundDirectory(const std::string& folderName){
    soundsDirectory = folderName;
}

void AssetManager::SetMusicDirectory(const std::string& folderName){
    musicDirectory = folderName;
}