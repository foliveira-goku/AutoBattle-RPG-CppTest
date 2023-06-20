#pragma once

#include <iostream>
#include <string>

#include "Health.h"
#include "CharacterAttributes.h"
#include "../Utils/Vector2.h"

class Character
{
public:
	enum CharacterClass
	{
		None = 0, Paladin = 1, Warrior = 2, Cleric = 3, Archer = 4
	};
	enum Team
	{
		Player = 0, Enemy = 1
	};

private:
	const std::string charName = "";
	const int charId = 0;
	const Team team = Player;
	const CharacterClass charClass = None;
	const CharacterAttributes charAttributes;
	
	Vector2 currentPosition;
	Health charHealth;

public:
	Character() = default;
	Character(const std::string& Name, const CharacterClass& CharClass, 
		const int& CharacterId, const int& Team);
	const std::string& GetName() const;
	const Vector2& GetPosition() const;
	const int& GetCharacterId() const;
	const Character::Team& GetTeam() const;
	const int& GetAttackAttribute() const;
	const bool& IsDead() const;
	void SetNewPosition(const Vector2& NewPosition);
	void TakeDamage(const int& Amount);
	void Heal(const int& Amount);
};
