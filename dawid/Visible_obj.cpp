//
//  visible_obj.cpp
//  dawid
//
//  Created by Roza on 24/11/2019.
//  Copyright © 2019 Roza. All rights reserved.
//

#include "Visible_obj.hpp"
#include "game.hpp"
#include "MainMenu.hpp"
#include "back_screen.hpp"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>



visible_obj::visible_obj()
{
    is_loaded = false;
}


visible_obj::~visible_obj()
{
}

void visible_obj::load(std::string filename)
{
    if(image_.loadFromFile(filename) == false)
    {
        file_name = "";
        is_loaded = false;
    }
    else
    {
        file_name = filename;
        sprite_.setTexture(image_);
        is_loaded = true;
    }
}

void visible_obj::drawing(sf::RenderWindow & renderWindow)
{
    if(is_loaded)
    {
        renderWindow.draw(sprite_);
    }
}

void visible_obj::Update(float elapsedTime)
{
}

void visible_obj::set_position(float x, float y)
{
    if(is_loaded)
    {
        sprite_.setPosition(x,y);
    }
}


sf::Vector2f visible_obj::GetPosition() const
{
    if(is_loaded)
    {
        return sprite_.getPosition();
    }
    return sf::Vector2f();
}



float visible_obj::GetHeight() const
{
    return sprite_.getLocalBounds().height;
}

float visible_obj:: GetWidth() const
{
        return sprite_.getLocalBounds().width;
}

sf::Rect<float> visible_obj::GetBoundingRect() const
{
    return sprite_.getGlobalBounds();
}


sf::Sprite& visible_obj::GetSprite()
{
    return sprite_;
}

bool visible_obj::IsLoaded() const
{
    return is_loaded;
}
