/**
 * @file paletka_2.hpp
 * @brief The file contains class which manipulate the AI player paddle object.
 * @author Oliwia Mlonek
 */

#ifndef paletka_2_hpp
#define paletka_2_hpp

#include <iostream>
#include "Visible_obj.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
 * @class Paletka_2
 * @brief Creates the AI player’s paddle.
 */
class Paletka_2 : public visible_obj
{
public:
    
    /**
     * Create the Paletka_2 object.
     */
    Paletka_2(void);
    
    /**
     * Destroys objects.
     */
    ~Paletka_2(void);
    
    /**
     * Override Update() function from the base class visible_obj. Checks if the arrows are pressed, changes the speed of the paddle.
     * @param elapsedTime elapsed since the last frame.
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
    float _elapsedTimeSinceStart;
};


#endif /* paletka_2_hpp */
