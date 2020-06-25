

#include "MainMenu.hpp"
#include "back_screen.hpp"
#include "player_paletka.hpp"
#include "Visible_obj.hpp"
#include "Ball.hpp"
#include "paletka_2.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <iostream>
#include <cassert>





void Game::Start(void)
{
    if(_gameState != Uninitialized)
        return;
   
    

    
    _mainWindow.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32),"Heart-pong <3 ");
   
    
    player_paletka *player1 = new player_paletka();
    player1->set_position((SCREEN_WIDTH/2),700);
    _hud.SetPlayer(player1);
    
    Ball *ball = new Ball();
    ball->set_position((SCREEN_WIDTH/2),(SCREEN_HEIGHT/2)-15);
    
    Paletka_2 * player2 = new Paletka_2();
    player2->set_position((SCREEN_WIDTH/2),40);
    _hud.SetPaletka(player2);


    _gameObjectManager.Add("Paddle1",player1);
    _gameObjectManager.Add("Ball",ball);
    _gameObjectManager.Add("Paddle2",player2);
  
   
    
    _gameState= Game::ShowingSplash;
    
    sf::Music music;
    music.openFromFile("PINK.ogg");
    music.play();
    music.setLoop(true);

    
    while(!IsExiting())
    {
        GameLoop();
    }
    
    _mainWindow.close();
}

sf::RenderWindow& Game::GetWindow()
{
    return _mainWindow;
}

const sf::Event& Game::GetInput()
{
    sf::Event currentEvent;
    _mainWindow.pollEvent(currentEvent);
    return currentEvent;
}

bool Game::IsExiting()
{
    if(_gameState == Game::Exiting)
        return true;
    else
        return false;
}

const menager& Game::GetGameObjectManager()
{
    return Game::_gameObjectManager;
}



void Game::GameLoop()
{
    {
        sf::Event currentEvent;
        _mainWindow.pollEvent(currentEvent);
        
        
        switch(_gameState)
        {
            case Game::ShowingMenu:
            {
                ShowMenu();
                break;
            }
            
            case Game::ShowingSplash:
            {
                show_back_screen();
                break;
            }
            
            case Game::Playing:
            {
           Ball* ball= dynamic_cast<Ball*>(Game::GetGameObjectManager().Get("Ball"));
                _mainWindow.clear(sf::Color(245, 223, 245));
            if(ball->score==true)
                _hud.Show(_mainWindow);

               _gameObjectManager.DrawAll(_mainWindow);
                
                _gameObjectManager.Update_all();

                _mainWindow.display();

                if(currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;
                
                if(currentEvent.type == sf::Event::KeyPressed)
                {
                    if(currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
                }
                
                break;
            }
   
        }
    
}
}
void Game::show_back_screen()
{
    back_screen splashScreen;
    splashScreen.Show(_mainWindow);
    _gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
    switch(result)
    {
        case MainMenu::Exit:
            _gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            _gameState = Game::Playing;
            break;
    }
}



Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
menager Game::_gameObjectManager;
HUD Game::_hud;

