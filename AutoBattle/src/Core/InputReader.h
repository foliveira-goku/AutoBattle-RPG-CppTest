#pragma once
#include <iostream>
#include <string>

#include "../Utils/Vector2.h"

class InputReader
{
public:
	const Vector2& GetMapSize();
	const std::string GetCharacterName();
	const int& GetCharacterClass();
	const bool& WannaQuit();
	
private:
	const int& GetIntInput();
};