#pragma once

#include "raylib.h"
#include "playerScore.h"
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

struct PlayerData
{
	std::string name{};
	int score;

};

struct LeaderBoard {
private:
	std::vector<PlayerData> Leaderboard = { PlayerData("Player 1", 500), PlayerData("Player 2", 400), PlayerData("Player 3", 300), PlayerData("Player 4", 200), PlayerData("Player 5", 100), };
	
public:

	bool newHighScore = false;

	bool CheckNewHighScore(int score) const noexcept;

	void InsertNewHighScore(std::string name, int score);

	LeaderBoard() {
		if (CheckNewHighScore(playerScore.score)) {
			newHighScore = true;
		}
	}

	std::vector<PlayerData> GetLeaderboard() const noexcept;
};

struct TextBox {
	std::string name{};

	Rectangle textBox = { 600, 500, 225, 50 };
	bool mouseOnText = false;

	int framesCounter = 0;

	TextBox() = default;
};