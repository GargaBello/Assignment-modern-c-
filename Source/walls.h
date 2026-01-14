#pragma once
#include "raylib.h"
#include <vector>

struct Wall
{
	Vector2 position{};
	bool active = true;
	int health = 50;
	float width = 100.0f;

	Rectangle rect = { position.x, position.y, width * 2, width };

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
		DrawRectangleLinesEx(rect, 5, DARKPURPLE);
	}

	

	void Update() noexcept {
		if (health < 1)
		{
			active = false;
		}

		rect.x = position.x;
		rect.y = position.y;
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
		 const float wall_distance = window_width / (wallCount);
		 
		 for (int i : std::views::iota(0, wallCount)) {
			 const float x = wall_distance * (i + 1);
			 const float y = window_height - wall_y_offset;
			 walls_vec.emplace_back(Vector2{x, y});
		 }
	}
};