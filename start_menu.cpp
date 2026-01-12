#include "start_menu.h"

void StartMenu::Update() {
	if (IsKeyReleased(KEY_SPACE))
	{
		
	}
}

void StartMenu::Render() noexcept {
	DrawText("SPACE INVADERS", 200, 100, 160, YELLOW);

	DrawText("PRESS SPACE TO BEGIN", 200, 350, 40, YELLOW);
}