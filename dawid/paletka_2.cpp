

#include "paletka_2.hpp"
#include "game.hpp"
#include "Ball.hpp"
#include "Visible_obj.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


Paletka_2::Paletka_2() :_velocity(0),_maxVelocity(1000.0f), score(0)
{
    load("paddle2.png");
    assert(IsLoaded());
    
    GetSprite().setOrigin(GetSprite().getLocalBounds().width /2, GetSprite().getLocalBounds().height / 2);
    
    
}


Paletka_2::~Paletka_2()
{
}

void Paletka_2::Draw(sf::RenderWindow & rw)
{
    visible_obj::drawing(rw);
}

float Paletka_2::GetVelocity() const
{
    return _velocity;
}

void Paletka_2::Update(float elapsedTime)
{
    
    
    
    const Ball* gameBall = static_cast<Ball*>
    (Game::GetGameObjectManager().Get("Ball"));
    sf::Vector2f ballPosition = gameBall->GetPosition();
    
    

    if(GetPosition().x  < ballPosition.x)
        _velocity += 150.0f;
    
    else if(GetPosition().x > ballPosition.x)
        _velocity -= 150.0f;
    
    if(gameBall->GetVelocity()==0.0f){
        GetSprite().setPosition((Game::SCREEN_WIDTH/2),40);
        _velocity = 0.0f;
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
