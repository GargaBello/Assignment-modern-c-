#pragma once
#include "raylib.h"
#include <vector>

struct Alien
{
	Vector2 position{};
	float radius = 30; 
	bool active = true;
	int speed = 2;

	Rectangle rect = { position.x, position.y, radius, radius };

	void Update() noexcept {
		position.x += speed;

		if (position.x >= GetScreenWidth())
		{
			speed = -2;
			position.y += 50;
		}
		else if (position.x <= 0)
		{
			speed = 2;
			position.y += 50;
		}
	}

	void Render(Texture2D texture) const noexcept{
		DrawTextureV(texture, position, WHITE);
	}
};

struct Aliens {
	std::vector<Alien> aliens{};

	int formationWidth = 8;
	int formationHeight = 5;
	float alienSpacing = 80;
	float formationX = 100;
	float formationY = 50;

	Aliens() noexcept { // TODO: use other algo than iota
		for (const int& row : std::views::iota(0, formationHeight)) {
			for (const int& col : std::views::iota(0, formationHeight)) {
				Vector2 alienPos = { formationX + 450 + (col * alienSpacing), formationY + (row * alienSpacing) };
				Alien newAlien(alienPos);
				aliens.push_back(newAlien);
			}
		}
	}

	void Update() {
		if (aliens.size() < 1) {
			for (const int& row : std::views::iota(0, formationHeight)) {
				for (const int& col : std::views::iota(0, formationHeight)) {
					Vector2 alienPos = { formationX + 450 + (col * alienSpacing), formationY + (row * alienSpacing) };
					Alien newAlien(alienPos);
					aliens.push_back(newAlien);
				}
			}
		}
	}
};