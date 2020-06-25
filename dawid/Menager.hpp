/**
 * @file Menager.hpp
 * @brief The file contains class which manipulate the visible obejcts.
 * @author Oliwia Mlonek
 */

#ifndef Menager_hpp
#define Menager_hpp



#include "Visible_obj.hpp"
#include <iostream>
#include <map>
#include <iostream>
#include <cassert>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


/**
 * @class menager
 * @brief Responspible for holding all of our visibe objects, being in charge of updating, drawing and then finally removing them.
 */
class menager
{
public:
    /**
     * Create the menager object.
     */
    menager();
    
    /**
     * Destroys objects.
     */
    ~menager();
    
    
    /**
     * Function creates  map _gameObjects which is composed of a collection of std::pair<> objects and adds one more.
     * @param name a string which holds the name as the identifier.
     * @param gameObject a Visible_obj pointer.
     */
    void Add(std::string name, visible_obj* gameObject);
    
    /**
     * Function deletes the pointer to the Visible_obj* referred to in results->second.
     * @param name a string which holds the name as the identifier.
     */
    void Remove(std::string name);
    
    /**
     * Function returns the size of the map.
     * @return the number of items contained in the map.
     */
    int GetObjectCount() const;
    
    /**
     * Function iterates through the map.
     * @param name a string which holds the name as the identifier.
     * @return second value from a pair collected in a map.
     */
    visible_obj * Get(std::string name) const;
    
    /**
     * Function updates elapsed time of visible objects from a map.
     */
    void Update_all();
    
    /**
     * Function loops through all of the items stored within map and calls the Visible_obj’s Draw method.
     * @param renderWindow is a created window.
     */
    void DrawAll(sf::RenderWindow& renderWindow);
    

   
private:
    std::map<std::string, visible_obj*> _gameObjects;
    sf::Clock clock;
    
    /**
     * A struct which holds a functor to delete a Visible_obj pointer.
     */
    struct object_delocation
    {
        
        /**
         * Overloaded function operator ().
         */
        void operator()(const std::pair<std::string,visible_obj*> & p) const
        {
            delete p.second;
        }
    };
};
#endif /* menager_hpp */
