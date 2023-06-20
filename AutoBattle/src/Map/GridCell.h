#pragma once
#include "..\Utils\Vector2.h"

class GridCell
{
public:
	enum class Direction
	{
		North, South, West, East
	};

private:
	Vector2 position;
	bool isOccupied;

public:
	GridCell() = default;
	GridCell(const Vector2& CellPosition);
	const Vector2& GetPosition() const;
	bool IsOccupied();
	void SetOccupied();
	void FreeCell();
};