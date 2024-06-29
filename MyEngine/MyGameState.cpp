#include "MyGameState.h"
#include "MyGame.h"
#include <chrono>
#include <thread>

namespace MyEngine
{
    void MyGameState::GameLoopIteration(MyGame& game)
    {
        Input();
        Update();
        Render();
        Timing();
    }

    void MyGameState::Timing()
    {
        time.DeltaTime = steady_clock::now() - time.LastFrameTime;

        if (time.DeltaTime < time.GetTargetDeltaTime())
        {
            steady_clock::duration timeToSleep = time.GetTargetDeltaTime() - time.DeltaTime;
            std::this_thread::sleep_for(timeToSleep);
        }
    }
}