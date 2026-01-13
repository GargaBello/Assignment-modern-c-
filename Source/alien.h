#pragma once
#include "raylib.h"

struct Alien
{
	Vector2 position{};
	float radius = 30; 
	bool active = true;

	int speed = 2; 

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