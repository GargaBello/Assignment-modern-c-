#pragma once
#include "raylib.h"
#include <vector>

struct Wall
{
	Vector2 position{ gsl::narrow_cast<float>(GetScreenWidth()) / 2, gsl::narrow_cast<float>(GetScreenHeight()) / 2  };
	bool active = false;
	int health = 50;
	float width = 100.0f;

	Rectangle rect = { position.x, position.y, width, width };

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
	float wall_y_offset = 250; //TODO: you meant to write static const or static constexpr. 
	std::vector<Wall> walls_vec{ Wall({gsl::narrow_cast<float>(GetScreenWidth()) / 2, gsl::narrow_cast<float>(GetScreenHeight()) / 2 })};

	Walls() noexcept {
		 const float window_width = gsl::narrow_cast<float>(GetScreenWidth());
		 const float window_height = gsl::narrow_cast<float>(GetScreenHeight());
		 const float wall_distance = window_width / (wallCount + 1);
		 
		 for (const int i : std::views::iota(0, wallCount)) {
			Wall new_wall({ wall_distance * (i + 1), window_height - 250 });
		 	walls_vec.push_back(new_wall);
		 }
	}
};