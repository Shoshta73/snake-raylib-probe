// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "defines.hh"

#include "raylib.h"

int
main(void)
{
	InitWindow(CELL_SIZE * CELLS_COUNT, CELL_SIZE * CELLS_COUNT, "Snake");

#if DEBUG
	SetExitKey(KEY_NULL);
#endif

	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(green);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
