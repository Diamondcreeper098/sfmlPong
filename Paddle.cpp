//
// Created by seyed ali on 1/12/20.
// Paddle Class
//

#include "Paddle.h"
#include <SFML/Graphics.hpp>

Paddle::Paddle(int x, int y, int w, int h) {
    Pad_X = x;Pad_Y = y;Pad_W = w; Pad_H = h;
    Pad = sf::RectangleShape(sf::Vector2f(w,h));
    Pad.setFillColor(sf::Color::White);
    Pad.setPosition(x,y);
}

void Paddle::setPosition(int x, int y) {
    Pad_X = x;Pad_Y = y;
    Pad.setPosition(x,y);
}

sf::Vector2f Paddle::getPosition() {
    return Pad.getPosition();
}

void Paddle::changeScore(int offset) {
    Score += offset;
}

int Paddle::getScore() {
    return Score;
}

sf::RectangleShape Paddle::getShape() {
    return Pad;
}

sf::Vector2f Paddle::getSize() {
    return Pad.getSize();
}

void Paddle::move(int x, int y) {
    Paddle::setPosition(Pad_X + x, Pad_Y + y);
}