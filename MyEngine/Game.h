#pragma once
#include <memory>
#include "GameState.h"
#include "FrameTiming.h"

namespace MyEngine
{
    class Game
    {
    public:
        bool end = false;

        Game(std::shared_ptr<GameState> state)
        {
            State = state;
        }

        FrameTiming Time;
        std::shared_ptr<GameState> State;

        virtual void Run()
        {
            State->Initialize(*this);
            while (!end)
                State->GameLoopIteration(*this);
        }
    };
}