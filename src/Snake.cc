// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Snake.hh"

#include "defines.hh"

namespace snake {

Snake::Snake() {}

Snake::~Snake() {}

void
Snake::Draw()
{
	for (auto& bp : body) {
		DrawRectangle(REAL_COORD(bp.x), REAL_COORD(bp.y), CELL_SIZE, CELL_SIZE, darkGreen);
	}
}

}
