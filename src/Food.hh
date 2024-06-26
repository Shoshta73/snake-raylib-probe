// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "raylib.h"

#include <cstdint>
#include <deque>

#pragma once

#ifndef FOOD_HH
#define FOOD_HH

namespace snake {
class Food
{
  public:
	Food();
	~Food();

  public:
	void Draw(void);
	void GenerateRandomPosition(void);
	void GenerateRandomPosition(const std::deque<Vector2>& snakeBody);

  public:
	float x;
	float y;
	Texture2D texture;

  public:
	operator Vector2() const { return Vector2(x, y); }

  private:
	bool inSnakeBody(Vector2 pos, const std::deque<Vector2>& snakeBody) const;
};
} // namespace snake

#endif
