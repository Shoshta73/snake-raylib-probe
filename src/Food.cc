// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Food.hh"

#include "defines.hh"

namespace snake {

Food::Food()
{
	this->x = GetRandomValue(0, CELLS_COUNT - 1);
	this->y = GetRandomValue(0, CELLS_COUNT - 1);

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

}
