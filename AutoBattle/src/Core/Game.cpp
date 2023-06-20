#include "Game.h"

Game::Game() : grid{ inputReader.GetMapSize() } {}

void Game::Start()
{
	std::cout << "Welcome to Auto Battle! \n";

	int charactersCount = 0;
	int amountOfEnemies = 2;

	CreatePlayerCharacter(charactersCount);
	CreateEnemyCharacter(amountOfEnemies, charactersCount);

	charsController.SetCharactersToRandomPlace(grid);

	turnController.InitializeTurnController([this]()->const int& { return charsController.GetCharactersCount(); });

	grid.DrawBattlefield();

	UpdateTurn();
}

void Game::CreatePlayerCharacter(int& TotalCharAmount)
{
	charsController.CreateCharacter(inputReader.GetCharacterName(),
								   (Character::CharacterClass)inputReader.GetCharacterClass(), 0, 0);

	TotalCharAmount++;
}

void Game::CreateEnemyCharacter(const int& AmountOfEnemies, int& TotalAmountOfCharacters)
{
	std::srand(std::time(0));

	for (int i = 0; i < AmountOfEnemies; i++)
	{
		int randomClass = std::rand() % 4 + 1;
		charsController.CreateCharacter("Enemy "+ std::to_string(TotalAmountOfCharacters), (Character::CharacterClass)randomClass, TotalAmountOfCharacters, 1);
		TotalAmountOfCharacters++;
	}
}

void Game::UpdateTurn()
{
	std::cout << "Press any key to start...\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	std::cin.get();

	std::cout << "The battle is starting in... \n";
	std::cout << "3... \n";
	std::cout << "2... \n";
	std::cout << "1... \n";

	while (true)
	{
		int currentCharacterIndex = turnController.GetChararacterIndexFromTurn();

		charsController.ExecuteTurnAction(currentCharacterIndex, grid);

		if (charsController.IsWinner())
			return;

		turnController.EndTurn();

		std::cout << "Press any key to continue...\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
		std::cin.get();
	}
}
