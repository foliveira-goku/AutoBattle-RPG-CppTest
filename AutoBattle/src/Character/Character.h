#pragma once

#include <iostream>
#include <string>

#include "Health.h"
#include "CharacterAttributes.h"
#include "../Utils/Vector2.h"

namespace CharacterClass
{
	enum Types
	{
		None = 0, Paladin = 1, Warrior = 2, Cleric = 3, Archer = 4
	};
}

namespace Team
{
	enum Team
	{
		Player = 0, Enemy = 1
	};
}

class Character
{
private:
	const std::string charName = "";
	const int charId = 0;
	const Team::Team team = Team::Player;
	const CharacterClass::Types charClass = CharacterClass::None;
	const CharacterAttributes charAttributes{};
	
	Vector2 currentPosition{};
	Health charHealth{0};

public:
	Character() = default;
	Character(const std::string& Name, const CharacterClass::Types& CharClass, 
		const CharacterAttributes& CharAttributes, const int& CharacterId, const int& Team);
	const std::string& GetName() const;
	const Vector2& GetPosition() const;
	const int& GetCharacterId() const;
	const Team::Team& GetTeam() const;
	const int& GetAttackAttribute() const;
	const bool& IsDead() const;
	void SetNewPosition(const Vector2& NewPosition);
	void TakeDamage(const int& Amount);
	void Heal(const int& Amount);
};
