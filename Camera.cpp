#include "Camera.h"

Camera::Camera(sf::Vector2f size)
{
    view.reset({0, 0, size.x, size.y});
}

void Camera::updateEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::LAlt)
            scrolled = true;
    }
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::LAlt)
            scrolled = false;
    }
    if (event.type == sf::Event::MouseWheelScrolled)
    {
        std::cout << event.mouseWheelScroll.delta << std::endl;
        zoom(event.mouseWheelScroll.delta);
    }
}

void Camera::update(sf::RenderWindow & window)
{
    sf::Vector2f mouseWorldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window), view);
    if (scrolled)
    {   
        view.move(mousePreviousWorldPos - mouseWorldPos);
        mousePreviousWorldPos = mouseWorldPos + (mousePreviousWorldPos - mouseWorldPos);
    }
    else 
        mousePreviousWorldPos = mouseWorldPos;
}

void Camera::zoom(float delta)
{
    view.zoom(1.f - delta / 10.f);
}