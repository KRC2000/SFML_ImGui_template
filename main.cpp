#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <imgui.h>
#include <imgui-SFML.h>

#include "Camera.h"
#include "Marker.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    
    Camera cam({300.f, 200.f});

    Marker m1({150.f, 50.f}), m2({100.f, 100.f});

    bool viewScrolled = false;

    sf::Clock deltaClock;
    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);
            cam.updateEvent(event);

            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::LAlt)
                    viewScrolled = true;
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::LAlt)
                    viewScrolled = false;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                //if (event.mouseButton.button == sf::Mouse::Middle)
                     // viewScrolled = true;
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                // if (event.mouseButton.button == sf::Mouse::Middle)
                //     viewScrolled = false;
            }
        }

        if (viewScrolled)
        {
            
        }

        ImGui::SFML::Update(window, deltaClock.restart());
        cam.update(window);

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        window.setView(cam.getView());
        window.clear();

        window.draw(m1);
        window.draw(m2);

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}