#pragma once

#include "raylib.h"
#include "Leaderboard.h"

struct EndMenu {

	TextBox box;
	LeaderBoard Leaderboard;
	PlayerData leaderboardData;
	bool restartGame = false;

	void Render() noexcept;

	void Update();
};