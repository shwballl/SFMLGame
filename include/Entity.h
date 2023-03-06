#include <iostream>
#include <SFML\Graphics.hpp>


class Entity{
public:
    Entity(){
    }
 
    Entity(std::string imgDirectory){
        if(!pTexture.loadFromFile(imgDirectory)){
            std::cerr << "Error\n";
        }
        pSprite.setTexture(pTexture);
    }
 
    void drawEntity(sf::RenderWindow &window){
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
    sf::FloatRect getGlobalBounds(){
        return pSprite.getGlobalBounds();
    }

    void movePlayer(float moveSpeed){
        pSprite.move(0, moveSpeed);
    }

    void Stop(){
        pSprite.move(0, 0);
    }
    void rotate(float angle){
        pSprite.rotate(angle);
    }

private:
    sf::Texture pTexture;
    sf::Sprite pSprite;
};