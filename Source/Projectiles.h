#pragma once
#include "raylib.h"

struct PlayerProjectile {
	Vector2 position{};
	int speed = 15; // 15 if player //TODO: this comments begs to become a function. Projectile::isPlayerProjectile() { return speed < 0;} 
	float width = 15;
	bool active = true;

	Rectangle rect = { position.x, position.y, width, width }; //TODO: these are clearly mad. you already have position. The projectile is a simple rectangle. just use rect/rect intersection tests
	 //TODO: refactor the projectile to remove this.

	void Update() noexcept {
		if (position.y < 0 || position.y > 1500)
		{
			active = false;
		}
	} //noexcept

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
	} //const noexcept
};

struct EnemyProjectile {
	Vector2 position{};
	int speed = -15; // 15 if player //TODO: this comments begs to become a function. Projectile::isPlayerProjectile() { return speed < 0;} 
	float width = 15;
	bool active = true;

	Rectangle rect = { position.x, position.y, width, width }; //TODO: these are clearly mad. you already have position. The projectile is a simple rectangle. just use rect/rect intersection tests
	 //TODO: refactor the projectile to remove this.

	void Update() noexcept {
		if (position.y < 0 || position.y > 1500)
		{
			active = false;
		}
	} //noexcept

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
	}//const noexcept
};