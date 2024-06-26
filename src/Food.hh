// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "raylib.h"

#include <cstdint>

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

  public:
	float x;
	float y;
	Texture2D texture;

  public:
	operator Vector2() const { return Vector2(x, y); }
};
} // namespace snake

#endif
