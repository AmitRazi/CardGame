//
// Created by 97250 on 21/03/2023.
//

#include "card.hpp"
using namespace ariel;
Card::Card(Suit suit, Rank rank) : suit_type(suit),rank_value(rank){};



int Card::get_value() const{
    return get_value();
};

int Card::get_suit() const{
    return get_suit();
};

bool Card::operator>(const Card &) const{
    return false;
};

bool Card::operator<(const Card &) const{
    return false;
};

bool Card::operator==(const Card &) const{
    return false;
};