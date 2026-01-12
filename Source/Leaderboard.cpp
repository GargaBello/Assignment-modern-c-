#include "Leaderboard.h"

bool LeaderBoard::CheckNewHighScore(int score) const noexcept {
	return !Leaderboard.empty() && score > Leaderboard.back().score;
}

void LeaderBoard::InsertNewHighScore(std::string name, int score) {
	PlayerData newData(name, score);
	
	//consider: 
	// push_back the new value
	// sort the vector
	// if the vector is too long, pop_back

	auto it = std::find_if(Leaderboard.begin(), Leaderboard.end(),
		[&](const PlayerData& data) {
			return newData.score > data.score;
		});

	if (it != Leaderboard.end()) {
		Leaderboard.insert(it, newData);
		Leaderboard.pop_back();
	}
}

std::vector<PlayerData> LeaderBoard::GetLeaderboard()
{
	return Leaderboard;
}



PlayerData::PlayerData(std::string name, int score)
	: score(score)
	, name(name)
{
}


