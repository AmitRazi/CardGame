//
// Created by 97250 on 21/03/2023.
//

#ifndef CARDGAME_CARD_HPP
#define CARDGAME_CARD_HPP

#include <iostream>
#include <vector>
#include <string>
namespace ariel {
    class Card {

    public:
        const enum Suit {
            HEARTS, DIAMONDS, CLUBS, SPADES
        };
        const enum Rank {
            ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
        };

        Card(Suit, Rank);

        int get_value() const;

        int get_suit() const;

        bool operator>(const Card &) const;

        bool operator<(const Card &) const;

        bool operator==(const Card &) const;

    private:
        Suit suit_type;
        Rank rank_value;
    };
}

#endif //CARDGAME_CARD_HPP
