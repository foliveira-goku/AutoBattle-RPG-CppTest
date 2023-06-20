#include "Health.h"

Health::Health(const int& MaxHealth) : 
	maxHealth{MaxHealth}, currentHealth{MaxHealth} { }

void Health::TakeDamage(const int& Amount) 
{ 
	currentHealth -= Amount; 
}

void Health::Heal(const int& Amount) 
{
	currentHealth += Amount; 

	if (currentHealth > maxHealth)
		currentHealth = maxHealth;
}

const bool Health::IsDead() const { return currentHealth <= 0; }
const bool Health::IsFull() const { return currentHealth >= maxHealth; }