// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Food.hh"

#include "defines.hh"

namespace snake {

Food::Food()
{
	x = CELLS_COUNT / 2;
	y = CELLS_COUNT / 2;
}

Food::~Food()
{
	// Nothing to do.
}

void
Food::Draw(void)
{
	DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, RED);
}

}
