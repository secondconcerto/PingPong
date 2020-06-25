/**
 * @file Visible_obj.hpp
 * @brief The file contains class which displays the objects such as ball or paddles.
 * @author Oliwia Mlonek
 */
#ifndef visible_obj_hpp
#define visible_obj_hpp
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

/**
 * @class visible_obj
 * @brief Represents an item in the world that needs to be drawn, such as the player’s paddle or the game’s ball.
 */
class visible_obj
{
public:
    
    /**
     * Create the visible_obj object.
     */
    visible_obj();
    
    /**
     * Destroys objects.
     */
    virtual ~visible_obj();
    
    /**
     * Function checks if loading a file is possible.
     * @param filename the name of the file that is loaded into the image.
     */
    virtual void load(std::string filename);
    
    /**
     * Function draw a sprite if possible.
     * @param window is a created window.
     */
    virtual void drawing(sf::RenderWindow & window);
    
    /**
     * Call update for all game objects
     * @param elapsedTime elapsed time since the last frame
     */
    virtual void Update(float elapsedTime);
    
    /**
     * Sets position of the sprite.
     * @param x is a float variable which informs of the location of the sprite.
     * @param y is a float variable which informs of the location of the sprite.
     */
    virtual void set_position(float x, float y);
    /**
     * Gets position of the sprite.
     * @return a mathematical vector with two coordinates (x and y) or current rotation of the object, in degrees.
     */
    virtual sf::Vector2f GetPosition() const;
    
    /**
     * Informs if the file was loaded correctly.
     * @return a bool variable, which is true or false, depending on whether the file was loaded without any problem.
     */
    virtual bool IsLoaded() const;
   
    /**
     * Gets the width of the sprite.
     * @return the bounds of the sprite in the coordinate system.
     */
    virtual float GetWidth() const;
   
    /**
     * Gets the height of the sprite.
     * @return the bounds of the sprite in the coordinate system.
     */
    virtual float GetHeight() const;
    
    /**
     * Gets the global bounding rectangle of the sprite.
     * @return the bounds of the sprite in the coordinate system.
     */
    virtual sf::Rect<float> GetBoundingRect() const;
    
protected:
    /**
     * Gets the sprite.
     * @return the sprite.
     */
    sf::Sprite& GetSprite();
    
private:
    sf::Sprite  sprite_;
    sf::Texture image_;
    std::string file_name;
    bool is_loaded;
};

#endif /* visible_obj_hpp */
