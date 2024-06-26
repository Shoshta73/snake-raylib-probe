// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Food.hh"
#include "Snake.hh"
#include "defines.hh"

#include "raylib.h"

double lastUpdateTime = 0.0;

bool
eventTriggered(double interval)
{
	double curr = GetTime();
	if (curr - lastUpdateTime >= interval) {
		lastUpdateTime = curr;
		return true;
	}
	return false;
}

using namespace snake;

int
main(void)
{
	InitWindow(CELL_SIZE * CELLS_COUNT, CELL_SIZE * CELLS_COUNT, "Snake");
#if !DEBUG
	SetExitKey(KEY_NULL);
#endif
	SetTargetFPS(60);

	Food food = Food();
	Snake snake = Snake();
	while (!WindowShouldClose()) {
		BeginDrawing();

		if (eventTriggered(INTERVAL)) {
			snake.Update();
		}

		ClearBackground(green);
		food.Draw();
		snake.Draw();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
