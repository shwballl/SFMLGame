  
#include <iostream>
#include <SFML\Graphics.hpp>
 
class Player  : public sf::Sprite {
public:
    Player(){
        //Default
    }
 
    Player(std::string imgDirectory){
        if(!pTexture.loadFromFile(imgDirectory)){
            std::cerr << "Error\n";
        }
        pSprite.setTexture(pTexture);
    }

    
    void drawPlayer(sf::RenderWindow &window){
        window.draw(pSprite);
    }

    void setPosition(float x, float y){
        pSprite.setPosition(x,y);
    }

    float getPositionX(){
        return pSprite.getPosition().x;
    }
    float getPositionY(){
        return pSprite.getPosition().y;
    }
    float getLocalBoundsWidth(){
        return pSprite.getLocalBounds().width;
    }
    float getLocalBoundsHeight(){
        return pSprite.getLocalBounds().height;
    }
    sf::FloatRect getGloabalBounds(){
        return pSprite.getGlobalBounds();
    }


    void movePlayer(char direction, float moveSpeed){
        switch (direction)
        {
            case 'l':
                pSprite.move(-moveSpeed, 0);
                break;
            case 'r':
                pSprite.move(moveSpeed, 0);
                break;
            case 's':
                pSprite.move(0, 0);
                break;
        }
    }

private:
    sf::Texture pTexture;
    sf::Sprite pSprite;
};