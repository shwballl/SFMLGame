#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"
#include <time.h>

class Game
{
private:
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Game");
    Player player("C:/prog/cosm.png");
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    std::vector<Entity*> vect;
    std::vector<Entity*> enemies;
public:
    Game(/* args */){
        player.setPosition(0, 600);
        font.loadFromFile("C:/prog/TiltWarp-Regular.ttf");
        text.setString("Game Over!");
        text.setCharacterSize(32);
        text.setFont(font);
        text.setColor(sf::Color::Red);
        text.setPosition(420, 250);
        text2.setString("Press Enter to restart or Q to quit");
        text2.setCharacterSize(32);
        text2.setFont(font);
        text2.setColor(sf::Color::Red);
        text2.setPosition(420, 300);
        for (size_t i = 0; i < 10; i++)
        {
            vect.push_back(new Entity("C:/prog/dirt.png"));
        }
        vect[0]->setPosition(0, 655);
        int j = 1;
        int k = 0;
        while (j<=9)
        {
            vect[j]->setPosition((float)k+128, 655);
            ++j;
            k+=128;
        }
        enemies.reserve(20);
        for (size_t i = 0; i < 20; i++)
        {
            enemies.push_back(new Entity("C:/prog/asteroid.png"));
            setRandomPos(enemies[i]);
            
        }
    };
    ~Game();


    void update(){
        while(window.isOpen()){
       
        sf::Event Event;
        while(window.pollEvent(Event)){
            switch(Event.type){
 
            case sf::Event::Closed:
                window.close();
            }
        }
        
        }
    }

    void run(){

    }

    void setRandomPos(Entity* enemies){
        for (size_t i = 0; i < 20; i++)
        {
            enemies->setPosition(rand()%1000, -rand()%1000);
        }     
    }

    void CheckEnemyColision(Entity *enemies, Player &player, sf::RenderWindow &window,sf::Text text, sf::Text text2){
        if(enemies->getPositionX() <= player.getPositionX() + player.getGloabalBounds().width && enemies->getPositionX() + enemies->getGlobalBounds().width >= player.getPositionX() && enemies->getPositionY() <= player.getPositionY() + player.getGloabalBounds().height && enemies->getPositionY() + enemies->getGlobalBounds().height >= player.getPositionY()){
            window.draw(text);
            window.draw(text2);
            for (size_t i = 0; i < 10000; i++)
            {
                
            }
            
            while (enemies->getPositionX() <= player.getPositionX() + player.getGloabalBounds().width && enemies->getPositionX() + enemies->getGlobalBounds().width >= player.getPositionX() && enemies->getPositionY() <= player.getPositionY() + player.getGloabalBounds().height && enemies->getPositionY() + enemies->getGlobalBounds().height >= player.getPositionY())
            {
                enemies->Stop();
                window.draw(text);
                window.draw(text2);
                player.setPosition(player.getPositionX(), player.getPositionY());
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    setRandomPos(enemies);
                    player.setPosition(0,player.getPositionY());
                }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
                    window.close();
                }
            }
        }
    }
};
