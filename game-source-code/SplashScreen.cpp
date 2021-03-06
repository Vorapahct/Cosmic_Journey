#include "SplashScreen.h"
#include <string>

SplashScreen::SplashScreen()
{
    _splashTexture.loadFromFile("Resources/Background.png");
}

void SplashScreen::show(sf::RenderWindow& renderWindow)
{
    sf::Sprite background;
    background.setTexture(_splashTexture);
    
    font.loadFromFile("Resources/Font.ttf");
    std::string splashTitle = "Cosmic Journey";
    sf::Text title(splashTitle, font);
    title.setCharacterSize(58);
    title.setPosition(renderWindow.getSize().x/4,renderWindow.getSize().y/4);
    title.setStyle(sf::Text::Bold);
    title.setColor(sf::Color::Yellow);
    
    std::string splashControls = "Controls"
                                 "\n -Left arrow key moves clockwise"
                                 "\n -Right arrow key moves anticlockwise"
                                 "\n -Space key fires bullet(s)"
                                 "\n \n Press Space key to continue...";
                                 
    sf::Text controls(splashControls,font);
    controls.setCharacterSize(25);
    controls.setPosition(renderWindow.getSize().x/4,renderWindow.getSize().y/2 - renderWindow.getSize().y/10);
    controls.setStyle(sf::Text::Bold);
    controls.setColor(sf::Color::Yellow);
    
    renderWindow.draw(background);
    renderWindow.draw(controls);
    renderWindow.draw(title);
    renderWindow.display();
    
    sf::Event event;
    while(true)
    {
        while (renderWindow.pollEvent(event))              
        {
            if(event.key.code == sf::Keyboard::Space){return;}
        }
    }
}

SplashScreen::~SplashScreen()
{
}