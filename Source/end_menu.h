#pragma once

#include "raylib.h"
#include "Leaderboard.h"
#include "playerScore.h"
#include "gsl/algorithm"
#include <string>

struct EndMenu {

	TextBox box;
	LeaderBoard Leaderboard;
	PlayerData leaderboardData;
	bool restartGame = false;

	bool isValidCharacter(int key) noexcept;
	void Render() const noexcept;
	void Update() noexcept;
};