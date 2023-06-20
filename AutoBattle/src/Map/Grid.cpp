#include "Grid.h"

Grid::Grid(const Vector2& MapSize):
	width{ MapSize.X }, height { MapSize.Y }, grid{ new GridCell[width * height] }
{
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			grid[x + y * width] = GridCell{ Vector2{x, y} };

	std::cout << "The battle field has been created with " << width << " rows and " << height << " columns\n";
}

Grid::~Grid() { delete[] grid; }

std::string GetRedCrossCell()
{
	std::cout << "\033[" << 31 << "m";

	return "[X]\t";
}

void ResetColor()
{
	std::cout << "\033[" << 0 << "m";
}

void Grid::DrawBattlefield() const
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			auto boxPrint = grid[x + y * width].IsOccupied() ? GetRedCrossCell() : "[ ]\t";
			std::cout << boxPrint;
			ResetColor();
		}

		std::cout << "\n\n";
	}

	std::cout << "\n";
}

const bool Grid::IsCellsAdjacent(const Vector2& FirstPosition, const Vector2& SecondPosition) const
{
	int distanceX = std::abs(FirstPosition.X - SecondPosition.X);
	int distanceY = std::abs(FirstPosition.Y - SecondPosition.Y);
	return distanceX == 1 && distanceY == 0 || 
			distanceX == 0 && distanceY == 1 ||
			distanceX == 1 && distanceY == 1;
}

GridCell& Grid::GetCellFromDirection(const Vector2& From, const GridCell::Direction& Direction) const
{
	switch (Direction)
	{
		case GridCell::Direction::North:
			return grid[From.X + (From.Y + 1) * width];
		case GridCell::Direction::South:
			return grid[From.X + (From.Y - 1) * width];
		case GridCell::Direction::West:
			return grid[(From.X - 1) + From.Y * width];
		case GridCell::Direction::East:
			return grid[(From.X + 1) + From.Y * width];
		default:
			break;
	}

	return grid[0];
}

GridCell* Grid::GetRandomUnoccupiedCell() const
{
	GridCell* cell;

	do
	{
		cell = &GetRandomCell();
	} while (cell->IsOccupied());

	return cell;
}

void Grid::PrintGridIsOccupied() const
{
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			std::cout << "Grid -> x:" << x << " y:" << y << " is occupied: " << grid[x + y * width].IsOccupied() << std::endl;
}

// private functions

GridCell& Grid::GetRandomCell() const
{
	int randomX = std::rand() % width;
	int randomY = std::rand() % height;
	std::cout << "Random cell=> X:" << randomX << " Y:" << randomY << std::endl;

	return GetCellAt(Vector2(randomX, randomY));
}

GridCell& Grid::GetCellAt(const Vector2& Position) const
{
	return IsValidCell(Position) ? grid[Position.X + Position.Y * width] : grid[0];
}

const bool Grid::IsValidCell(const Vector2& Position) const
{
	return Position.X < width || Position.X >= 0 ||
		   Position.Y < height || Position.Y >= 0;
}