#include <core/game.hpp>


int main(void) {
    Game game;

    // Initialize, End if not successfully initialized
    if(game.Initialize()){
        // Game loop
        game.Run();
    }

    // Shutdown
    game.Shutdown();

    return 0;
}