// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Game.hh"
#include "defines.hh"
namespace snake {

Game::Game()
{
	this->food = Food();
	this->snake = Snake();
}

Game::~Game() {}

void
Game::Draw()
{
	this->food.Draw();
	this->snake.Draw();
}

void
Game::Update()
{
	if (shouldUpdate())
		this->snake.Update();

	this->handleInput();
}

bool
Game::shouldUpdate()
{
	double curr = GetTime();
	if (curr - this->lastUpdateTime >= INTERVAL) {
		this->lastUpdateTime = curr;
		return true;
	}
	return false;
}

void
Game::handleInput()
{
	if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_KP_8)) && this->snake.direction.y != 1)
		this->snake.direction = { 0, -1 };
	if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_KP_2)) && this->snake.direction.y != -1)
		this->snake.direction = { 0, 1 };
	if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_KP_4)) && this->snake.direction.x != 1)
		this->snake.direction = { -1, 0 };
	if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_KP_6)) && this->snake.direction.x != -1)
		this->snake.direction = { 1, 0 };
}

} // namespace snake
