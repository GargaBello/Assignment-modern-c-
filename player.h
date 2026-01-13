#pragma once
#include "raylib.h"
#include "gsl/algorithm"

struct Player {
	float x_pos = gsl::narrow_cast<float>(GetScreenWidth()) / 2;
	float y_pos = gsl::narrow_cast<float>(GetScreenHeight()) - player_base_height;
	float speed = 7; //TODO: velocity already has direction, so either this or int direction needs to go. 
	float player_base_height = 70.0f;
	float radius = 50.0f;
	float timer = 0;
	int lives = 3;
	int activeTexture = 0;

	const void Render(Texture2D texture) noexcept {
		DrawTextureV(texture, { x_pos, y_pos }, WHITE);
	}; //TODO: render should always be const

	void Update() noexcept {
		if (IsKeyDown(KEY_LEFT))
		{
			speed = -7;
		}
		if (IsKeyDown(KEY_RIGHT))
		{
			speed = 7;
		}

		x_pos += speed;

		if (x_pos < 0 + radius)
		{
			x_pos = 0 + radius;
		}
		else if (x_pos > GetScreenWidth() - radius)
		{
			x_pos = GetScreenWidth() - radius;
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
	}//TODO: surely this can be noexcept? 
};