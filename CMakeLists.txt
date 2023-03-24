cmake_minimum_required(VERSION 3.23)
project(CardGame)

set(CMAKE_CXX_STANDARD 20)

set(Headers player.hpp game.hpp card.hpp)
add_executable(CardGame TestCounter.cpp Demo.cpp main.cpp card.cpp card.hpp game.cpp game.hpp player.cpp player.hpp Test.cpp)
