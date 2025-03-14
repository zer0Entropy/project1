#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "log.hpp"
#include "state.hpp"
#include "resource/resourceMgr.hpp"
#include "system/input.hpp"
#include "system/render.hpp"
#include "rng.hpp"

class MainMenuState;
class Gameplay;
class GameOver;

class Game {
public:
    Game();
    Game(Game& copy) = delete;
    Game(const Game& copy) = delete;
    Game(Game&& move) = delete;
    ~Game();

    void                                    Update();

    GameState*                              GetCurrentState() const;
    GameState*                              FindInactiveState(GameState::ID stateID) const;
    void                                    CreateGameState(GameState::ID stateID);
    void                                    DestroyCurrentGameState();
private:
    void                                    CreateMainMenuState();
    void                                    CreateGameplayState();
    void                                    CreateGameOverState();

    sf::Vector2u                            targetWindowSize;
    std::string                             windowTitle;

    sf::Clock                               runtimeClock;

    RandomNumberGenerator                   rng;

    LogMgr                                  logMgr;
    ResourceMgr                             resourceMgr;
    std::unique_ptr<GameState>              currentState;
    std::vector<std::unique_ptr<GameState>> inactiveStates;
    sf::RenderWindow                        mainWindow;

    RenderSystem                            renderSystem;
    InputSystem                             inputSystem;

    bool                                    errorFlag;

    static constexpr std::string_view       logPath{"log.txt"};
};
