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

	void Fold();
	void Raise();
	void Pass();
	void Call();

	std::vector <std::string> pHand ;
	std::vector <std::string> pBoardHand;

	int playerNum;
	bool inCurRound = true;
	bool stillPlaying = true;
	int Money = 100;
	float cardPower = 0;



};


#endif // !PLAYER_H
