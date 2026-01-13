#pragma once
#include "raylib.h"
#include "Resources.h"
#include "player.h"
#include "alien.h"
#include "walls.h"
#include "background.h"
#include "Projectiles.h"
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>
#include <print>

struct Game
{
	// Score
	int score = 0;

	//Aliens shooting
	float shootTimer = 0;

	void Start();
	void End();

	void Update();
	void Render();

	void SpawnAliens();

	//TODO: raylib has a rectangle interfection test. use it. Replace all custom collision logic with the library function, and make all entities adhere to the simple
	// Rectangle getCollisionBox() const noexcept interface. 

	Resources resources; //consider using RAII and just giving each type their own Resource handle. No reason to store those assets here in game. 

	Player player;

	std::vector<EnemyProjectile> enemyProjectiles{}; 
	std::vector<PlayerProjectile> playerProjectiles{};

	Walls walls;

	Background background;

	Aliens aliens;
};