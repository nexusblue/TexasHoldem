#pragma once

//Header
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <Vector>

class Player {
	
public:
	//Default Constructor
	Player();

	//Overload Constructor
	Player(int num, std::vector <std::string>& hand);

	//Destructor
	~Player();

	//Accessor Functions
	int const getPlayNum();
	std::vector <std::string> getHand();

	//Mutator Functions
	void setPlayNum(int);
	void setHand(std::vector <std::string>);


	std::vector <std::string> pHand ;
	int playerNum;
	//void DealHand();

};

//void Player::DealHand() {
	//this->pDeck = pDeck;
	//this->hand[0] = pDeck[playerNum - 1];
	//this->hand[1] = pDeck[playerNum];
//}


#endif // !PLAYER_H
