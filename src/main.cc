// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "raylib.h"

#define CELL_SIZE 20
#define CELLS_COUNT 40

Color green = { 173, 204, 96, 255 };

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
