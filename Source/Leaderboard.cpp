#include "Leaderboard.h"

bool LeaderBoard::CheckNewHighScore(int score) const noexcept {
	return !Leaderboard.empty() && score > Leaderboard.back().score;
}

void LeaderBoard::InsertNewHighScore(std::string name, int score) noexcept {
	Leaderboard.emplace_back(name, score);
	std::ranges::sort(Leaderboard, std::ranges::greater{}, &PlayerData::score);
	Leaderboard.pop_back();
}

std::vector<PlayerData> LeaderBoard::GetLeaderboard() const noexcept
{
	return Leaderboard;
}