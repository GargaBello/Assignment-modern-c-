#pragma once

#include "raylib.h"
#include <string_view>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

struct PlayerData
{
	std::string name{};
	int score = 0;

	PlayerData(std::string name, int score);
};

class LeaderBoard {
private:
	std::vector<PlayerData> Leaderboard = { PlayerData{"Player 1", 500}, PlayerData{"Player 2", 400}, PlayerData{"Player 3", 300}, PlayerData{"Player 4", 200}, PlayerData{"Player 5", 100} };
public:
	bool newHighScore = false;

	bool CheckNewHighScore(int score) const noexcept;

	void InsertNewHighScore(std::string name, int score);

	std::vector<PlayerData> GetLeaderboard();

	LeaderBoard() = default;
};

struct TextBox {
	std::string name{};
	int letterCount = 0;

	Rectangle textBox = { 600, 500, 225, 50 };
	bool mouseOnText = false;

	int framesCounter = 0;

	TextBox() = default;
};