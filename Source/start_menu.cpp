#include "start_menu.h"
#include "raylib.h"

void StartMenu::Update() noexcept{
	if (IsKeyReleased(KEY_SPACE))
	{
		start_game = true;
	}
}

bool& StartMenu::GetStartGame() noexcept
{
	return start_game;
}

void StartMenu::SetStarGame(bool condition) noexcept
{
	start_game = condition;
}

void StartMenu::Render() const noexcept {
	static constexpr int X_pos = 200, Y_pos = 100, Thickness = 160;
	DrawText("SPACE INVADERS", X_pos, Y_pos, Thickness, YELLOW);
	static constexpr int Y_pos2 = 350, Thickness2 = 40;
	DrawText("PRESS SPACE TO BEGIN", X_pos, Y_pos2, Thickness2, YELLOW);
}