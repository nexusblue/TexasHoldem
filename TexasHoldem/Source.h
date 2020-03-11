#include <iostream>  
#include <vector>


#pragma once

void CreateDeck(std::vector <std::string>& Deck );

void ShowDeck( std::vector <std::string>& Deck );

void ShuffleDeck( std::vector <std::string>& Deck );

void ResetCards(std::vector<std::string>& Deck);

int GetPlayerNum();
