// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <deque>
#include <raylib.h>

#pragma once

#ifndef SNAKE_HH
#define SNAKE_HH

namespace snake {
class Snake
{
  public:
	Snake();
	~Snake();

  public:
	std::deque<Vector2> body = { { 5, 6 }, { 4, 6 }, { 3, 6 } };

  public:
	void Draw();
};
}

#endif
