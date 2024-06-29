#pragma once
#include "FrameTimingInfo.h"

namespace MyEngine
{
    class MyGame;

    class MyGameState
    {
    public:
        FrameTimingInfo time;

        virtual void Initialize() = 0;
        virtual void GameLoopIteration(MyGame& game);

    protected:

        virtual void Input() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        virtual void Timing();
    };
}