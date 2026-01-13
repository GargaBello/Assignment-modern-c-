#include "game.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>

/* TODO: maybe make into destructor
* Refactor away, find new way to restar game, probably reconstruct the game 
*/

void Game::End()
{
	playerProjectiles.clear();
	enemyProjectiles.clear();
	walls.walls_vec.clear();
	aliens.aliens.clear();
}

/* TODO: Change iskeyreleased to iskeypressed
* Signal that q ends the game or make it escape
* Change all for loop to ranged for loop
* Invert the collision checking or make it less nested
* Maybe make the collision check a template free function that can check both types of projectiles
* Make projectile creation a construction instead of two step initialisation
* Look into the erasing of entities and see if there is a better way
* Probly change the way the name in the highscore is put in and especially make it string or string_view
* Split function into start menu, game screen and end menu and make leaderboard a separate class
*/

void Game::Update()
{
		if (IsKeyReleased(KEY_Q))
		{
			End();
		}

		player.Update();
		
		for (auto& alien : aliens.aliens)
		{
			alien.Update(); 

			if (alien.position.y > GetScreenHeight() - player.spawn_offset)
			{
				End();
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
			for (auto& alien : aliens.aliens)
			{
				if (CheckCollisionRecs(alien.rect, projectile.rect)) {
					projectile.active = false;
					alien.active = false;
					leaderboardData.score += 100;
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
			float window_height = static_cast<float>(GetScreenHeight()); // TODO: use narrow cast instead
			Vector2 projPos = { player.position.x, window_height - 130};
			PlayerProjectile newProjectile(projPos);
			playerProjectiles.push_back(newProjectile);
		}

		shootTimer += 1;
		if (shootTimer > 59) //once per second
		{
			//TODO: Refactor random system

			int randomAlienIndex = 0;

			if (aliens.aliens.size() > 1)
			{
				randomAlienIndex = rand() % aliens.aliens.size();
			}

			Vector2 projPos = { aliens.aliens[randomAlienIndex].position};
			projPos.y += 40;
			const EnemyProjectile newProjectile(projPos);
			enemyProjectiles.push_back(newProjectile);
			shootTimer = 0;
		}

		std::erase_if(playerProjectiles, [](const auto& projectile) { return !projectile.active; });
		std::erase_if(enemyProjectiles, [](const auto& projectile) { return !projectile.active; });

		std::erase_if(aliens.aliens, [](const auto& alien) { return !alien.active; });

		std::erase_if(walls.walls_vec, [](const auto& wall) { return !wall.active; });
}

/* TODO: Move the draw functions built into raylib here
* Make for loop into ranged for loop
* Probably change something with the textbox in leaderboard, ill get to it eventually
*/

void Game::Render()
{
	background.Render();
	
	DrawText(TextFormat("Score: %i", score), 50, 20, 40, YELLOW);
	DrawText(TextFormat("Lives: %i", player.lives), 50, 70, 40, YELLOW);
	
	player.Render(resources.shipTexture.GetTexture());
	wall.Render(resources.barrierTexture.GetTexture());
	
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
	
	for (auto& alien : aliens.aliens)
	{
		alien.Render(resources.alienTexture.GetTexture());
	}
}
