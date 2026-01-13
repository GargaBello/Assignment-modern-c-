#include "game.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>

/* TODO: Make into construction, make all initialisations inside constructions aswell
* Change the starting of the game as needed to compensate
* Make for loops into an algo or ranged for loops
*/
void Game::Start()
{
	/* TODO: Find better solution to resetting player attributes when game is restarted without game struct being reconstructed
	*/
	player.lives = 3;

	SpawnAliens();

	score = 0;
}

/* TODO: maybe make into destructor
* Refactor away, find new way to restar game, probably reconstruct the game 
*/

void Game::End()
{
	playerProjectiles.clear();
	enemyProjectiles.clear();
	walls.walls_vec.clear();
	Aliens.clear();
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
		
		for (auto& alien : Aliens)
		{
			alien.Update(); 

			if (alien.position.y > GetScreenHeight() - player.player_base_height)
			{
				End();
			}
		}

		if (Aliens.size() < 1)
		{
			SpawnAliens();
		}

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
			for (auto& alien : Aliens)
			{
				if (CheckCollisionRecs(player.rect, projectile.rect)) {
					projectile.active = false;
					alien.active = false;
					score += 100;
				}
			}

			for (auto& projectile : enemyProjectiles)
			{
				if (CheckCollisionRecs(player.rect, projectile.rect)) {
					projectile.active = false;
					player.lives -= 1;
				}
			}

			for (auto& wall : walls.walls_vec)
			{
				if (CheckCollisionRecs(player.rect, projectile.rect)) {
					projectile.active = false;
					wall.health -= 1;
				}
			}
		}

		if (IsKeyPressed(KEY_SPACE))
		{
			const float window_height = static_cast<float>(GetScreenHeight()); // TODO: use narrow cast instead
			const Vector2 projPos = { player.x_pos, window_height - 130};
			const PlayerProjectile newProjectile(projPos);
			playerProjectiles.push_back(newProjectile);
		}

		shootTimer += 1;
		if (shootTimer > 59) //once per second
		{
			//TODO: Refactor random system

			int randomAlienIndex = 0;

			if (Aliens.size() > 1)
			{
				randomAlienIndex = rand() % Aliens.size();
			}

			Vector2 projPos = { Aliens[randomAlienIndex].position};
			projPos.y += 40;
			const EnemyProjectile newProjectile(projPos);
			enemyProjectiles.push_back(newProjectile);
			shootTimer = 0;
		}

		std::erase_if(playerProjectiles, [](const auto& projectile) { return !projectile.active; });
		std::erase_if(enemyProjectiles, [](const auto& projectile) { return !projectile.active; });

		std::erase_if(Aliens, [](const auto& alien) { return !alien.active; });

		std::erase_if(walls.walls_vec, [](const auto& wall) { return !wall.active; });
}

/* TODO: Move the draw functions built into raylib here
* Make for loop into ranged for loop
* Probably change something with the textbox in leaderboard, ill get to it eventually
*/

void Game::Render()
{
	Drawer drawer;

	background.Render();
	
	DrawText(TextFormat("Score: %i", score), 50, 20, 40, YELLOW);
	DrawText(TextFormat("Lives: %i", player.lives), 50, 70, 40, YELLOW);
	
	//player rendering 
	player.Render(resources.shipTexture.GetTexture());
	
	//projectile rendering
	for (auto& projectile : playerProjectiles)
	{
		projectile.Render(resources.laserTexture.GetTexture());
	}
	
	for (auto& projectile : enemyProjectiles)
	{
		projectile.Render(resources.laserTexture.GetTexture());
	}
	
	// wall rendering 
	for (auto& wall : walls.walls_vec)
	{
		wall.Render(resources.barrierTexture.GetTexture());
	}
	
	//alien rendering  
	for (auto& alien : Aliens)
	{
		alien.Render(resources.alienTexture.GetTexture());
	}
}

/* TODO: Make for loops into ranged for loops
* Make alien an construction
* maybe put in alien.h
*/
void Game::SpawnAliens()
{
	for (const int& row : std::views::iota(0, formationHeight)) {
		for (const int& col : std::views::iota(0, formationHeight)) {
			Vector2 alienPos = { formationX + 450 + (col * alienSpacing), formationY + (row * alienSpacing) };
			Alien newAlien(alienPos);
			Aliens.push_back(newAlien);
		}
	}
}
