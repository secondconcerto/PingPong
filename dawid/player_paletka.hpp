/**
 * @file player_paletka.hpp
 * @brief The file contains class which manipulate the player paddle object.
 * @author Oliwia Mlonek
 */

#ifndef Player_paletka_hpp
#define Player_paletka_hpp

#include <iostream>
#include "Visible_obj.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
 * @class player_paletka
 * @brief Creates the player’s paddle.
 */
class player_paletka : public visible_obj
{
public:
    
    /**
     * Create the player_paddle object.
     */
    player_paletka();
    /**
     * Destroys objects.
     */
    ~player_paletka();
    
    /**
     * Override Update() function from the base class visible_obj. Checks if the arrows are pressed, changes the speed of the paddle.
     * @param elapsedTime elapsed time since the last frame.
     */
    void Update(float elapsedTime);
    
    /**
     * Function draw a rendered window.
     * @param rw is a created window.
     */
    void Draw(sf::RenderWindow& rw);
    
    /**
     * Function gets the velocity of the object.
     * @return a float variable which represents a velocity of the paddle.
     */
    float GetVelocity() const;
    
    int score;
private:
    float _velocity;  
    float _maxVelocity;
    
};

#endif /* player_paletka_hpp */
