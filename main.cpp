#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

#include "Paddle.h"
#include "Ball.h"
#include "Asset.h"

using namespace std;

int main() {
    int WIN_W = 1000, WIN_H = 800;
    sf::RenderWindow window(sf::VideoMode(WIN_W,WIN_H,32),"Hello SFML"); // Makes The window
    window.setFramerateLimit(60);
    sf::Clock GameClock; // For delta time

    float Accel_X = 350, Accel_Y = 300, Opp_Acc = 300; //For acceleration
    Paddle Ply_Pad(10, ((WIN_H/2) - ((WIN_H/4)/2)), 30, WIN_H/4); //Player Paddle
    Paddle Opp_Pad(WIN_W - (10 + 30), ((WIN_H/2) - ((WIN_H/4)/2)), 30, WIN_H/4); //Player Paddle
    Ball GMball(5+ Ply_Pad.getSize().x, 10, 50, sf::Color::Cyan); // Ball

    sf::Font font;
    font.loadFromFile(Asset::Fonts::OpenSans::Bold);
    sf::Text PlyScore("0", font);
    sf::Text OppScore("0", font);
    PlyScore.setFillColor(sf::Color::White);
    OppScore.setFillColor(sf::Color::White);
    PlyScore.setPosition(80, 10);
    OppScore.setPosition(WIN_W - 80, 10);

    sf::SoundBuffer Pong_E4;
    sf::SoundBuffer Pong_E5;
    sf::Sound Pong_Blip;
    if (!Pong_E4.loadFromFile(Asset::Sound::Pong_E4)){
        std::cout << "Loading Asset::Pong_E4 failed!" << std::endl;
        return -1;
    }
    else{
        std::cout << "Loading Asset::Pong_E4 Succeeded!" << std::endl;
    }
    if (!Pong_E5.loadFromFile(Asset::Sound::Pong_E5)){
        std::cout << "Loading Assset::Pong_E5 failed!" << std::endl;
        return -1;
    }
    else{
        std::cout << "Loading Asset::Pong_E5 Succeeded!" << std::endl;
    }
    while(window.isOpen()){ //Main loop
        sf::Time currSec = GameClock.restart();//getting the clock reset
        int Ball_X = GMball.getPosition().x; //Position of The Ball in window
        int Ball_Y = GMball.getPosition().y; //Position of The Ball in window
        int Ball_W = GMball.getSize().x;    //Length og the ball
                int Mouse_Y = 0;
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
        if (Ball_X+Ball_W >= WIN_W ){ //checking if ball is hitting left and right side of the window
            Ply_Pad.changeScore(10);
            Accel_X = 350;
            Accel_Y = 300;
            GMball.setPosition(35, 10);
            Ball_X = GMball.getPosition().x; //Position of The Ball in window
            Ball_Y = GMball.getPosition().y; //Position of The Ball in window
        }
        if(Ball_X <= 0){
            Opp_Pad.changeScore(10);
            Accel_X = -350;
            Accel_Y = -300;
            GMball.setPosition(WIN_W - (Ball_W + 10), 10);
            Ball_X = GMball.getPosition().x; //Position of The Ball in window
            Ball_Y = GMball.getPosition().y; //Position of The Ball in window
        }
        if (Ball_Y+Ball_W >= WIN_H || Ball_Y < 0){ // checking if ball is hitting top and bottom of the window
            Accel_Y = -Accel_Y;
        }
        if(GMball.intersectAll(Ply_Pad)){
            Pong_Blip.setBuffer(Pong_E5);
            Accel_X = -Accel_X;
            Pong_Blip.play();
        }
        if(GMball.intersectAll(Opp_Pad)){
            Pong_Blip.setBuffer(Pong_E4);
            Accel_X = -Accel_X;
            Pong_Blip.play();
        }
        //game logic
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            Opp_Pad.move(0, Opp_Acc * currSec.asSeconds());
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            Opp_Pad.move(0, -Opp_Acc * currSec.asSeconds());
        }
        //Setting the ball Position
        GMball.setPosition(Ball_X + Accel_X * currSec.asSeconds(), Ball_Y + Accel_Y * currSec.asSeconds());
        int MSY = (sf::Mouse::getPosition(window).y);
        int MSX = (sf::Mouse::getPosition(window).x);
        Ply_Pad.setPosition(window.getSize().x - MSX, window.getSize().y - MSY);

        PlyScore.setString(std::to_string(Ply_Pad.getScore()));
        OppScore.setString(std::to_string(Opp_Pad.getScore()));

        window.clear(sf::Color::Black);
        window.draw(GMball.getShape());
        window.draw(Ply_Pad.getShape());
        window.draw(Opp_Pad.getShape());
        window.draw(PlyScore);
        window.draw(OppScore);
        window.display();

    }

    return 0;
}