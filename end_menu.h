#pragma once

#include "raylib.h"

struct EndMenu {

	TextBox box;
	LeaderBoard Leaderboard;

	void Render() noexcept;

	void Update();
};