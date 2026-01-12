#pragma once

#include "raylib.h"

struct StartMenu {

	bool start_game = false;

	void Render() noexcept;

	void Update();
};