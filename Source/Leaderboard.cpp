#include "Leaderboard.h"

bool LeaderBoard::CheckNewHighScore(int score) const noexcept {
	return !Leaderboard.empty() && score > Leaderboard.back().score;
}

void LeaderBoard::InsertNewHighScore(std::string name, int score) {
	PlayerData newData;
	Leaderboard.push_back(newData);
	//std::ranges::sort(Leaderboard, {}, &PlayerData::score); // check if this is right
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



//PlayerData::PlayerData(std::string name)
//	: name(name)
//{
//}


