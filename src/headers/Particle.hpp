#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

#include "GravitySource.hpp"
class Particle
{
    sf::Vector2f pos;
    sf::Vector2f velocity;

    sf::CircleShape s;

public:
    Particle(float pos_x, float pos_y, float velocity_x, float velocity_y)
    {
        this->pos.x = pos_x;
        this->pos.y = pos_y;

        this->velocity.x = velocity_x;
        this->velocity.y = velocity_y;

        s.setPosition(pos);
        s.setFillColor(sf::Color::White);
        s.setRadius(6);
    }

    void render(sf::RenderWindow &window)
    {
        s.setPosition(pos);
        window.draw(s);
    }

    void set_color(sf::Color color)
    {
        s.setFillColor(color);
    }

    void update_physics(GravitySource &s)
    {
        float distance_x = s.get_pos().x - pos.x;
        float distance_y = s.get_pos().y - pos.y;

        float distance = sqrt(distance_x * distance_x + distance_y * distance_y);

        float inverse_distance = 1.f / distance;

        float normalized_x = inverse_distance * distance_x;
        float normalized_y = inverse_distance * distance_y;

        float inverse_square_dropoff = inverse_distance * inverse_distance;

        float accleration_x = normalized_x * s.get_strength() * inverse_square_dropoff;
        float accleration_y = normalized_y * s.get_strength() * inverse_square_dropoff;

        velocity.x += accleration_x;
        velocity.y += accleration_y;

        pos.x += velocity.x;
        pos.y += velocity.y;
    }
};
#endif