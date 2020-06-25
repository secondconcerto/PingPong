

#include "player_paletka.hpp"
#include "Visible_obj.hpp"
#include "game.hpp"
#include "MainMenu.hpp"
#include "back_screen.hpp"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

player_paletka::player_paletka() : _velocity(0),_maxVelocity(650.0f), score(0)
{
    load("paddle3.png");
    assert(IsLoaded());
    
GetSprite().setOrigin(GetSprite().getLocalBounds().width /2, GetSprite().getLocalBounds().height / 2);
}

void player_paletka::Draw(sf::RenderWindow & rw)
{
   visible_obj::drawing(rw);
}


player_paletka::~player_paletka()
{
}

float player_paletka::GetVelocity() const
{
    return _velocity;
}

void player_paletka::Update(float elapsedTime)
{
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _velocity-= 3.0f;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _velocity+= 3.0f;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        _velocity= 0.0f;
    }
    
    if(_velocity > _maxVelocity)
        _velocity = _maxVelocity;
    
    if(_velocity < -_maxVelocity)
        _velocity = -_maxVelocity;
    
    
    sf::Vector2f pos = this->GetPosition();
    if(pos.x  <= GetSprite().getLocalBounds().width/2)
    {
        _velocity = -_velocity;
        GetSprite().setPosition((GetSprite().getLocalBounds().width / 2) + 1, GetSprite().getPosition().y);
        
    }
    
    if(pos.x >= (Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width/2))
    {
        
        
        _velocity = -_velocity; 
        GetSprite().setPosition((Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2) - 1, GetSprite().getPosition().y);
        
        
    }
    
    GetSprite().move(_velocity * elapsedTime, 0);
}
