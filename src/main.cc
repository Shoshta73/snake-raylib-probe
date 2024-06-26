// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Game.hh"
#include "defines.hh"

#include "raylib.h"

using namespace snake;

int
main(void)
{
	InitWindow(CELL_SIZE * CELLS_COUNT, CELL_SIZE * CELLS_COUNT, "Snake");
#if !DEBUG
	SetExitKey(KEY_NULL);
#endif
	SetTargetFPS(60);

	Game game = Game();
	while (!WindowShouldClose()) {
		BeginDrawing();

		game.Update();

		ClearBackground(green);

		game.Draw();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
