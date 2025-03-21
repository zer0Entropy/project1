#pragma once

#include "state.hpp"
#include "resource/resourceMgr.hpp"

struct MainMenuState: public GameState {
    Entity                          mainMenu;
    Entity                          newGameOption;
    Entity                          loadGameOption;
    Entity                          settingsOption;
    Entity                          quitGameOption;

    std::optional<unsigned int>     selectedIndex;
    std::optional<unsigned int>     pressedIndex;

    static constexpr std::string_view   newGameContents{"New Game"};
    static constexpr std::string_view   loadGameContents{"Load Game"};
    static constexpr std::string_view   settingsContents{"Settings"};
    static constexpr std::string_view   quitGameContents{"Quit Game"};

    static const sf::Vector2u           newGameRelPosition;
    static const sf::Vector2u           loadGameRelPosition;
    static const sf::Vector2u           settingsRelPosition;
    static const sf::Vector2u           quitGameRelPosition;

    static constexpr std::string_view   backgroundID{"mainMenuBackground"};
    static constexpr std::string_view   backgroundPath{"resource/brown_age_by_darkwood67.jpg"};

    static constexpr unsigned int       fontSize{48};
    static constexpr std::string_view   fontID{"mainMenuFont"};
    static constexpr std::string_view   fontPath{"resource/TruenoBlack-mBYV.otf"};
    static constexpr float              fontOutlineThicknessNormal{1.0f};
    static constexpr float              fontOutlineThicknessHighlight{4.0f};
    static const sf::Color              fontOutlineColorNormal;
    static const sf::Color              fontOutlineColorHightlight;
    static const sf::Color              fontFillColor;

    ResourceMgr::ErrorCode              LoadMainMenuFont(ResourceMgr& resourceMgr);
    ResourceMgr::ErrorCode              LoadMainMenuBackground(ResourceMgr& resourceMgr);

    Entity                              CreateMainMenu(ResourceMgr& resourceMgr);
    Entity                              CreateNewGameOption(ResourceMgr& resourceMgr);
    Entity                              CreateLoadGameOption(ResourceMgr& resourceMgr);
    Entity                              CreateSettingsOption(ResourceMgr& resourceMgr);
    Entity                              CreateQuitGameOption(ResourceMgr& resourceMgr);

    void DoAction(ActionID action, std::optional<EntityID> ownerID = std::nullopt);
    void HighlightSelectedOption(EntityID menuOptionID);
    void ResetHighlight();
};
