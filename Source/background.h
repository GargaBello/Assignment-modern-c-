#pragma once
#include "raylib.h"
#include <vector>
#include "gsl/algorithm"

struct Star
{
private:
	Vector2 position = { gsl::narrow_cast<float>(GetRandomValue(-150, GetScreenWidth() + 150)) , gsl::narrow_cast<float>(GetRandomValue(0, GetScreenHeight())) };
	float size = gsl::narrow_cast<float>(GetRandomValue(0, 4) / 2);
public:

	void Render() const noexcept {
		DrawCircleV(position, size, SKYBLUE);
	}
};

struct Background
{
private:
	std::vector<Star> Stars{};
	int star_amount = 600;

public:

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
	}
};