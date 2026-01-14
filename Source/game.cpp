#include "game.h"

void Game::Update()
{
		player.Update();
		
		for (auto& alien : aliens.GetVector())
		{
			alien.Update(); 

			if (alien.GetPosition().y > player.GetPosition().y)
			{
				player.lives = 0;
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

		for (auto& wall : walls.walls_vec)
		{
			wall.Update();
		}

		for (auto& projectile : playerProjectiles)
		{
			for (auto& alien : aliens.GetVector())
			{
				if (CheckCollisionRecs(alien.GetCollisionBox(), projectile.rect)) {
					projectile.active = false;
					alien.SetActive(false);
					playerScore.score += 100;
				}
			}

			for (auto& wall : walls.walls_vec)
			{
				if (CheckCollisionRecs(wall.rect, projectile.rect)) {
					projectile.active = false;
					wall.health -= 1;
				}
			}
		}

		for (auto& projectile : enemyProjectiles)
		{
			if (CheckCollisionRecs(player.rect, projectile.rect)) {
				projectile.active = false;
				player.lives -= 1;
			}

			for (auto& wall : walls.walls_vec)
			{
				if (CheckCollisionRecs(wall.rect, projectile.rect)) {
					projectile.active = false;
					wall.health -= 1;
				}
			}
		}

		if (IsKeyPressed(KEY_SPACE))
		{
			static constexpr int bottom_offset = 240;
			playerProjectiles.emplace_back(Vector2{ player.position.x, gsl::narrow_cast<float>(GetScreenHeight() - bottom_offset) });
		}

		shootTimer += 1;
		if (shootTimer > 59)
		{
			std::mt19937 rng{ std::random_device{}() };
			Alien& alien = aliens.GetRandomElement(aliens.GetVector(), rng);
			constexpr int height_offset = 40;
			enemyProjectiles.emplace_back(Vector2{ alien.GetPosition().x, alien.GetPosition().y + height_offset });
			shootTimer = 0;
		}

		std::erase_if(playerProjectiles, [](const auto& projectile) { return !projectile.active; });
		std::erase_if(enemyProjectiles, [](const auto& projectile) { return !projectile.active; });
		aliens.RemoveInactive();
		std::erase_if(walls.walls_vec, [](const auto& wall) { return !wall.active; });
}

void Game::Render() const noexcept
{
	background.Render();
	
	DrawText(TextFormat("Score: %i", playerScore.score), 50, 20, 40, YELLOW);
	DrawText(TextFormat("Lives: %i", player.lives), 50, 70, 40, YELLOW);
	
	player.Render(resources.shipTexture.GetTexture());
	
	for (auto& projectile : playerProjectiles)
	{
		projectile.Render(resources.laserTexture.GetTexture());
	}
	
	for (auto& projectile : enemyProjectiles)
	{
		projectile.Render(resources.laserTexture.GetTexture());
	}
	
	for (auto& wall : walls.walls_vec)
	{
		wall.Render(resources.barrierTexture.GetTexture());
	}
	
	for (auto& alien : aliens.GetVector())
	{
		alien.Render(resources.alienTexture.GetTexture());
	}
}
