#pragma once

static class CharacterClassAttributesProvider
{
public:
	static CharacterAttributes GetAttributes(const Character::CharacterClass& charClass)
	{
		switch (charClass)
		{
		case Character::CharacterClass::Paladin:
			return CharacterAttributes{ 80,15,7,8 };

		case Character::CharacterClass::Warrior:
			return CharacterAttributes{ 100,7,10,10 };

		case Character::CharacterClass::Cleric:
			return CharacterAttributes{ 70,10,5,7 };

		case Character::CharacterClass::Archer:
			return CharacterAttributes{ 50,20,3,15 };

		default:
			break;
		}
	}
};