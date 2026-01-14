#pragma once
#include "raylib.h"

class PlayerProjectile {
private:
	Vector2 position{};
	static constexpr int speed = -15;  
	static constexpr float width = 15;
	static constexpr float bullet_width_offset = 17.5f;
	bool active = true;

	Rectangle rect = { position.x + bullet_width_offset, position.y, width, width };

public:

	Rectangle& GetCollisionBox() noexcept {
		return rect;
	}

	bool& GetActive() noexcept {
		return active;
	}

	const bool& GetActive() const noexcept {
		return active;
	}

	void SetActive(bool condition) noexcept {
		active = condition;
	}

	void Update() noexcept {
		if (position.y < 0 || position.y > 1500)
		{
			active = false;
		}

		position.y += speed;
		rect.y = position.y;
	} 

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
		DrawRectangleLinesEx(rect, 5, DARKPURPLE);
	} 

	PlayerProjectile(Vector2 position) noexcept
		: position(position)
	{ }
};

class EnemyProjectile {
private:
	Vector2 position{};
	static constexpr int speed = 15; 
	static constexpr float width = 15;
	static constexpr float bullet_width_offset = 17.5f;
	static constexpr float bullet_height_offset = 30.0f;
	bool active = true;

	Rectangle rect = { position.x + bullet_width_offset, position.y + width, width, width };

public:

	Rectangle& GetCollisionBox() noexcept {
		return rect;
	}

	bool& GetActive() noexcept {
		return active;
	}

	const bool& GetActive() const noexcept {
		return active;
	}

	void SetActive(bool condition) noexcept {
		active = condition;
	}

	void Update() noexcept {
		if (position.y < 0 || position.y > 1500)
		{
			active = false;
		}

		position.y += speed;
		rect.y = position.y + bullet_height_offset;
	} 

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
		DrawRectangleLinesEx(rect, 5, DARKPURPLE);
	}

	EnemyProjectile(Vector2 position) noexcept
		: position(position)
	{
	}
};