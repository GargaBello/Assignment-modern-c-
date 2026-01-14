#pragma once
#include "raylib.h"
#include <vector>

struct Wall
{
	Vector2 position{};
	bool active = true;
	int health = 50;
	float width = 100.0f;
	static constexpr int textOffsetX = 70;
	static constexpr int textOffsetY = 100;

	Rectangle rect = { position.x, position.y, width * 2, width };

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
		DrawText(std::to_string(health).data(), gsl::narrow_cast<float>(position.x + textOffsetX), gsl::narrow_cast<float>(position.y + textOffsetY), 50, WHITE);
		DrawRectangleLinesEx(rect, 5, DARKPURPLE);
	}

	void Update() noexcept {
		if (health < 1)
		{
			active = false;
		}

		rect.x = position.x;
		rect.y = position.y + textOffsetY;
	}
};


struct Walls
{
	int wallCount = 5; //TODO: const members are always a problem. They break value semantics, same as a reference-member. 
	static constexpr int wall_y_offset = 400; //TODO: you meant to write static const or static constexpr. 
	std::vector<Wall> walls_vec{};

	Walls() noexcept {
		 const float window_width = gsl::narrow_cast<float>(GetScreenWidth());
		 const float window_height = gsl::narrow_cast<float>(GetScreenHeight());
		 const float wall_distance = window_width / wallCount;
		 
		 for (int i : std::views::iota(0, wallCount)) {
			 walls_vec.emplace_back(Vector2{ wall_distance * i, window_height - wall_y_offset });
		 }
	}
};