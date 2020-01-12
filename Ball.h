//
// Created by seyed ali on 1/12/20.
//

#ifndef SFMLGAME_BALL_H
#define SFMLGAME_BALL_H

#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball {
private:
    sf::RectangleShape BallShape;
    int Ball_Y;
    int Ball_X;
    int Ball_W;
    int Ball_H;
    sf::Color col;
public:
    Ball(int x, int y, int w, sf::Color _color);
    bool intersectAll(Paddle &pad);
    bool intersectX(Paddle &pad);
    bool intersectY(Paddle &pad);
    void setPosition(int x, int y);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    void move(int x, int y);
    sf::RectangleShape getShape();
};


#endif //SFMLGAME_BALL_H
