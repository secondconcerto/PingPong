

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <iostream>
#include <cassert>

#include "back_screen.hpp"


void back_screen::Show(sf::RenderWindow & renderWindow)

{
   
    sf::Texture image;
    if(image.loadFromFile("pang.main.png") != true)
    {
        return;
    }
    
    sf::Sprite sprite(image);
    
    renderWindow.draw(sprite);
    renderWindow.display();
    
    sf::Event event;
    while(true)
    {
        while(renderWindow.pollEvent(event))
        {
            if(event.type == sf::Event::EventType::KeyPressed
               || event.type == sf::Event::EventType::MouseButtonPressed
               || event.type == sf::Event::EventType::Closed )
            {
                return;
            }
        }
    }
}
