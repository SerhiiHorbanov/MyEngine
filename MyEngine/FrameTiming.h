#pragma once
#include <chrono>
#include <thread>

using namespace std::chrono;

struct FrameTiming
{
public:

    bool WaitUntilReachedTargetDeltaTime = true;
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
        _targetDeltaTime = seconds(1) / _targetFPS;
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

        if (WaitUntilReachedTargetDeltaTime && DeltaTime < GetTargetDeltaTime())
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

public:

    FrameTiming(bool waitUntilReachedTargetDeltaTime = true, unsigned int targetFPS = 60) : 
        WaitUntilReachedTargetDeltaTime(waitUntilReachedTargetDeltaTime), 
        _targetFPS(targetFPS), 
        LastFrameTime(steady_clock::now()),
        DeltaTime(1 / targetFPS), 
        DeltaSeconds(DeltaTime / seconds(1)),
        DeltaMilliseconds(DeltaSeconds * 1000), 
        _targetDeltaTime(seconds(1) / targetFPS)
    {}
};