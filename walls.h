#pragma once
#include "raylib.h"
#include <vector>

struct Wall
{
	Vector2 position{};
	bool active = false;
	int health = 50;
	int width = 60;

	Rectangle rect = { position.x, position.y, width, width };

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
	}

	void Update() noexcept {
		if (health < 1)
		{
			active = false;
		}
	}
};

struct Walls
{
	int wallCount = 5; //TODO: const members are always a problem. They break value semantics, same as a reference-member. 
	float wall_y_offset = 250; //TODO: you meant to write static const or static constexpr. 
	std::vector<Wall> walls_vec{};
};