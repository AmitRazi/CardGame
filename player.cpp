//
// Created by 97250 on 21/03/2023.
//

#include "player.hpp"
using namespace ariel;
Player::Player(std::string name) : name(name){};

std::string Player::get_name(){
    return name;
};

int Player::stacksize(){
    return stack.size();
};

int Player::cardesTaken(){
    return won_cards;
};

void Player::won(int x){
    won_cards+=x;
};

void Player::addcard(const Card &card) const{

};

void Player::removecard(){

};

Card Player::topCard() const{
    return stack[0];
};