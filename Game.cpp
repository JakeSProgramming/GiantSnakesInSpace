#include "Game.h"

Game::Game()
{
    srand(time(0));
    if (!GameFont.loadFromFile("ARCADE.TTF"));
}

Game::~Game()
{
    //dtor
}

void Game::PlayGame()
{
    if (!BackgroundTexture.loadFromFile("BackGround.png"));
    BackgroundSpr.setTexture(BackgroundTexture);

    /// Main loop that continues until we call Close()
    while (GameWindow.isOpen())
    {
        sf::Event event;
        while (GameWindow.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    GameWindow.close();
                break;
                default:
                break;
            }
        }

        /// We must clear the window each time round the loop
        GameWindow.clear();

        switch (CurrentGameState)
        {
            case EGameState::GamePlaying:
            {
                Update();
                Render();

                if (!PlayerSnake.GetAlive())
                {
                    SaveGame();
                    CurrentGameState = EGameState::GameFinished;
                }

                ///Get Time
                sf::Clock Clock;
                while (Clock.getElapsedTime().asSeconds() <= .25)
                {
                    PlayerSnake.ChangeDirection();
                }

                Clock.restart();

                if (GameClock.getElapsedTime().asSeconds() >= 90)
                {
                    SaveGame();
                    CurrentGameState = EGameState::GameFinished;
                }
                break;
            }

            case EGameState::GameFinished:
            {
                Restart();
                break;
            }

            case EGameState::LeaderboardShowing:
            {
                LoadLeaderboard();
                CurrentGameState = EGameState::GamePlaying;
            }
        }

        /// Get the window to display its contents
        GameWindow.display();
    }
}

void Game::Update()
{

    ///Movement
    {
        PlayerSnake.Move();
        AISnake.Move();
        GamePlanet.Move();
        GamePlanet2.Move();
    }

    if (GamePickUpsV.size() < 5)
    {
        PickUp NewPickup;
        NewPickup.SetNewPosition(ScreenWidth, ScreenHeight);

        GamePickUpsV.push_back(NewPickup);
    }

    for (int i = 0; i < GamePickUpsV.size(); i++)
    {
        if (!GamePickUpsV[i].IsAlive())
        {
            GamePickUpsV[i].SetNewPosition(ScreenWidth, ScreenHeight);
        }
    }

    ///Snake vs PickUp Collision Check
    {
        PlayerSnake.CheckCollidePickUp(GamePickUpsV);
        AISnake.CheckCollidePickUp(GamePickUpsV);
    }

    ///Snake vs Snake Collision Check
    {
        PlayerSnake.CheckCollideSnake(AISnake);
        AISnake.CheckCollideSnake(PlayerSnake);
    }

    ///Planet vs Snake Collision Check
    {
        GamePlanet.CheckCollideSnake(PlayerSnake);
        GamePlanet2.CheckCollideSnake(PlayerSnake);
        GamePlanet.CheckCollideSnake(AISnake);
        GamePlanet2.CheckCollideSnake(AISnake);
    }

}

void Game::Render()
{
    GameWindow.draw(BackgroundSpr);

    for (int i = 0; i < GamePickUpsV.size(); i++)
    {
        GamePickUpsV[i].Draw(GameWindow);
    }

    PlayerSnake.Draw(GameWindow);
    AISnake.Draw(GameWindow);

    GameSun.Draw(GameWindow);
    GamePlanet.Draw(GameWindow);
    GamePlanet2.Draw(GameWindow);
}

void Game::Restart()
{
    if (PlayerSnake.GetPoints() < AISnake.GetPoints())
    {
        std::string PointS = "Player Loses";
        std::stringstream ss;
        ss << PointS;
        std::string Pointsss = ss.str();

        sf::Text PointsT(Pointsss, GameFont, 20);
        PointsT.setColor(sf::Color::White);
        PointsT.setCharacterSize(36);
        PointsT.setPosition({180,200});
        GameWindow.draw(PointsT);
    }
    else if (PlayerSnake.GetPoints() > AISnake.GetPoints())
    {
        std::string PointS = "Player Wins";
        std::stringstream ss;
        ss << PointS;
        std::string Pointsss = ss.str();

        sf::Text PointsT(Pointsss, GameFont, 20);
        PointsT.setColor(sf::Color::White);
        PointsT.setCharacterSize(36);
        PointsT.setPosition({180,200});
        GameWindow.draw(PointsT);
    }



    std::string RestartS = "Do You Want To Play Again, View HighScores or Exit? P/H/E";
    std::stringstream ss;
    ss << RestartS;
    std::string Restartss = ss.str();

    sf::Text RestartT(Restartss, GameFont, 20);
    RestartT.setColor(sf::Color::White);
    RestartT.setCharacterSize(36);
    RestartT.setPosition({180,380});
    GameWindow.draw(RestartT);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        GameClock.restart();
        PlayerSnake.Reset();
        AISnake.Reset();
        CurrentGameState = EGameState::GamePlaying;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
    {
        CurrentGameState = EGameState::LeaderboardShowing;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        GameWindow.close();
    }
}

void Game::SaveGame()
{
    SaveFile.open ("SaveGame.sav", std::ofstream::app);

    if (SaveFile.fail())
    {
        std::cout << "Failed To Open" << std::endl;
    }

    SaveFile << PlayerSnake.GetPoints() << std::endl;

    SaveFile.close();

}

void Game::LoadLeaderboard()
{
    std::ifstream LoadGame("SaveGame.sav");

    int Points;
    std::vector <int> PointsV;

    while (!LoadGame.eof())
    {
        LoadGame >> Points;
        PointsV.push_back(Points);
    }

    for (int i : PointsV)
    {
        std::cout << i << std::endl;
    }
}
