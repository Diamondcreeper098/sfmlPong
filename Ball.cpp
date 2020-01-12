//
// Created by seyed ali on 1/12/20.
// Ball class
//

#include "Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball(int x, int y, int w, sf::Color _color) {
    Ball_X = x;Ball_Y = y;Ball_W = w; Ball_H = w;
    BallShape = sf::RectangleShape(sf::Vector2f(w,w));
    BallShape.setFillColor(_color);
    BallShape.setPosition(x,y);
}

void Ball::setPosition(int x, int y) {
    Ball_X = x; Ball_Y = y;
    BallShape.setPosition(x,y);
}

sf::Vector2f Ball::getPosition() {
    return sf::Vector2f(Ball_X, Ball_Y);
}

sf::RectangleShape Ball::getShape() {
    return BallShape;
}

bool Ball::intersectAll(Paddle &pad) {
    int padx = pad.getPosition().x;
    int pady = pad.getPosition().y;
    int padW = pad.getSize().x;
    int padH = pad.getSize().y;
    if(padx < Ball_X + Ball_W && padx + padW > Ball_X && pady < Ball_Y+Ball_H && pady + padH > Ball_Y){
        return true;
    }
    return false;
}

bool Ball::intersectX(Paddle &pad) {
    int padx = pad.getPosition().x;
    int padW = pad.getSize().x;
    if(padx < Ball_X + Ball_W && padx + padW > Ball_X){
        return true;
    }
    return false;
}
bool Ball::intersectY(Paddle &pad) {
    int pady = pad.getPosition().y;
    int padH = pad.getSize().y;
    if(pady < Ball_Y+Ball_H && pady + padH > Ball_Y){
        return true;
    }
    return false;
}

void Ball::move(int x, int y) {
    Ball::setPosition(Ball_X + x, Ball_Y + y);
}

sf::Vector2f Ball::getSize() {
    return sf::Vector2f(Ball_W, Ball_H);
}