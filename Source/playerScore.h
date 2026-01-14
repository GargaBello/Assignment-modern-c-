#pragma once

class PlayerScore {
private:
	int score = 0;
	static constexpr int points_to_add = 100;

public:
	void AddPoints() noexcept;
	int GetScore() noexcept;
	void ResetScore() noexcept;
};

extern PlayerScore playerScore;