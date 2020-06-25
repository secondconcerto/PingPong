/**
 * @file game.hpp
 * @brief The file contains entirely static class 'Game'.
 * @author Oliwia Mlonek
 */
#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "player_paletka.hpp"
#include "paletka_2.hpp"
#include "Visible_obj.hpp"
#include "Menager.hpp"
#include "HUD.hpp"

/**
 * @class Game
 * @brief Represents the game.
 */
class Game
{
public:
    /**
     * Launch the game loop.
     */
    static void Start();
    
    /**
     *  Returns rendered window.
     */
    static sf::RenderWindow& GetWindow();
   
    /**
     *  Wait for an event and return it.
     */
    const static sf::Event& GetInput();


    
    const static int SCREEN_WIDTH = 1024;
    const static int SCREEN_HEIGHT = 768;
    
    
    /**
     *  Returns a member variables - 'menager' object.
     */
    const static menager& GetGameObjectManager();
    
private:
    sf::Music music;
  
    /**
     * Checks if the game status has been changed to 'Exiting'.
     * @return The information about whether the game state is changed.
     */
    static bool IsExiting();
   
    /**
     * Start the game loop.
     */
    static void GameLoop();
    
    /**
     * The function is responsible for creating and displaying the back screen.
     */
    static void show_back_screen();
   
    /**
     * The function is responsible for creating and displaying the main menu.
     */
    static void ShowMenu();
    
    /**
     * Represents the various states that game can be in.
     */
    enum GameState { Uninitialized, ShowingSplash, Paused,
        ShowingMenu, Playing, Exiting };
    
    static GameState _gameState;
    static sf::RenderWindow _mainWindow;

    static menager _gameObjectManager;
    static HUD _hud;
};
