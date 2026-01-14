#pragma once
#include "Leaderboard.h"

class EndMenu {
private:

	TextBox box;
	LeaderBoard Leaderboard;
	PlayerData leaderboardData;
	bool restartGame = false;

public:

	bool& GetRestartGame() noexcept;
	void SetRestartGame(bool condition) noexcept;
	void ResetLeaderBoard(LeaderBoard board) noexcept;
	bool isValidCharacter(int key) noexcept;
	void Render() const noexcept;
	void Update() noexcept;
};