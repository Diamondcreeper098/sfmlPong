cmake_minimum_required(VERSION 3.10)
project(sfmlgame)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
add_executable(sfmlgame main.cpp Asset.cpp Asset.h Paddle.cpp Paddle.h Ball.cpp Ball.h)
target_link_libraries(sfmlgame sfml-system sfml-window sfml-graphics sfml-network sfml-audio)