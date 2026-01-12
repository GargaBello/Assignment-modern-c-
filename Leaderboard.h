#pragma once

#include "raylib.h"
#include <string_view>
#include <string>
#include <vector>

struct PlayerData
{
	std::string name{};
	int score = 0;

	PlayerData(std::string name, int score);
};

class LeaderBoard {
private:
	std::vector<PlayerData> Leaderboard = { {"Player 1", 500}, {"Player 2", 400}, {"Player 3", 300}, {"Player 4", 200}, {"Player 5", 100} };
public:
	bool newHighScore = false;

	bool CheckNewHighScore(int score) const;

	void InsertNewHighScore(std::string name, int score);

	std::vector<PlayerData> GetLeaderboard();

	LeaderBoard() = default;
};

struct TextBox {
	//TEXTBOX ENTER
	std::string name{};      //Should be maximum of 8 letters
	int letterCount = 0;

	Rectangle textBox = { 600, 500, 225, 50 };
	bool mouseOnText = false;

	int framesCounter = 0;

	TextBox() = default;
};