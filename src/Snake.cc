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
	int initialDir = GetRandomValue(0, 3);

	int initalLength = GetRandomValue(1, MAX_STARTING_LENGTH);
	int initial_x = GetRandomValue(0 + initalLength, CELLS_COUNT - 1 - initalLength);
	int initial_y = GetRandomValue(0 + initalLength, CELLS_COUNT - 1 - initalLength);

	switch (initialDir) {
		case 0: // up
			direction = { 0, -1 };
			for (uint8_t i = 0; i < initalLength; i++)
				body.push_back(Vector2(initial_x, initial_y + i));
			break;
		case 1: // right
			direction = { 1, 0 };
			for (uint8_t i = 0; i < initalLength; i++)
				body.push_back(Vector2(initial_x - i, initial_y));
			break;
		case 2: // down
			direction = { 0, 1 };
			for (uint8_t i = 0; i < initalLength; i++)
				body.push_back(Vector2(initial_x, initial_y - i));
			break;
		case 3: // left
			direction = { -1, 0 };
			for (uint8_t i = 0; i < initalLength; i++)
				body.push_back(Vector2(initial_x + i, initial_y));
			break;
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
	this->body.push_front(Vector2Add(this->body[0], this->direction));
	if (this->addSegment) {
		this->addSegment = false;
	} else {
		this->body.pop_back();
	}
}

}
