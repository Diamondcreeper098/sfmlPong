#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "Paddle.h"
#include "Ball.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800,600,32),"Hello SFML"); // Makes The window
    sf::Clock GameClock; // For delta time
    float Accel_X = 350, Accel_Y = 300; //For acceleration
    Paddle Ply_Pad(5, 10, 30, 600/4); //Player Paddle
    Ball GMball(5+ Ply_Pad.getSize().x, 10, 50, sf::Color::Cyan); // Ball
    while(window.isOpen()){ //Main loop
        sf::Time currSec = GameClock.restart();//getting the clock reset
        int Ball_X = GMball.getPosition().x; //Position of The Ball in window
        int Ball_Y = GMball.getPosition().y; //Position of The Ball in window
        int Ball_W = GMball.getSize().x;    //Length og the ball
        sf::Event event; //getting events
        while (window.pollEvent(event)){ //Event loop
            if (event.type == sf::Event::Closed){
                window.close();
            } else if(event.type == sf::Event::KeyPressed){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window.close();
                }
            }
        }
        //Game physics
        if (Ball_X+Ball_W > 800 || Ball_X < 0){ //checking if ball is hitting left and right side of the window
            Accel_X = -Accel_X;
        }
        if (Ball_Y+Ball_W >= 600 || Ball_Y < 0){ // checking if ball is hitting top and bottom of the window
            Accel_Y = -Accel_Y;
        }
        //Setting the ball Position
        GMball.setPosition(Ball_X + Accel_X * currSec.asSeconds(), Ball_Y + Accel_Y * currSec.asSeconds());
        window.clear(sf::Color::Black);
        window.draw(GMball.getShape());
        window.draw(Ply_Pad.getShape());
        window.display();

    }

    return 0;
}