#pragma once
#include <chrono>

using namespace std::chrono;

struct FrameTimingInfo
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

private:
    unsigned int _targetFPS;
    steady_clock::duration _targetDeltaTime;
};