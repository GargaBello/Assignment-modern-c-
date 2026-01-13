#pragma once
#include "raylib.h"
#include "gsl/algorithm"

struct Player {

	Vector2 position = { gsl::narrow_cast<float>(GetScreenWidth()) / 2, gsl::narrow_cast<float>(GetScreenHeight() - 200) };
	float speed = 7;
	float radius = 50.0f;
	float timer = 0;
	int lives = 3;
	int activeTexture = 0;

	Rectangle rect = { position.x, position.y, radius, radius };

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
	}; //TODO: render should always be const

	void Update() noexcept {
		if (IsKeyDown(KEY_LEFT))
		{
			speed = -7;
			position.x += speed;

		}
		if (IsKeyDown(KEY_RIGHT))
		{
			speed = 7;
			position.x += speed;

		}

		rect.x = position.x;

		if (position.x < 0 + radius)
		{
			position.x = 0 + radius;
		}
		else if (position.x > GetScreenWidth() - radius)
		{
			position.x = GetScreenWidth() - radius;
		}

		timer += GetFrameTime();

		if (timer > 0.4 && activeTexture == 2)
		{
			activeTexture = 0;
			timer = 0;
		}
		else if (timer > 0.4)
		{
			activeTexture++;
			timer = 0;
		}
	}
};