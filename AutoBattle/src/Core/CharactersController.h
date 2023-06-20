#pragma once

#include <vector>
#include <memory>
#include "../Character/Character.h"
#include "../Map/Grid.h"

class CharactersController
{
private:
	std::vector<std::shared_ptr<Character>> allCharacters;
	std::weak_ptr<Character> currentCharacter;

public:
	CharactersController();
	void CreateCharacter(const std::string& Name, const Character::CharacterClass& CharacterClass, 
		const int& CharacterId, const int& Team);
	void SetCharactersToRandomPlace(const Grid& Grid);
	void ExecuteTurnAction(const int& CurrentCharIndex, const Grid& Grid);
	const int& GetCharactersCount();
	const bool& IsWinner();

private:
	void AttackOpponent(Character& CurrentCharacter, Character& OpponentCharacter);
	void MoveTowardsOpponent(Character& CurrentCharacter, const Vector2& OpponentPosition, const Grid& Grid);
	Character& GetClosestOpponent(const Character& CurrentCharacter);
	const GridCell::Direction& GetDirectionTowardsTarget(const Vector2& CharacterPosition, const Vector2& TargetPosition) const;
};
