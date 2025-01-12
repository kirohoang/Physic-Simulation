#ifndef GRAVITYSOURCE_HPP
#define GRAVITYSOURCE_HPP

#include <SFML/Graphics.hpp>

class GravitySource
{
    sf::Vector2f pos;
    float strength; // how strong is the gravity
    
    sf::CircleShape s;

public:
    GravitySource(float pos_x, float pos_y, float strength)
    {
        pos.x = pos_x;
        pos.y = pos_y;
        this->strength = strength;

        s.setPosition(pos);
        s.setFillColor(sf::Color::White);
        s.setRadius(10);
    }

    void render(sf::RenderWindow &window)
    {
        window.draw(s);
    }

    sf::Vector2f get_pos()
    {
        return pos;
    }

    float get_strength()
    {
        return strength;
    }
};
#endif