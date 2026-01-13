#pragma once

#include "raylib.h"

struct StartMenu {

	bool start_game = false;

	void Render() const noexcept;

	void Update() noexcept;
};