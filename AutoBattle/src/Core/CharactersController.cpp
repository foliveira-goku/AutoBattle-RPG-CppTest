#include "CharactersController.h"
#include "../Map/Grid.h"
#include "../Character/CharacterClassAttributesProvider.h"
#include <climits>

CharactersController::CharactersController()
{
	allCharacters.reserve(3);
}

void CharactersController::CreateCharacter(const std::string& Name, 
	const CharacterClass::Types& CharacterClass, const int& CharacterId, const int& Team)
{
	allCharacters.emplace_back(new Character{ Name, CharacterClass, 
		CharacterClassAttributesProvider::GetAttributes(CharacterClass), CharacterId, Team });
}

void CharactersController::SetCharactersToRandomPlace(const Grid& Grid)
{
	for (std::shared_ptr<Character> character : allCharacters)
	{
		GridCell* randomCell = Grid.GetRandomUnoccupiedCell();
		character->SetNewPosition(randomCell->GetPosition());
		randomCell->SetOccupied();
	}
}

void CharactersController::ExecuteTurnAction(const int& CurrentCharIndex, const Grid& Grid)
{
	currentCharacter = allCharacters[CurrentCharIndex];

	std::shared_ptr<Character> currentCharacterPtr = currentCharacter.lock();
	Character& opponentCharacter = GetClosestOpponent(*currentCharacterPtr);
	
	if (Grid.IsCellsAdjacent(currentCharacterPtr->GetPosition(), opponentCharacter.GetPosition()))
	{
		AttackOpponent(*currentCharacterPtr, opponentCharacter);
		return;
	}

	MoveTowardsOpponent(*currentCharacterPtr, opponentCharacter.GetPosition(), Grid);
}

const int& CharactersController::GetCharactersCount() { return allCharacters.size(); }

const bool& CharactersController::IsWinner()
{
	std::shared_ptr<Character> currentCharacterPtr = currentCharacter.lock();

	if (allCharacters.size() == 1)
	{
		std::cout << currentCharacterPtr->GetName() << " has won the game!\n";
		return true;
	}

	int currentCharacterTeam = currentCharacterPtr->GetTeam();
	int opponentsAliveCount = 0;

	for (const std::shared_ptr<Character> character : allCharacters)
	{
		if (character->GetTeam() == currentCharacterTeam ||
			character->GetCharacterId() == currentCharacterPtr->GetCharacterId())
			continue;

		opponentsAliveCount++;
	}

	bool hasWon = opponentsAliveCount <= 0;

	if (hasWon)
		std::cout << currentCharacterPtr->GetName() << " has won the game!\n";

	return hasWon;
}

// private functions

void CharactersController::AttackOpponent(Character& CurrentCharacter, Character& OpponentCharacter)
{
	std::cout << CurrentCharacter.GetName() <<" is attacking " << OpponentCharacter.GetName() << ".\n";

	OpponentCharacter.TakeDamage(CurrentCharacter.GetAttackAttribute());

	for (int i = 0; i < allCharacters.size(); i++)
	{
		if (allCharacters[i]->IsDead())
		{
			allCharacters.erase(allCharacters.begin() + i);
			return;
		}
	}
}

void CharactersController::MoveTowardsOpponent(Character& CurrentCharacter, const Vector2& OpponentPosition, const Grid& Grid)
{
	Direction::Direction directionToOpponent = GetDirectionTowardsTarget(CurrentCharacter.GetPosition(), OpponentPosition);

	GridCell& oldCell = Grid.GetCellAt(CurrentCharacter.GetPosition());
	oldCell.FreeCell();

	GridCell& newCell = Grid.GetCellFromDirection(CurrentCharacter.GetPosition(), directionToOpponent);
	CurrentCharacter.SetNewPosition(newCell.GetPosition());
	newCell.SetOccupied();

	std::cout << CurrentCharacter.GetName() << " has moved from " << oldCell.GetPosition().ToString() << " to " << newCell.GetPosition().ToString() << std::endl;

	Grid.DrawBattlefield();
}

Character& CharactersController::GetClosestOpponent(const Character& CurrentCharacter)
{
	int closestOpponentDistance = INT_MAX;
	std::shared_ptr<Character> currentClosestEnemy = allCharacters[0];
	Vector2 currentCharacterPosition = CurrentCharacter.GetPosition();

	for (std::shared_ptr<Character> character : allCharacters)
	{
		if (CurrentCharacter.GetCharacterId() == character->GetCharacterId() ||
			CurrentCharacter.GetTeam() == character->GetTeam())
			continue;

		int distance = currentCharacterPosition.DistanceTo(character->GetPosition());

		if (distance < closestOpponentDistance)
		{
			closestOpponentDistance = distance;
			currentClosestEnemy = character;
		}
	}

	return *currentClosestEnemy;
}

const Direction::Direction& CharactersController::GetDirectionTowardsTarget(const Vector2& CharacterPosition, const Vector2& TargetPosition) const
{
	int xDiff = TargetPosition.X - CharacterPosition.X;
	int yDiff = TargetPosition.Y - CharacterPosition.Y;

	if (xDiff > 0)
		return Direction::Direction::East;
	else if (xDiff < 0)
		return Direction::Direction::West;
	else if (yDiff > 0)
		return Direction::Direction::North;
	else
		return Direction::Direction::South;
}
