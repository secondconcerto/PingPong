

#include "HUD.hpp"
#include "game.hpp"
#include "player_paletka.hpp"
#include "paletka_2.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

HUD::HUD(){
    player=nullptr;
    player2=nullptr;
    font.loadFromFile("Zapfino.ttf");
    text.setFont(font);
    text.setCharacterSize(30);
    text.setPosition((Game::SCREEN_WIDTH/2)-170, Game::SCREEN_HEIGHT/2);
    text.setFillColor(sf::Color(59, 10, 75));
}
HUD::~HUD(){}

void HUD::SetPlayer(player_paletka * _player){
    player=_player;
}
void HUD::SetPaletka(Paletka_2 * _player2){
    player2=_player2;
}
void HUD::Show(sf::RenderWindow& window){
    text.setString("UNICORN: "+std::to_string(player->score)+ "\n\t" + " YOU: "+ std::to_string(player2->score));
    window.draw(text);
}
