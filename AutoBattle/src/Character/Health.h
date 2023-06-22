#pragma once
#include <iostream>
#include <string>

class Health
{
private:
	const int maxHealth {};
	int currentHealth {};

public:
	Health(const int& MaxHealth);
	void TakeDamage(const int& Amount);
	void Heal(const int& Amount);
	const bool IsDead() const;
	const bool IsFull() const;

	std::string ToString() { return std::to_string(currentHealth) + "/" + std::to_string(maxHealth); }
};