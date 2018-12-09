#ifndef GAME_H
#define GAME_H

//#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

#include "PlayerControlledSnake.h"
#include "AIControlledSnake.h"
#include "PickUp.h"
#include "Vector2.h"
#include "Sun.h"
#include "Planet.h"

class Game
{
    public:
        Game();
        ~Game();

        void PlayGame();
        void Update();
        void Render();
        void Restart();
        void SaveGame();
        void LoadLeaderboard();

    private:
        ///Game Settings
        float ScreenWidth {1280};
        float ScreenHeight {960};
        bool GameOver = false;
        std::ofstream SaveFile;

        ///Game Instances
        PlayerControlledSnake PlayerSnake;
        AIControlledSnake AISnake{0};
        std::vector <PickUp> GamePickUpsV;
        Sun GameSun;
        Planet GamePlanet{160, 160};
        Planet GamePlanet2{480, 320};

        sf::Sprite BackgroundSpr;
        sf::Texture BackgroundTexture;
        sf::Font GameFont;
        sf::Clock GameClock;

        enum class EGameState
        {
            GamePlaying,
            GameFinished,
            LeaderboardShowing
        };

        EGameState CurrentGameState = EGameState::GamePlaying;

        ///Create Game Window at set size and give it a title
        sf::RenderWindow GameWindow{sf::VideoMode(ScreenWidth, ScreenHeight), "C++ Snake ICA : T7038904"};
};

#endif // GAME_H
