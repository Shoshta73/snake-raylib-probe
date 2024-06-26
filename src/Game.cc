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

} // namespace snake
