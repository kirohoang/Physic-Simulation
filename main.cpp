#include <SFML/Graphics.hpp>
#include "./src/headers/GravitySource.hpp"
#include "./src/headers/Particle.hpp"

sf::Color map_val_to_color(float value) // value is 0-1
{
    if (value < 0.0f)
        value = 0;
    if (value > 1.0f)
        value = 1;

    int r = 0, g = 0, b = 0;

    // 0 - 0.5 interp blue to green
    // 0.5 - 1 interp green to red

    if (value < 0.5f)
    {
        b = 255 * (1.0f - 2 * value);
        g = 255 * 2 * value;
    }
    else
    {
        g = 255 * (2.f - 2 * value);
        r = 255 * (2 * value - 1);
    }

    return sf::Color(r, g, b);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({1600, 900}), "Physics Simulation");
    window.setFramerateLimit(60);

    // GravitySource source(800, 500, 7000);

    // Paricle particle(600, 700, 5, 0);

    std::vector<GravitySource> sources;

    sources.push_back(GravitySource(500, 500, 7000));
    sources.push_back(GravitySource(1200, 500, 7000));

    int num_particle = 2000;

    std::vector<Particle> particles;

    for (int i = 0; i < num_particle; i++)
    {
        particles.push_back(Particle(600, 700, 4, 0.2 + (0.1 / num_particle) * i));

        // Change color
        float val = (float)i / (float)num_particle;

        sf::Color col = map_val_to_color(val);

        particles[i].set_color(col);
    }

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        // particle.update_physics(source);

        // source.render(window);
        // particle.render(window);
        for (int i = 0; i < sources.size(); i++)
        {
            for (int j = 0; j < particles.size(); j++)
            {
                particles[j].update_physics(sources[i]);
            }
        }

        for (int i = 0; i < sources.size(); i++)
        {
            sources[i].render(window);
        }

        for (int j = 0; j < particles.size(); j++)
        {
            particles[j].render(window);
        }

        window.display();
    }
}