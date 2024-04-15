#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class SimpleBullet {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f velocity;
    bool active;

public:
    SimpleBullet() {
        active=true;
        setVelocity(sf::Vector2f(5.0f, 0.0f));
    } 

    void loadTexture(const std::string& texturePath) {
        //if (!texture.loadFromFile(texturePath)) {
        //    std::cerr << "Failed to load texture from file: " << texturePath << std::endl;
        //    // Handle error if texture loading fails
        //}
        texture.loadFromFile(texturePath);
        std::cerr << "file: " << texturePath << std::endl;
        sprite.setTexture(texture);
    }

    void activate(const sf::Vector2f& position) {
        sprite.setPosition(position);
        active = true;
    }

    void update(float deltaTime) {
        if (active) {
            // Update bullet position based on velocity and deltaTime
            //std::cout<< deltaTime << std::endl;
            sprite.move(velocity * deltaTime);
        }
    }

    void draw(sf::RenderWindow& window) {
        if (active) {
            window.draw(sprite);
        }
    }

    bool isActive() const {
        return active;
    }

    sf::Vector2f getVelocity() const {
        return velocity;
    }

    // Setter for velocity
    void setVelocity(const sf::Vector2f& newVelocity) {
        velocity = newVelocity;
    }
    

    // Add more methods as needed, such as getters and setters for velocity, etc.
};
