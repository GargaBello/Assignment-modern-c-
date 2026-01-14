#pragma once

#include "raylib.h"
#include "game.h"
#include "start_menu.h"
#include "end_menu.h"
#include "Leaderboard.h"


struct App {
	Window window;
	StartMenu start_menu;
	EndMenu end_menu;
	//Game game;
	std::unique_ptr<Game> game;
	LeaderBoard leaderboard;
	PlayerData leaderboardData;
	

	enum class gameState {
		Start,
		Ingame,
		End,
	};

	gameState state = gameState::Start;

	void RestartGame();

	void Update();
	void Render();
	void Run();

	App() {
		game = std::make_unique<Game>();
	}
};