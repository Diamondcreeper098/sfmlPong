//
// Created by seyed ali on 1/12/20.
//

#ifndef SFMLGAME_PADDLE_H
#define SFMLGAME_PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
private:
    sf::RectangleShape Pad;
    int Pad_Y;
    int Pad_X;
    int Pad_W;
    int Pad_H;
    int Score;
public:
    Paddle(int x, int y, int w, int h);
    void setPosition(int x, int y);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    void move(int x, int y);
    void changeScore(int offset);
    int getScore();
    sf::RectangleShape getShape();
};


#endif //SFMLGAME_PADDLE_H
