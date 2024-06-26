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

  public:
	uint8_t x;
	uint8_t y;
	Texture2D texture;
};
} // namespace snake

#endif
