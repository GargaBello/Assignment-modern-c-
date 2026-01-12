#include "Leaderboard.h"

bool LeaderBoard::CheckNewHighScore(int score) const noexcept {
	return !Leaderboard.empty() && score > Leaderboard.back().score;
}

void LeaderBoard::InsertNewHighScore(std::string name, int score) {
	PlayerData newData(name, score);
	

	/*for (auto& highscore : Leaderboard)
	{
		if (newData.score > highscore.score)
		{

			Leaderboard.insert(Leaderboard.begin() + i, newData);

			Leaderboard.pop_back();

			i = Leaderboard.size();

		}
	}*/

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


