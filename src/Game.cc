// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Game.hh"
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
	this->snake.Update();
}

} // namespace snake
