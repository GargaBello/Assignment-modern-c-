#include "playerScore.h"

PlayerScore playerScore;

void PlayerScore::AddPoints() noexcept
{
	score += points_to_add;
}

int PlayerScore::GetScore() noexcept
{
	return score;
}

void PlayerScore::ResetScore() noexcept
{
	score = 0;
}
