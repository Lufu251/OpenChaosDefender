#include <core/game.hpp>


int main(void)
{
    Game game;

    // Initialize
    if(game.Initialize()){
        // Game loop
        game.Run();
    }

    // Shutdown
    game.Shutdown();

    return 0;
}