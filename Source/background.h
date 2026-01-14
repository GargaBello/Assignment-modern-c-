#pragma once
#include "raylib.h"
#include <vector>
#include "gsl/algorithm"

class Star
{
private:
	static constexpr int lower_x_pos_bounds = -150, upper_x_pos_bounds_offset = 150, lower_y_pos_bounds = 0;
	
	Vector2 position = { 
		gsl::narrow_cast<float>(GetRandomValue(lower_x_pos_bounds, GetScreenWidth() + upper_x_pos_bounds_offset)), 
		gsl::narrow_cast<float>(GetRandomValue(lower_y_pos_bounds, GetScreenHeight())) };
	float size = gsl::narrow_cast<float>(GetRandomValue(0, 4) / 2);
public:

	void Render() const noexcept {
		DrawCircleV(position, size, SKYBLUE);
	}
};

class Background
{
private:
	std::vector<Star> Stars{};
	static constexpr int star_amount = 600;

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