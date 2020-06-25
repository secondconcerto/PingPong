/*
 * @file HUD.hpp
 * @brief The file contains class which displays the score of players.
 * @author Oliwia Mlonek
 */


#ifndef HUD_hpp
#define HUD_hpp

#include <iostream>

#include "player_paletka.hpp"
#include "paletka_2.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
 * @class HUD
 * @brief Responsible for creating and displaying the results of each player after losing the game by one of them.
 */
class HUD
{
public:
    
    /**
     * Create the HUD object.
     */
    HUD();
    /**
     * Destroys objects.
     */
    ~HUD();
    
    /**
     * Sets a player_paletka pointer to an player_paletka object.
     * @param player pointer to an object.
     */
    void SetPlayer(player_paletka * player);
    
    /**
     * Sets a Paletka_2 pointer to an Paletka_2 object.
     * @param player2 pointer to an object.
     */
    void SetPaletka(Paletka_2 * player2);
    
    /**
     * Function that draws and displays text in the background window after a lost game.
     * @param window is a created window.
     */
    void Show(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text text;
    
    player_paletka * player;
    Paletka_2 * player2;
};

#endif /* HUD_hpp */
