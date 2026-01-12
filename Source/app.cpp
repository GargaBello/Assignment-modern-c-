#include "app.h"

void App::Render() {
	Drawer drawer;
	switch (state)
	{
	case App::gameState::Start:
		start_menu.Render();
		break;
	case App::gameState::Ingame:
		game.Render();
		break;
	case App::gameState::End:
		end_menu.Render();
		break;
	default:
		break;
	}
}

void App::Update() {
	switch (state)
	{
	case App::gameState::Start:
		start_menu.Update();
		if (start_menu.start_game == true) {
			start_menu.start_game = false;
			state = gameState::Ingame;
		}
		break;
	case App::gameState::Ingame:
		game.Update();
		if (game.player.lives <= 0) {
			state = gameState::End;
		}
		break;
	case App::gameState::End:
		end_menu.Update();
		if (end_menu.restartGame == true) {
			end_menu.restartGame = false;
			state = gameState::Ingame;
		}
		break;
	default:
		break;
	}
}

void App::Run() {
	while (!WindowShouldClose()) {
		Update();
		Render();
	}
}