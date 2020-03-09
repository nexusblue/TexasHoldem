#include <iostream>
#include "Source.h"
#include <chrono>       
#include <random>
#include <vector>


void ShowDeck(std::vector <std::string>& Deck) {
	int DeckSize = Deck.size();

	for (size_t i = 0; i < DeckSize; i++) {
		std::cout << Deck.at(i) << ",";
		if ((i + 1) % 13 == 0) {
			std::cout << "\n" << std::endl;
		}
	}
}

void ShuffleDeck(std::vector <std::string>& Deck) {
	//shuffle deck to a randomize order
	unsigned seed = rand() % 100;
	std::shuffle(Deck.begin(), Deck.begin() + 52, std::default_random_engine(seed));
	std::cout << " Shuffling Deck......." << std::endl;

}

void CreateDeck(std::vector <std::string>& Deck)
{
	//using the arrays below contruct a 52 playing card deck 
	std::string suit[4] = { "S","C","D","H" };
	std::string value[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };

	for (size_t j = 0; j < 4; j++)
	{
		for (size_t i = 0; i < 13; i++)
		{
			Deck.push_back("[" + value[i] + suit[j] + "]");
		}
	}
}
