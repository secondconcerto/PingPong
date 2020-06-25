
#include "Ball.hpp"
#include "game.hpp"
#include "Menager.hpp"
#include "Visible_obj.hpp"
#include <cmath>
#include <SFML/Audio.hpp>

Ball::Ball() : _velocity(0.0f),_elapsedTimeSinceStart(0.0f)
{
    //320
    load("ball3.png");
    assert(IsLoaded());
    score=true;
    
//    GetSprite().setOrigin(15,15);
GetSprite().setOrigin(GetSprite().getLocalBounds().width /2, GetSprite().getLocalBounds().height / 2);
    float random_integer = std::rand() % 360 + 1; 
    _angle = random_integer;
}


Ball::~Ball()
{
}

float Ball::GetVelocity() const
{
    return _velocity;
}


void  Ball::Update(float elapsedTime)
{
    _elapsedTimeSinceStart += elapsedTime;
    _velocity=320.0f;
    

    if(_elapsedTimeSinceStart < 3.0f){
        score=true;
        GetSprite().setPosition((Game::SCREEN_WIDTH/2),(Game::SCREEN_HEIGHT/2)-15);
        _velocity=0.0f;
        GetSprite().setColor(sf::Color(0,0,0,0));
        
        return;
        
    }
    score=false;
    GetSprite().setColor(sf::Color(255,255,255,255));
        
    
    float moveAmount = _velocity  * elapsedTime;
    
    
    float moveByX = LinearVelocityX(_angle) * moveAmount;
    float moveByY = LinearVelocityY(_angle) * moveAmount;
    
    

    if(GetPosition().x + moveByX <= 0 + GetWidth()/2 || GetPosition().x + GetHeight()/2 + moveByX >= Game::SCREEN_WIDTH)
    {

        _angle = 360.0f - _angle;
        if(_angle > 260.0f && _angle < 280.0f) _angle += 20.0f;
        if(_angle > 80.0f && _angle < 100.0f) _angle += 20.0f;
        moveByX = -moveByX;
    }
    
 
    
 player_paletka* player1 = dynamic_cast<player_paletka*>(Game::GetGameObjectManager().Get("Paddle1"));
    if(player1 != NULL)
    {
        sf::Rect<float> p1BB = player1->GetBoundingRect();
        
        if(p1BB.intersects(GetBoundingRect()))
        {
            _angle =  360.0f - (_angle - 180.0f);
            if(_angle > 360.0f) _angle -= 360.0f;
            
            
            
            moveByY = -moveByY;
            

            if(GetBoundingRect().width > player1->GetBoundingRect().top)
            {
                set_position(GetPosition().x,player1->GetBoundingRect().top - GetWidth()/2 -1 );
            }
            

            float playerVelocity = player1->GetVelocity();
            
            if(playerVelocity < 0)
            {

                _angle -= 20.0f;
                if(_angle < 0 ) _angle = 360.0f - _angle;
            }
            else if(playerVelocity > 0)
            {
                _angle += 20.0f;
                if(_angle > 360.0f) _angle = _angle - 360.0f;
            }
            

            _velocity += 5.0f;
        }
        
        if(GetPosition().y - GetHeight()/2 <= 0)
        {
            _angle =  180 - _angle;
            moveByY = -moveByY;
        }
        
        
        
        if(GetPosition().y + GetHeight()/2 + moveByY >= Game::SCREEN_HEIGHT)
        {

            GetSprite().setPosition(Game::SCREEN_WIDTH/2, Game::SCREEN_HEIGHT/2);
            _angle = (rand()%360)+1;
            _velocity = 230.0f;
            _elapsedTimeSinceStart = 0.0f;
             player1->score += 1;
        }
        
        GetSprite().move(moveByX,moveByY);
    }
    
    
    Paletka_2* player2 = dynamic_cast<Paletka_2*>(Game::GetGameObjectManager().Get("Paddle2"));
    
    if(player2 != NULL)
    {
        sf::Rect<float> p1BB = player2->GetBoundingRect();

        if(p1BB.intersects(GetBoundingRect()))
        {
            _angle =  360.0f - (_angle - 180.0f);
            if(_angle > 360.0f) _angle -= 360.0f;



            moveByY = -moveByY;

 
            if(GetBoundingRect().width < player2->GetBoundingRect().top)
            {
                set_position(GetPosition().x,player2->GetBoundingRect().top - GetWidth()/2 -1 );
            }


            float playerVelocity = player2->GetVelocity();
            
            if(playerVelocity < 0)
            {

                _angle -= 20.0f;
                if(_angle < 0 ) _angle = 360.0f - _angle;
            }
            else if(playerVelocity > 0)
            {
                _angle += 20.0f;
                if(_angle > 360.0f) _angle = _angle - 360.0f;
            }
            
     
            _velocity += 5.0f;
        }
        
        if(GetPosition().y - GetHeight()/2 <= 0)
        {
            _angle =  180 - _angle;
            moveByY = -moveByY;
        }
        
     
        if(( GetPosition().y - GetHeight() / 2 - moveByY <= 0))
        {
          
            GetSprite().setPosition(Game::SCREEN_WIDTH/2, Game::SCREEN_HEIGHT/2);
            _angle = (rand()%360)+1;
            _velocity = 230.0f;
            _elapsedTimeSinceStart = 0.0f;
            player2->score += 1;
        }
        
        GetSprite().move(moveByX,moveByY);
    }
    

}



float Ball::LinearVelocityX(float angle)
{
    angle -= 90;
    if (angle < 0) angle = 360 + angle;
    return (float)std::cos( angle * ( 3.1415926 / 180.0f ));
}

float Ball::LinearVelocityY(float angle)
{
    angle -= 90;
    if (angle < 0) angle = 360 + angle;
    return (float)std::sin( angle * ( 3.1415926 / 180.0f ));
}

