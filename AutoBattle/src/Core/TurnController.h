#pragma once
#include <random>
#include <functional>
#include "../Character/Character.h"

class TurnController
{
private:
	int currentCharacterIndex;
	std::function<const int& ()> getCharactersCount;

public:
	TurnController() = default;
	void InitializeTurnController(std::function<const int&()> GetCharactersCount);
	const int& GetChararacterIndexFromTurn() const;
	void EndTurn();

private:
	const int& RandonmizeCharacterIndex() const;
};

