#include "Marker.h"

Marker::Marker(sf::Vector2f pos):
    pos(pos)
{
    rect.setFillColor(sf::Color::Red);
    rect.setSize(sf::Vector2f(32.f, 16.f));
    rect.setOrigin(16.f, 8.f);
    rect.setPosition(pos);
}

Marker::~Marker()
{
}

void Marker::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(rect);
}