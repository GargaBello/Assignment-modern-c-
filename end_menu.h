#pragma once

#include "raylib.h"

struct EndMenu {

	TextBox box;
	LeaderBoard Leaderboard;

	void Render();

	void Update();
};