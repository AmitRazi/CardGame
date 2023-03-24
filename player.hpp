//
// Created by 97250 on 21/03/2023.
//

#ifndef CARDGAME_PLAYER_HPP
#define CARDGAME_PLAYER_HPP
#include <iostream>
#include <vector>
#include <string>
#include "card.hpp"

namespace ariel {
    class Player {
    private:
        std::string name;
        std::vector<Card> stack;
        int won_cards;

    public:
        Player(std::string = "No Name");

        std::string get_name();

        int stacksize();

        int cardesTaken();

        void won(int);

        void addcard(const Card &card) const;

        void removecard();

        Card topCard() const;
    };
}

#endif //CARDGAME_PLAYER_HPP
