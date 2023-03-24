//
// Created by 97250 on 21/03/2023.
//

#ifndef CARDGAME_GAME_HPP
#define CARDGAME_GAME_HPP
#include <iostream>
#include <string>
#include <vector>
#include "player.hpp"
#include "card.hpp"
namespace ariel {
    class Game {
    private:
        Player player1;
        Player player2;
        std::vector<Card> deck;

    public:
        Game(Player, Player);

        void playTurn();

        void printLastTurn();

        void playAll();

        void printWiner();

        void printLog();

        void printStats();
    };
}

#endif //CARDGAME_GAME_HPP
