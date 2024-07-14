#pragma once
#include <chrono>
#include <thread>

using namespace std::chrono;

struct FrameTiming
{
public:
    steady_clock::time_point LastFrameTime;

    steady_clock::duration DeltaTime;
    float DeltaSeconds;
    float DeltaMilliseconds;

    unsigned int GetTargetFPS()
    {
        return _targetFPS;
    }
    void SetTargetFPS(unsigned int newTargetFPS)
    {
        _targetFPS = newTargetFPS;
        _targetDeltaTime = steady_clock::duration(seconds(1) / _targetFPS);
    }

    steady_clock::duration GetTargetDeltaTime()
    {
        return _targetDeltaTime;
    }
    void SetTargetDeltaTime(steady_clock::duration newTargetDeltaTime)
    {
        _targetDeltaTime = newTargetDeltaTime;
        _targetFPS = seconds(1) / newTargetDeltaTime;
    }

    void Timing()
    {
        DeltaTime = steady_clock::now() - LastFrameTime;

        if (DeltaTime < GetTargetDeltaTime())
        {
            steady_clock::duration timeToSleep = GetTargetDeltaTime() - DeltaTime;
            std::this_thread::sleep_for(timeToSleep);
        }
        DeltaTime = steady_clock::now() - LastFrameTime;
        DeltaSeconds = DeltaTime / seconds(1);
        DeltaMilliseconds = DeltaTime / milliseconds(1);
    }

private:
    unsigned int _targetFPS;
    steady_clock::duration _targetDeltaTime;

};