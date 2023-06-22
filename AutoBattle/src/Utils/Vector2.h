#pragma once
#include <cmath>
#include <iostream>
#include <string>

struct Vector2
{
	int X{};
	int Y{};

	Vector2() = default;

	Vector2(int x, int y): X{ x }, Y{y}	{}

	const int& DistanceTo(const Vector2& other)
	{
		return std::sqrt(std::pow(other.X - X, 2) + std::pow(other.Y - Y, 2));
	}

	const std::string ToString() const
	{
		return std::to_string(X) + " " + std::to_string(Y);
	}
};