#ifndef MARKER_H
#define MARKER_H

#include <SFML/Graphics.hpp>


class Marker: public sf::Drawable
{
public:
    Marker(sf::Vector2f pos);
    ~Marker();
    
private:
    sf::Vector2f pos{150.f, 150.f};
    sf::RectangleShape rect;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif