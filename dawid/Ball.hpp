/**
 * @file Ball.hpp
 * @brief The file contains class which manipulate the game ball object.
 * @author Oliwia Mlonek
 */

#ifndef Ball_hpp
#define Ball_hpp

#include <iostream>
#include "Visible_obj.hpp"
#include "Menager.hpp"
#include "game.hpp"

/**
 * @class Ball
 * @brief Responsible for creating a ball object and manipulating it.
 */
class Ball : public visible_obj
{
public:
    
    /**
     * Create the Ball object.
     */
    Ball();
    
    /**
     * Destroys objects.
     */
    virtual ~Ball();
   
    /**
     * Function updates the elapsed time since the last frame and changes the speed and movement of the ball.
     * @param elapsedTime float variable which gives the elapsed time since the last frame.
     */
    void Update(float elapsedTime );
    
    /**
     * Function gets the velocity of the object.
     * @return a float variable which represents a velocity of the ball.
     */
    float GetVelocity() const;
    bool score;
    
    
private:
    float _velocity;
    float _angle;
    float _elapsedTimeSinceStart;
    
    float LinearVelocityX(float angle);
    float LinearVelocityY(float angle);
};

#endif /* ball_hpp */

