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

		if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_KP_8)) && game.snake.direction.y != 1)
			game.snake.direction = { 0, -1 };
		if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_KP_2)) && game.snake.direction.y != -1)
			game.snake.direction = { 0, 1 };
		if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_KP_4)) && game.snake.direction.x != 1)
			game.snake.direction = { -1, 0 };
		if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_KP_6)) && game.snake.direction.x != -1)
			game.snake.direction = { 1, 0 };

		ClearBackground(green);

		game.Draw();
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
