#include "Leaderboard.h"
#include "playerScore.h"
#include <vector>
#include <algorithm>
#include <ranges>

void LeaderBoard::SetNewHighScore(bool condition) noexcept
{
	newHighScore = condition;
}

bool LeaderBoard::GetNewHighScore() noexcept
{
	return newHighScore;
}

const bool LeaderBoard::GetNewHighScore() const noexcept
{
	return newHighScore;
}

bool LeaderBoard::CheckNewHighScore(int score) const noexcept {
	return !Leaderboard.empty() && score > Leaderboard.back().score;
}

void LeaderBoard::InsertNewHighScore(std::string name, int score) noexcept {
	Leaderboard.emplace_back(name, score);
	std::ranges::sort(Leaderboard, std::ranges::greater{}, &PlayerData::score);
	Leaderboard.pop_back();
}

LeaderBoard::LeaderBoard() noexcept
{
	if (CheckNewHighScore(playerScore.GetScore())) {
		newHighScore = true;
	}
}

const std::vector<PlayerData> LeaderBoard::GetLeaderboard() const noexcept
{
	return Leaderboard;
}

std::string& TextBox::GetName() noexcept
{
	return name;
}

const std::string& TextBox::GetName() const noexcept
{
	return name;
}

bool& TextBox::GetMouseOnText() noexcept
{
	return mouseOnText;
}

const bool& TextBox::GetMouseOnText() const noexcept
{
	return mouseOnText;
}

void TextBox::SetMouseOnText(bool condition) noexcept
{
	mouseOnText = condition;
}

const Rectangle& TextBox::GetRect() const noexcept
{
	return textBox;
}
