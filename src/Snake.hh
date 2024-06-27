// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "defines.hh"
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
	std::deque<Vector2> body;
	Vector2 direction;
	bool addSegment = false;

  public:
	void Draw();
	void Update();
	void Reset();
};

}

#endif
