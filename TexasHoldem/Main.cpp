#include <iostream>
#include "Source.h"
#include <chrono>       
#include <random>
#include <vector>
#include <string>
#include "Player.h"


void FillPlayerInfo(std::vector<Player>& allPlayers, std::vector <std::string>& Deck) {
	//Ask for the # if players
	int numOfPlayers;
	std::cout << "How many players (Between 2-4) are playing: ";
	std::cin >> numOfPlayers;

	for (size_t i = 0; i < numOfPlayers; i++)
	{
		//Create hand and assign player's hand and player number for each player
		std::vector <std::string> Hand = {};
		int DeckSize = Deck.size();
		int PlayNum = i + 1;
		for (size_t j = 0; j < 2; j++)
		{
			Hand.push_back(Deck[DeckSize - (j+1)]);
			Deck.pop_back();
		}
		Player newPlayer(PlayNum, Hand);
		allPlayers.push_back(newPlayer);
	}

};

void printShit(const std::vector<Player>& Players) {

	unsigned int size = Players.size();

	if (Players[0].pHand.size() == 0)
	{
		std::cout << "The hand is empty" << std::endl;
	}
	else {
		for (unsigned i = 0; i < size; i++) {
			for (unsigned j = 0; j < 2; j++)
			{
				std::cout << "" << Players[i].pHand[j] << std::endl;
			}
		}
	}

}

void ClearHands(std::vector<Player>& Players) {
	
	unsigned int size = Players.size();
	for (unsigned i = 0; i < size; i++) {
			Players[i].pHand.clear();
	}
}


int main() {
	

	srand(time(0));
	//Create/Shuffle/Show the starting Deck we play with
	std::vector <std::string> Deck;
	CreateDeck(Deck);
	ShuffleDeck(Deck);
	ShowDeck(Deck);

	//Fill in all players numbers and hand
	std::vector<Player> allPlayers = {};
	FillPlayerInfo(allPlayers, Deck);
	printShit(allPlayers);


	std::cout << "\nMaking a new deck" << std::endl;
	CreateDeck(Deck);
	ShuffleDeck(Deck);
	ShowDeck(Deck);
	ClearHands(allPlayers);
	printShit(allPlayers);


	//FillPlayerInfo(allPlayers, Deck);
	//printShit(allPlayers);

}



/*
	bool inCurRound = true;
	bool stillPlaying = true;
	int Money = 100;
	float cardPower = 0;

	void Fold();
	void Raise();
	void Pass();
	void Call();

void Player::Fold() {

}
void Player::Raise() {

}
void Player::Pass() {

}
void Player::Call() {

}





*/