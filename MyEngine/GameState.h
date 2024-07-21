#pragma once

namespace MyEngine
{
    class Game;
    class GameState
    {
    public:
        virtual void Initialize(Game& game) { };
        virtual void GameLoopIteration(Game& game);

    protected:
        virtual void Input(Game& game) { };
        virtual void Update(Game& game) { };
        virtual void Render(Game& game) { };
        void Timing(Game& game);
    };
}