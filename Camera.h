#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Camera
{
public:
    Camera(sf::Vector2f size);
    ~Camera(){};

    void updateEvent(sf::Event & event);
    void update(sf::RenderWindow & window);

    void zoom(float delta);

    sf::View & getView() { return view; }
private:
    sf::View view;

    bool scrolled = false;
    sf::Vector2f mousePreviousWorldPos{0.f, 0.f};
};

#endif