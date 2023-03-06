#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/Player.h"
#include "include/Entity.h"
#include <time.h>



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

int main(){
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Game");


    Player player("C:/prog/cosm.png");
    player.setPosition(0, 600);


    sf::Font font;
    font.loadFromFile("C:/prog/TiltWarp-Regular.ttf");
    sf::Text text;
    text.setString("Game Over!");
    text.setCharacterSize(32);
    text.setFont(font);
    text.setColor(sf::Color::Red);
    text.setPosition(420, 250);
    sf::Text text2;
    text2.setString("Press Enter to restart or Q to quit");
    text2.setCharacterSize(32);
    text2.setFont(font);
    text2.setColor(sf::Color::Red);
    text2.setPosition(420, 300);

    //Vectors off bottom blocks/////////////////////////////////
    std::vector<Entity*> vect;
    vect.reserve(10);
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
    ////////////////////////////////////////////////////////////


    //Enemies creation////////////////
    std::vector<Entity*> enemies;
    enemies.reserve(20);
    for (size_t i = 0; i < 20; i++)
    {
        enemies.push_back(new Entity("C:/prog/asteroid.png"));
        setRandomPos(enemies[i]);
        
    }
    
    /////////////////////////////////



    while(window.isOpen()){
       
        sf::Event Event;
        while(window.pollEvent(Event)){
            switch(Event.type){
 
            case sf::Event::Closed:
                window.close();
            }
        }



        //Move operations///////////////////////////////////
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            player.movePlayer('l', 3.0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player.movePlayer('r', 3.0);
        }
        ////////////////////////////////////////////////////

        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            for (size_t i = 0; i < 20; i++)
            {
                enemies[i]->movePlayer(rand()%5);
            }
        }

        //Colision Detection///////////////////////////////////
        if (player.getPositionX() < 0)
        {
            player.setPosition(0, 600);
        }
        if (player.getPositionX() + player.getLocalBoundsWidth() > 1280)
        {
            player.setPosition(1280 - player.getLocalBoundsWidth(), 600);
        }
        for (size_t i = 0; i < 20; i++)
        {
            if (enemies[i]->getPositionY() + 64 > 720)
            {
                setRandomPos(enemies[i]);
            };
        }
        ////////////////////////////////////////////////////////
        
        

        //Render objects//////////////////////////////
        window.clear(sf::Color::Black);

        player.drawPlayer(window);

        for (size_t i = 0; i < 20; i++)
        {
            CheckEnemyColision(enemies[i], player, window, text, text2);
        }    

        for (size_t i = 0; i < 20; i++)
        {
            enemies[i]->drawEntity(window);
        }
        for (size_t i = 0; i < 10; i++)
        {
            vect[i]->drawEntity(window);
        }

        window.display();
        ////////////////////////////////////////
    }
    for (size_t i = 0; i < 10; i++)
    {
        delete vect[i];
    }
    for (size_t i = 0; i < 20; i++)
    {
        delete enemies[i];
    }
}
