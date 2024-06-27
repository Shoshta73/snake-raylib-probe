// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Game.hh"

#include "defines.hh"

#include "raymath.h"
namespace snake {

bool
inSnakeBody(Vector2 pos, const std::deque<Vector2>& snakeBody)
{
	for (auto& bp : snakeBody) {
		if (Vector2Equals(bp, pos)) {
			return true;
		}
	}
	return false;
}

Game::Game() {}

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
	if (this->running) {
		if (shouldUpdate())
			this->snake.Update();

		this->checkFoodCollision();
		this->checkSnakeTailCollision();

		this->handleInput();
	}
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
	if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_KP_8)) && this->snake.direction.y != 1) {
		this->running = true;
		this->snake.direction = { 0, -1 };
	}
	if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_KP_2)) && this->snake.direction.y != -1) {
		this->running = true;
		this->snake.direction = { 0, 1 };
	}
	if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_KP_4)) && this->snake.direction.x != 1) {
		this->running = true;
		this->snake.direction = { -1, 0 };
	}
	if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_KP_6)) && this->snake.direction.x != -1) {
		this->running = true;
		this->snake.direction = { 1, 0 };
	}
}

void
Game::checkFoodCollision()
{
	if (Vector2Equals(this->snake.body[0], this->food)) {
		this->food.GenerateRandomPosition(this->snake.body);
		this->snake.addSegment = true;
	}
}

void
Game::checkSnakeTailCollision()
{
	std::deque<Vector2> hb = this->snake.body; // headless body
	hb.pop_front();
	if (inSnakeBody(snake.body[0], hb))
		this->gameOver();
}

void
Game::gameOver()
{
	this->snake.Reset();
	this->food.GenerateRandomPosition(this->snake.body);
	this->running = false;
}

} // namespace snake
