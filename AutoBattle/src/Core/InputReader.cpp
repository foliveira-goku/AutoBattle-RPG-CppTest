#include "InputReader.h"

const Vector2 InputReader::GetMapSize()
{
	std::cout << "Choose the map size.\n";

	std::cout << "Amount of rows: \n";
	int rows = GetIntInput();

	std::cout << "Amount of columns: \n";
	int columns = GetIntInput();
	
	return Vector2{ rows, columns };
}

const std::string InputReader::GetCharacterName()
{
	std::string name;
	std::cout << "Please tell me your name.\n";
	std::cin >> name;
	return name;
}

const int InputReader::GetCharacterClass()
{
	std::cout << "Choose Between One of this Classes:\n";
	std::cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer\n";
	int number;

	while (true)
	{
		number = GetIntInput();
		if (number >= 1 && number <= 4)
			return number;
		else
			std::cout << "Invalid choice. Please select a valid option.\n";
	}

	return 0;
}

const bool InputReader::WannaQuit()
{
	std::cout << "Do you want to quit? (y/n): ";
	char response;

	while (true)
	{
		std::cin >> response;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (!std::cin.fail())
		{
			if (response == 'Y' || response == 'y')
			{
				return true;
			}
			else if (response == 'N' || response == 'n')
			{
				return false;
			}
		}

		std::cin.clear();
		std::cout << "Invalid input. Please enter 'y' or 'n': ";

	}

	return false;
}

// private

const int InputReader::GetIntInput()
{
	int number;

	while (true)
	{
		std::cin >> number;

		if (!std::cin.fail())
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return number;
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a valid number.\n";
	}

	return 0;
}