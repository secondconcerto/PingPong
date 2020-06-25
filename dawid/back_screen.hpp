/**
 * @file back_screen.hpp
 * @brief The file contains class which displays the back screen of the game.
 * @author Oliwia Mlonek
 */

#ifndef back_screen_hpp
#define back_screen_hpp
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <iostream>
#include <cassert>
#include <iostream>
#pragma once

/**
 * @class back_screen
 * @brief Is responsible for creating and displaying the back screen of the game.
 */
class back_screen{
public:
    
    /**
     * Function load a back-screen image file and create a sprite to display it.
     * @param window is a created window.
     */
    void Show(sf::RenderWindow& window);
};


#endif /* back_screen_hpp */
