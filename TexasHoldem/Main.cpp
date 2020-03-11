#include <iostream>
#include "Source.h"
#include <chrono>       
#include <random>
#include <vector>
#include <string>
#include "Player.h"
#include "Main.h"


void ShowHand(const std::vector<Player>& Players) {

	unsigned int size = Players.size();
	if (Players[0].pHand.size() == 0)
	{
		std::cout << "\nThe hand is empty" << std::endl;
	}
	else {
		for (unsigned i = 0; i < size; i++) {
			std::cout << "Player " << Players[i].playerNum << "'s hand:";
			for (unsigned j = 0; j < 2; j++)
			{
				std::cout << "" << Players[i].pHand[j];
			}
			std::cout << "\n";
		}
	}
	std::cout << "\n";

}

void FirstHandDealt(int& numOfPlayers,std::vector<Player>& allPlayers, std::vector <std::string>& Deck) {
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
	ShowHand(allPlayers);
};

void HandDealt(int& numOfPlayers, std::vector<Player>& allPlayers, std::vector <std::string>& Deck) {
	for (size_t i = 0; i < numOfPlayers; i++)
	{
		std::vector <std::string> Hand = {};
		int DeckSize = Deck.size();
		for (size_t j = 0; j < 2; j++)
		{
			Hand.push_back(Deck[DeckSize - (j + 1)]);
			Deck.pop_back();
		}
		allPlayers[i].setHand(Hand);

	}
	ShowHand(allPlayers);

};

void ClearHands(std::vector<Player>& Players) {
	
	unsigned int size = Players.size();
	for (unsigned i = 0; i < size; i++) {
			Players[i].pHand.clear();
	}
}

int RemovePlayers(std::vector<Player>& Players) {
	Players.erase(Players.begin());
	return Players.size();
}

void RevealCards(std::vector <std::string>& Deck, std::vector <std::string>& ComCards) {
	//Remove the top card from Deck
	std::cout << "Burning the top card"<<std::endl;
	Deck.pop_back();
	std::cin.get();
	
	//Add cards to the community
	if (ComCards.size() == 0){
		for (size_t i = 0; i < 3; i++){
			ComCards.push_back(Deck[Deck.size() - (i + 1)]);
			Deck.pop_back();
		}
		std::cout << "The Flop:" << std::endl;
	}
	else if (ComCards.size() == 3){
		ComCards.push_back(Deck[Deck.size() - 1]);
		Deck.pop_back();
		std::cout << "The Turn:" << std::endl;
	}
	else if (ComCards.size() == 4){
		ComCards.push_back(Deck[Deck.size() - 1]);
		Deck.pop_back();
		std::cout << "The River:" << std::endl;
	}

	//Show community cards
	for (size_t i = 0; i < ComCards.size(); i++)
	{
		std::cout << ComCards[i]<< " ";
	}
	std::cout << "\n";


}

int main() {

	srand(time(0));
	//Create/Shuffle/Show the starting Deck we play with
	std::vector <std::string> Deck = {};
	std::vector <std::string> ComCards = {};

	ResetCards(Deck);

	//Get Player # and assign players numbers/hands
	int playerNum = GetPlayerNum();
	std::vector<Player> allPlayers = {};

	FirstHandDealt(playerNum,allPlayers, Deck);

	ComCards = {};
	RevealCards(Deck, ComCards);
	RevealCards(Deck, ComCards);
	RevealCards(Deck, ComCards);

	//Code to start a new round by clearing player hands and deal new cards
	//ResetCards(Deck);
	//ClearHands(allPlayers);
	//playerNum = RemovePlayers(allPlayers);
	//HandDealt(playerNum,allPlayers, Deck);

	int curCardPower;
	std::vector <std::string> allCards = {};

	for (size_t i = 0; i < 1; i++)
	{
		allCards = {};
		for (size_t j = 0; j < 5; j++) {
			allCards.push_back(ComCards[j]);
		}
		allCards.push_back(allPlayers[i].pHand[0]);
		allCards.push_back(allPlayers[i].pHand[1]);

		//for when I can take into account all the 
		if ("this is a royal flush"){curCardPower = 17;}
		else if ("straight flush"){curCardPower = 16;}
		else if ("4 of a kind"){curCardPower = 15;}
		else if ("full house"){curCardPower = 14;}
		else if ("flush"){curCardPower = 13;}
		else if ("straight"){curCardPower = 12;}
		else if ("3 of a kind"){curCardPower = 11;}
		else if ("2 pairs"){curCardPower = 12;}
		else if ("1 pair"){curCardPower = 10;}
		else if ("High Card") {//Run find highest card}
		}
		for (size_t i = 0; i < allCards.size(); i++)
		{
			std::cout << allCards[i] << " ";
		}

		//finding pairs
		for (size_t i = 0; i < allCards.size(); i++)
		{
			std::cout << allCards[i][1];
		}

	}





}
