#include "GridCell.h"

GridCell::GridCell(const Vector2& CellPosition) : position(CellPosition), isOccupied(false) {}

const Vector2& GridCell::GetPosition() const { return position; }

bool GridCell::IsOccupied() { return isOccupied; }

void GridCell::SetOccupied() { isOccupied = true; }

void GridCell::FreeCell() { isOccupied = false; }
