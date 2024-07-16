#include "Game.h"

namespace MyEngine
{
    void Game::SetState(std::shared_ptr<GameState> state)
    {
        NextStates.push_back(state);
    }

    std::shared_ptr<GameState> Game::GetState()
    {
        return _state;
    }

    void Game::Run()
    {
        _state->Initialize(*this);
        while (!end)
        {
            _state->GameLoopIteration(*this);
            CheckForChangingState();
        }

    }

    inline void Game::CheckForChangingState()
    {
        if (NextStates.size() != 0)
        {
            _state = NextStates.front();
            NextStates.pop_front();
        }
    }
}
