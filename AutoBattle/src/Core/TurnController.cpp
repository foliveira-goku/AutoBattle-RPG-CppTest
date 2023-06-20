#include "TurnController.h"

const int& TurnController::GetChararacterIndexFromTurn() const { return currentCharacterIndex; }

void TurnController::InitializeTurnController(std::function<const int& ()>GetCharactersCount)
{
	getCharactersCount = GetCharactersCount;
	currentCharacterIndex = RandonmizeCharacterIndex();
	std::cout << "Random id: " << currentCharacterIndex << "\n";
}

void TurnController::EndTurn() { currentCharacterIndex = (currentCharacterIndex + 1) % getCharactersCount(); }

// private functions

const int& TurnController::RandonmizeCharacterIndex() const { return std::rand() % getCharactersCount(); }