// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <raylib.h>

#pragma once

#ifndef DEFINES_HH
#define DEFINES_HH

#define CELL_SIZE 20
#define CELLS_COUNT 40
#define REAL_COORD(x) ((x) * CELL_SIZE)
#define MAX_STARTING_LENGTH 3

#define INTERVAL 0.5

static Color green = { 173, 204, 96, 255 };
static Color darkGreen = { 43, 51, 24, 255 };

#if DEBUG
#define FOOD_IMAGE "assets/foods/Food_0.png"
#endif

#endif
