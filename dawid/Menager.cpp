
#include "Menager.hpp"
#include "Visible_obj.hpp"
#include "game.hpp"
#include <iostream>
#include <map>
#include <iostream>
#include <cassert>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

menager::menager()
{
}

menager::~menager()
{
std::for_each(_gameObjects.begin(),_gameObjects.end(),object_delocation());

}
void menager::Add(std::string name, visible_obj* gameObject)
{
    _gameObjects.insert(std::pair<std::string,visible_obj*>(name,gameObject));
}

void menager::Remove(std::string name)
{
    std::map<std::string, visible_obj*>::iterator results = _gameObjects.find(name);
    if(results != _gameObjects.end() )
    {
        delete results->second;
        _gameObjects.erase(results);
    }
}

visible_obj* menager::Get(std::string name) const
{

    std::map<std::string, visible_obj*>::const_iterator results = _gameObjects.find(name);
    if(results == _gameObjects.end() )
        return NULL;
    return results->second;
    
    
}

int menager::GetObjectCount() const
{
    return _gameObjects.size();
}


void menager::DrawAll(sf::RenderWindow& renderWindow)
{
    std::map<std::string,visible_obj*>::const_iterator itr = _gameObjects.begin();
    while(itr != _gameObjects.end())
    {
        itr->second->drawing(renderWindow);
        itr++;
    }
}

void menager::Update_all()
{

    std::map<std::string,visible_obj*>::const_iterator itr = _gameObjects.begin();
    float timeDelta = clock.restart().asSeconds();
    
    while(itr != _gameObjects.end())
    {
        itr->second->Update(timeDelta);
        itr++;
    }
    
}


