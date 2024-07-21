#pragma once
#include <deque>
#include <memory>
#include "FrameTiming.h"
#include "GameState.h"

namespace MyEngine
{
    class Game
    {
    public:
        bool end = false;

        FrameTiming Time;
        std::deque<std::shared_ptr<GameState>> NextStates;
    protected:
        std::shared_ptr<GameState> _state;

    public:
        Game(FrameTiming timing, std::shared_ptr<GameState> state)
        {
            _state = state;
        }

        void SetState(std::shared_ptr<GameState> state);
        std::shared_ptr<GameState> GetState();

        virtual void Run();
    private:
        void CheckForChangingState();
    };
}