#pragma once
#include "raylib.h"
#include <vector>
#include "gsl/algorithm"

struct Star
{
	Vector2 position = { gsl::narrow_cast<float>(GetRandomValue(-150, GetScreenWidth() + 150)) , gsl::narrow_cast<float>(GetRandomValue(0, GetScreenHeight())) };
	float size = gsl::narrow_cast<float>(GetRandomValue(0, 4) / 2);

	void Render() const noexcept {
		DrawCircleV(position, size, SKYBLUE);
	}
};

/* TODO: Make constructor
*  Initialize in constructorm, not in separate function or
	make initialize part of construction depending on how it looks
*/

struct Background
{
	std::vector<Star> Stars{};

	int star_amount = 600;

	Background() noexcept {
		while (Stars.size() < star_amount) {
			Stars.emplace_back();
		}
	}

	void Render() const noexcept {
		for (auto& star : Stars)
		{
			star.Render();
		}
	}//todo: should be const and noexcept
};