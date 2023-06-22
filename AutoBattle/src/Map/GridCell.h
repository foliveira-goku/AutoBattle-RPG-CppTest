#pragma once
#include "..\Utils\Vector2.h"

namespace Direction
{
	enum class Direction
	{
		North, South, West, East
	};
}

class GridCell
{
private:
	Vector2 position{};
	bool isOccupied{};

public:
	GridCell() = default;
	GridCell(const Vector2& CellPosition);
	const Vector2& GetPosition() const;
	bool IsOccupied();
	void SetOccupied();
	void FreeCell();
};