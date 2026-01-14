#pragma once
#include "Resources.h"
#include "player.h"
#include "alien.h"
#include "walls.h"
#include "background.h"
#include "Projectiles.h"
#include <vector>

class Game
{
private:
	float shootTimer = 0;

	Resources resources;

	Player player;

	std::vector<EnemyProjectile> enemyProjectiles{};
	std::vector<PlayerProjectile> playerProjectiles{};

	Walls walls = Walls();

	Background background;

	Aliens aliens;

	void PlayerShoot() noexcept;
	void AliensShoot();
	void PlayerProjectileCollisionCheck() noexcept;
	void EnemyProjectileCollisionCheck() noexcept;
	void EraseInactiveProjectiles() noexcept;
public:

	int& GetPlayerLives() noexcept;

	void Update();
	void Render() const noexcept;
};