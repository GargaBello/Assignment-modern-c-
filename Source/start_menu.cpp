#include "start_menu.h"

/* TODO: Make work
* 
*/

void StartMenu::Update() {
	if (IsKeyReleased(KEY_SPACE))
	{
		start_game = true;
	}
}

void StartMenu::Render() noexcept {
	DrawText("SPACE INVADERS", 200, 100, 160, YELLOW);

	DrawText("PRESS SPACE TO BEGIN", 200, 350, 40, YELLOW);
}