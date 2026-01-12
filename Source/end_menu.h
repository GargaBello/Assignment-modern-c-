#pragma once

#include "raylib.h"
#include "Leaderboard.h"

struct EndMenu {

	TextBox box;
	LeaderBoard Leaderboard;
	bool restartGame = false;

	void Render() noexcept;

	void Update();
};