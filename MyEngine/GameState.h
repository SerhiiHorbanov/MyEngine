#pragma once

namespace MyEngine
{
    class Game;
    //whem deriving from MyGameState it is recommended to also derive std::enable_shared_from_this<MyGameState> with public access
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