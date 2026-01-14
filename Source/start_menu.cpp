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
	DrawText("SPACE INVADERS", 200, 100, 160, YELLOW);

	DrawText("PRESS SPACE TO BEGIN", 200, 350, 40, YELLOW);
}