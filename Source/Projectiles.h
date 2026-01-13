#pragma once
#include "raylib.h"

struct PlayerProjectile {
	Vector2 position{};
	int speed = -15; // 15 if player //TODO: this comments begs to become a function. Projectile::isPlayerProjectile() { return speed < 0;} 
	float width = 15;
	float bullet_width_offset = 17.5f;
	bool active = true;

	Rectangle rect = { position.x + bullet_width_offset, position.y, width, width }; //TODO: these are clearly mad. you already have position. The projectile is a simple rectangle. just use rect/rect intersection tests
	 //TODO: refactor the projectile to remove this.

	void Update() noexcept {
		if (position.y < 0 || position.y > 1500)
		{
			active = false;
		}

		position.y += speed;
		rect.y = position.y;
	} //noexcept

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
		DrawRectangleLinesEx(rect, 5, DARKPURPLE);
	} //const noexcept
};

struct EnemyProjectile {
	Vector2 position{};
	int speed = 15; // 15 if player //TODO: this comments begs to become a function. Projectile::isPlayerProjectile() { return speed < 0;} 
	float width = 15;
	float bullet_width_offset = 17.5f;
	float bullet_height_offset = 30.0f;
	bool active = true;

	Rectangle rect = { position.x + bullet_width_offset, position.y + width, width, width }; //TODO: these are clearly mad. you already have position. The projectile is a simple rectangle. just use rect/rect intersection tests
	 //TODO: refactor the projectile to remove this.

	void Update() noexcept {
		if (position.y < 0 || position.y > 1500)
		{
			active = false;
		}

		position.y += speed;
		rect.y = position.y + bullet_height_offset;
	} //noexcept

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
		DrawRectangleLinesEx(rect, 5, DARKPURPLE);
	}//const noexcept
};