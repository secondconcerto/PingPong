/**
 * @file MainMenu.hpp
 * @brief The file contains class which displays the main menu screen of the game.
 * @author Oliwia Mlonek
 */
#ifndef MainMenu_hpp
#define MainMenu_hpp

#include <stdio.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

/**
 * @class MainMenu
 * @brief Is responsible for creating and displaying the main menu screen of the game and catches the mouse movement.
 */
class MainMenu
{
    
public:
    /**
     * Represents various possible return values the menu could return.
     */
    enum MenuResult { Nothing, Exit, Play };
    
    /**
     * Struct that represents the individual menu items in the menu.
     */
    struct MenuItem
    {
    public:
        sf::Rect<int> rect;
        MenuResult action;
    };
    
    /**
     * Function load a main-menu and create a sprite to display it.
     * @param window is a created window.
     * @return the main-menu state from the GetMenuResponse function for a created window.
     */
    MenuResult Show(sf::RenderWindow& window);
    
private:
    /**
     * Function which correspond with the location of buttons physical locations within the main-menu image file.
     * @param window c
     * @return menu state.
     */
    MenuResult GetMenuResponse(sf::RenderWindow& window);
   
    /**
     * Function checks if any button has been pressed.If not, returns exit.
     * @param x an integer variable which informs of the location of the mouse.
     * @param y an integer variable which informs of the location of the mouse.
     * @return menu state.
     */
    MenuResult HandleClick(int x, int y);
    
    /**
     * A list of type MenuItem, which holds the various MenuItems that compose MainMenu.
     */
    std::list<MenuItem> _menuItems;
};
#endif /* MainMenu_hpp */
