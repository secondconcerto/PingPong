


#include "MainMenu.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <iostream>
#include <cassert>






MainMenu::MenuResult MainMenu::Show( sf::RenderWindow& window)
{
    
    sf::Texture image;
    image.loadFromFile("Mainmenu2.png");
    sf::Sprite sprite(image);
    
   
    MenuItem playButton;
    playButton.rect = sf::Rect<int> (0, 145, 1023, 235);
    playButton.action = Play;
   
    
    MenuItem exitButton;
    exitButton.rect = sf::Rect<int> (0, 383, 1023, 177);
    exitButton.action = Exit;
    
    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);
    
    window.draw(sprite);
    window.display();
    
    return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;
    
    for (it = _menuItems.begin(); it != _menuItems.end(); it++) {
        sf::Rect<int> menuItemRect = (*it).rect;
        if ((menuItemRect.top + menuItemRect.height) > y&& menuItemRect.top < y && menuItemRect.left<x && (menuItemRect.width + menuItemRect.left)>x) {
            return (*it).action;
        }
    }
    return Nothing;
}



MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event menuEvent;
    
    while(42 != 43)
    {
        
        while(window.pollEvent(menuEvent))
        {
            if(menuEvent.type == sf::Event::MouseButtonPressed)
            {

                return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
            }
            if(menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}
