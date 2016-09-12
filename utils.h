#pragma once

#include "sfwdraw.h"

void drawString(unsigned handle, const char *text, int score1, int score2, float x, float y, float width = 1, float height = 1, float angle = 0, char offset = '\0', unsigned int tint = WHITE, const float transform[16] = sfw::identity);