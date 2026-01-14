#pragma once
#include "raylib.h"
#include "gsl/algorithm"

class Player {
private:
	Vector2 position = { gsl::narrow_cast<float>(GetScreenWidth()) / 2, gsl::narrow_cast<float>(GetScreenHeight() - 200) };
	float speed = 7;
	static constexpr float radius = 100.0f;
	float timer = 0;
	static constexpr int spawn_offset = 200;
	int lives = 3;

	Rectangle rect = { position.x, position.y, radius, radius };

public:

	Vector2& GetPosition() noexcept {
		return position;
	}

	Rectangle& GetCollisionBox() noexcept {
		return rect;
	}

	int& GetLives() noexcept {
		return lives;
	}

	const int& GetLives() const noexcept {
		return lives;
	}

	void ReduceHealth() noexcept {
		static constexpr int damage = 1;
		lives -= damage;
	}

	void Kill() noexcept {
		lives = 0;
	}

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
	};

	void Update() noexcept {
		if (IsKeyDown(KEY_LEFT))
		{
			position.x -= speed;
		}
		else if (IsKeyDown(KEY_RIGHT))
		{
			position.x += speed;
		}

		rect.x = position.x;

		if (position.x < 0 + radius) { position.x = 0 + radius; }
		else if (position.x > GetScreenWidth() - radius) { position.x = GetScreenWidth() - radius; }
	}
};