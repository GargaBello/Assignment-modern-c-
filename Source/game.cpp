#include "raylib.h"
#include "game.h"
#include "playerScore.h"
#include <algorithm>
#include <random>

int& Game::GetPlayerLives() noexcept
{
	return player.GetLives();
}

void Game::Update()
{
		player.Update();
		
		for (auto& alien : aliens.GetVector())
		{
			alien.Update(); 

			if (alien.GetPosition().y > player.GetPosition().y)
			{
				player.Kill();
			}
		}

		aliens.Update();

		for (auto& projectile : playerProjectiles)
		{
			projectile.Update();
		}

		for (auto& projectile : enemyProjectiles)
		{
			projectile.Update();
		}

		for (auto& wall : walls.GetVector())
		{
			wall.Update();
		}

		PlayerProjectileCollisionCheck();

		EnemyProjectileCollisionCheck();

		PlayerShoot();

		AliensShoot();

		EraseInactiveProjectiles();
		aliens.RemoveInactive();
		walls.RemoveInactive();
}

void Game::Render() const noexcept
{
	background.Render();
	
	static constexpr int X_pos = 50, Y_pos = 20, FontThickness = 40;
	DrawText(TextFormat("Score: %i", playerScore.GetScore()), X_pos, Y_pos, FontThickness, YELLOW);
	static constexpr int Y_pos2 = 70;
	DrawText(TextFormat("Lives: %i", player.GetLives()), X_pos, Y_pos2, FontThickness, YELLOW);
	
	player.Render(resources.GetShipTexture());
	
	for (auto& projectile : playerProjectiles)
	{
		projectile.Render(resources.GetLaserTexture());
	}
	
	for (auto& projectile : enemyProjectiles)
	{
		projectile.Render(resources.GetLaserTexture());
	}
	
	for (auto& wall : walls.GetVector())
	{
		wall.Render(resources.GetBarrierTexture());
	}
	
	for (auto& alien : aliens.GetVector())
	{
		alien.Render(resources.GetAlienTexture());
	}
}

template <typename T>
T& GetRandomElement(std::vector<T>& v, std::mt19937& rng) {
	if (v.empty()) throw std::runtime_error("Cannot get random element from empty vector");
	std::uniform_int_distribution<std::size_t> dist(0, v.size() - 1);
	return v[dist(rng)];
}

void Game::PlayerShoot() noexcept {
	if (IsKeyPressed(KEY_SPACE))
	{
		static constexpr int bottom_offset = 240;
		playerProjectiles.emplace_back(Vector2{ player.GetPosition().x, gsl::narrow_cast<float>(GetScreenHeight() - bottom_offset) });
	}
}

void Game::AliensShoot()
{
	shootTimer += 1;
	if (shootTimer > 59)
	{
		std::mt19937 rng{ std::random_device{}() };
		Alien& alien = GetRandomElement(aliens.GetVector(), rng);
		constexpr int height_offset = 40;
		enemyProjectiles.emplace_back(Vector2{ alien.GetPosition().x, alien.GetPosition().y + height_offset });
		shootTimer = 0;
	}
}

void Game::PlayerProjectileCollisionCheck() noexcept
{
	for (auto& projectile : playerProjectiles)
	{
		for (auto& alien : aliens.GetVector())
		{
			if (CheckCollisionRecs(alien.GetCollisionBox(), projectile.GetCollisionBox())) {
				projectile.SetActive(false);
				alien.SetActive(false);
				playerScore.AddPoints();
			}
		}

		for (auto& wall : walls.GetVector())
		{
			if (CheckCollisionRecs(wall.GetCollisionBox(), projectile.GetCollisionBox())) {
				projectile.SetActive(false);
				wall.ReduceHealth();
			}
		}
	}
}

void Game::EnemyProjectileCollisionCheck() noexcept
{
	for (auto& projectile : enemyProjectiles)
	{
		if (CheckCollisionRecs(player.GetCollisionBox(), projectile.GetCollisionBox())) {
			projectile.SetActive(false);
			player.ReduceHealth();
		}

		for (auto& wall : walls.GetVector())
		{
			if (CheckCollisionRecs(wall.GetCollisionBox(), projectile.GetCollisionBox())) {
				projectile.SetActive(false);
				wall.ReduceHealth();
			}
		}
	}
}

void Game::EraseInactiveProjectiles() noexcept
{
	std::erase_if(playerProjectiles, [](const auto& projectile) noexcept { return !projectile.GetActive(); });
	std::erase_if(enemyProjectiles, [](const auto& projectile) noexcept { return !projectile.GetActive(); });
}
