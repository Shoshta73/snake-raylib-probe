// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Food.hh"

#include "defines.hh"

#include "raymath.h"

namespace snake {

Vector2
GenerateRandomCellPosition(void)
{
	return Vector2(GetRandomValue(0, CELLS_COUNT - 1), GetRandomValue(0, CELLS_COUNT - 1));
}

Food::Food()
{
	this->GenerateRandomPosition();
	Image image = LoadImage(FOOD_IMAGE);
	ImageResize(&image, CELL_SIZE, CELL_SIZE);
	this->texture = LoadTextureFromImage(image);

	UnloadImage(image);
}

Food::~Food()
{
	UnloadTexture(this->texture);
}

void
Food::Draw(void)
{
	DrawTexture(this->texture, REAL_COORD(this->x), REAL_COORD(this->y), WHITE);
}

void
Food::GenerateRandomPosition(void)
{
	this->x = GetRandomValue(0, CELLS_COUNT - 1);
	this->y = GetRandomValue(0, CELLS_COUNT - 1);
}

void
Food::GenerateRandomPosition(const std::deque<Vector2>& snakeBody)
{
	Vector2 pos = GenerateRandomCellPosition();

	while (this->inSnakeBody(pos, snakeBody)) {
		pos = GenerateRandomCellPosition();
	}

	this->x = pos.x;
	this->y = pos.y;
}

bool
Food::inSnakeBody(Vector2 pos, const std::deque<Vector2>& snakeBody) const
{
	for (auto& bp : snakeBody) {
		if (Vector2Equals(bp, pos)) {
			return true;
		}
	}
	return false;
}

} // namespace snake
