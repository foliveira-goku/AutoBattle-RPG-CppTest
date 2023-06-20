#pragma once
#include "CharactersController.h"
#include "InputReader.h"
#include "TurnController.h"
#include "../Map/Grid.h"

class Game
{
private:
	CharactersController charsController;
	InputReader inputReader;
	TurnController turnController;
	Grid grid;

public:
	Game();
	void Start();

private:
	void CreatePlayerCharacter(int& TotalCharAmount);
	void CreateEnemyCharacter(const int& AmountOfEnemies, int& TotalAmountOfCharacters);
	void UpdateTurn();
	void IsWinner();
};