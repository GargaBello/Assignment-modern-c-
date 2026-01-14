#pragma once

#include "raylib.h"
#include "game.h"
#include "start_menu.h"
#include "end_menu.h"
#include "Leaderboard.h"


struct App {
private:
	Window window;
	StartMenu start_menu;
	EndMenu end_menu;
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

public:
	App() noexcept {
		game = std::make_unique<Game>();
	}

	void Run();
};