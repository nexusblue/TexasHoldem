#include "Player.h"

Player::Player() {
	playerNum = 0;
	pHand = {"",""};
};

Player::Player(int num, std::vector <std::string>& hand) {
	playerNum = num;
	pHand = hand;
};

Player::~Player() {

}

int const Player::getPlayNum() {
	return playerNum;
}

std::vector <std::string> Player::getHand() {
	return pHand;
}

void Player::setPlayNum(int num) {
	playerNum = num;
}

void Player::setHand(std::vector <std::string> hand) {
	pHand = hand;

}

void Player::Fold() {
	std::cout << "Inside Fold" << std::endl;
}
void Player::Raise() {

}
void Player::Pass() {

}
void Player::Call() {

}