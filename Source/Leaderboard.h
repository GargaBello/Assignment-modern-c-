#pragma once
#include "raylib.h"
#include <vector>
#include <string>

struct PlayerData
{
	std::string name{};
	int score = 0;
};

class LeaderBoard {
private:
	std::vector<PlayerData> Leaderboard = { PlayerData("Player 1", 500), PlayerData("Player 2", 400), PlayerData("Player 3", 300), PlayerData("Player 4", 200), PlayerData("Player 5", 100), };
	bool newHighScore = false;
public:

	void SetNewHighScore(bool condition) noexcept;

	bool GetNewHighScore() noexcept;

	const bool GetNewHighScore() const noexcept;

	bool CheckNewHighScore(int score) const noexcept;

	void InsertNewHighScore(std::string name, int score) noexcept;

	LeaderBoard() noexcept;

	const std::vector<PlayerData> GetLeaderboard() const noexcept;
};

class TextBox {
private:
	std::string name{};

	static constexpr Rectangle textBox = { 600, 500, 225, 50 };
	bool mouseOnText = false;

public:

	std::string& GetName() noexcept;
	const std::string& GetName() const noexcept;

	bool& GetMouseOnText() noexcept;
	const bool& GetMouseOnText() const noexcept;
	void SetMouseOnText(bool condition) noexcept;

	const Rectangle& GetRect() const noexcept;

	TextBox() = default;
};