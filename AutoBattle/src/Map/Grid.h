#pragma once

#include <iostream>
#include <cmath>
#include <random>
#include "GridCell.h"
#include "..\Utils\Vector2.h"

class Grid
{
private:
	const int width;
	const int height;
	GridCell* grid;

public:
	Grid() = default;
	Grid(const Vector2& MapSize);
	~Grid();
	void DrawBattlefield() const;
	const bool IsCellsAdjacent(const Vector2& FirstPosition, const Vector2& SecondPosition) const;
	GridCell& GetCellFromDirection(const Vector2& From, const GridCell::Direction& Direction) const;
	GridCell* GetRandomUnoccupiedCell() const;
	void PrintGridIsOccupied() const;
	GridCell& GetCellAt(const Vector2& Position) const;

private:
	GridCell& GetRandomCell() const;
	const bool IsValidCell(const Vector2& Position) const;
};
