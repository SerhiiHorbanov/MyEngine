#pragma once
#include <memory>
#include "MyGameState.h"

namespace MyEngine
{
    class MyGame
    {
    public:
        bool end = false;
        std::shared_ptr<MyGameState> State;

        virtual void Run()
        {
            State.get()->Initialize();
            while (!end)
                State.get()->GameLoopIteration(*this);
        }
    };
}