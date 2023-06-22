#pragma once

static class CharacterClassAttributesProvider
{
public:
	static CharacterAttributes GetAttributes(const CharacterClass::Types& charClass)
	{
		switch (charClass)
		{
		case CharacterClass::Types::Paladin:
			return CharacterAttributes{ 80,15,7,8 };

		case CharacterClass::Types::Warrior:
			return CharacterAttributes{ 100,7,10,10 };

		case CharacterClass::Types::Cleric:
			return CharacterAttributes{ 70,10,5,7 };

		case CharacterClass::Types::Archer:
			return CharacterAttributes{ 50,20,3,15 };

		default:
			break;
		}
	}
};