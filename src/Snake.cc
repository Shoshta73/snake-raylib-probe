// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Snake.hh"

#include "defines.hh"

#include <raymath.h>

#include <cstdint>

namespace snake {

Snake::Snake()
{
	int initalLength = GetRandomValue(1, MAX_STARTING_LENGTH);
	int initial_x = GetRandomValue(0 + initalLength, CELLS_COUNT - 1 - initalLength);
	int initial_y = GetRandomValue(0 + initalLength, CELLS_COUNT - 1 - initalLength);
	for (uint8_t i = 0; i < initalLength; i++) {
		body.push_back(Vector2(initial_x - i, initial_y));
	}
}

Snake::~Snake() {}

void
Snake::Draw()
{
	for (auto& bp : body) {
		Rectangle segment = Rectangle(REAL_COORD(bp.x), REAL_COORD(bp.y), CELL_SIZE, CELL_SIZE);
		DrawRectangleRounded(segment, 0.5, 6, darkGreen);
	}
}

void
Snake::Update()
{
	body.pop_back();
	body.push_front(Vector2Add(body[0], this->direction));
}

}
