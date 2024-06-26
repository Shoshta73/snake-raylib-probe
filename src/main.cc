// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int
main(void)
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake");

#if DEBUG
	SetExitKey(KEY_NULL);
#endif

	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Le snake", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}
