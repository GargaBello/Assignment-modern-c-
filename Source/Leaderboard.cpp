#include "Leaderboard.h"

bool LeaderBoard::CheckNewHighScore(int score) const noexcept {
	return !Leaderboard.empty() && score > Leaderboard.back().score;
}

void LeaderBoard::InsertNewHighScore(std::string name, int score) {
	PlayerData newData;
	Leaderboard.push_back(newData);
	std::ranges::sort(Leaderboard, std::ranges::greater{}, &PlayerData::score);
	Leaderboard.pop_back();
	
	//consider: 
	// push_back the new value
	// sort the vector
	// if the vector is too long, pop_back
}

std::vector<PlayerData> LeaderBoard::GetLeaderboard()
{
	return Leaderboard;
}