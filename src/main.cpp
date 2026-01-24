#include <core/game.hpp>


int main(void)
{
    // Raylib Window
    const char* titel = "OpenChaosDefender";
    const int screenWidth = 1080;
    const int screenHeight = 720;
    const int minScreenWidth = 320;
    const int minScreenHeight = 320;


    // Pre window initialize
    SetConfigFlags(FLAG_WINDOW_HIGHDPI); // Enable High DPI scaling
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Set window is resizable

    // Window initialize
    InitWindow(screenWidth, screenHeight, titel);

    // Audiodevice initialize
    InitAudioDevice();

    // Post window initialize
    SetWindowMinSize(minScreenWidth,minScreenHeight); // Set minimum window size
    SetTargetFPS(60); // Set 60 frames-per-second
    SetExitKey(KEY_NULL);




    Game game;

    // Initialize
    if(game.Initialize()){
        // Game loop
        game.Run();

        // Draw the game to window
    }

    // Shutdown
    game.Shutdown();

    return 0;
}