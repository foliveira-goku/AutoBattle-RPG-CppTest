#include "Character.h"

Character::Character(const std::string& Name, const CharacterClass::Types& CharacterClass, 
	const CharacterAttributes& CharAttributes, const int& CharacterId,	const int& Team) :
	charName{ Name }, charClass{ CharacterClass }, charId{ CharacterId }, team{ static_cast<Team::Team>(Team) }, 
	currentPosition{}, charAttributes { CharAttributes }, charHealth { charAttributes.Vitality }
{
	std::cout << "The character " << Name << " was created.\n";

	std::cout << "Attributes=> attack: " << charAttributes.Attack << " defense: " << charAttributes.Defence;
	std::cout << " strength: " << charAttributes.Strength << " vitality: " << charAttributes.Vitality << "\n";
}

const std::string& Character::GetName() const { return charName; }
const Vector2& Character::GetPosition() const { return currentPosition; }
const int& Character::GetCharacterId() const { return charId; }
const Team::Team& Character::GetTeam() const { return team; }

const int& Character::GetAttackAttribute() const 
{
	int minDamage = charAttributes.Attack;
	int maxDamage = minDamage + charAttributes.Strength;
	return minDamage + (std::rand() % (maxDamage - minDamage + 1)); 
}

const bool& Character::IsDead() const { return charHealth.IsDead(); }

void Character::SetNewPosition(const Vector2& NewPosition) { currentPosition = NewPosition; }

void Character::TakeDamage(const int& Amount)
{
	if (charHealth.IsDead())
		return;

	int damageTaken = Amount - charAttributes.Defence;

	if (damageTaken < 0)
		damageTaken = 0;

	charHealth.TakeDamage(damageTaken);
	std::cout << charName << " has taken " << damageTaken << " of damage. HP: " << charHealth.ToString() << "\n";

	if (charHealth.IsDead())
		std::cout << charName << " has died!\n";
}

void Character::Heal(const int& Amount)
{
	if (charHealth.IsFull())
		return;

	charHealth.Heal(Amount);

	std::cout << charName << "has healed " << Amount << " hitpoints. HP: " << charHealth.ToString() << "\n";
}