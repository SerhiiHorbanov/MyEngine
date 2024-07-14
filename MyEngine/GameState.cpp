#include "GameState.h"
#include "Game.h"
#include <chrono>
#include <thread>

namespace MyEngine
{
    void GameState::GameLoopIteration(Game& game)
    {
        Input(game);
        Update(game);
        Render(game);
        Timing(game);
    }
    void GameState::Timing(Game& game)
    {
        game.Time.Timing();
    }
}