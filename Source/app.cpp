#include "app.h"
#include "playerScore.h"

void App::RestartGame()
{
	game = std::make_unique<Game>();
	playerScore.ResetScore();
}

void App::Render() const {
	Drawer drawer;
	switch (state)
	{
	case App::gameState::Start:
		start_menu.Render();
		break;
	case App::gameState::Ingame:
		game.get()->Render();
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
		if (start_menu.GetStartGame()) {
			start_menu.SetStarGame(false);
			state = gameState::Ingame;
			
		}
		break;
	case App::gameState::Ingame:
		game.get()->Update();
		if (game.get()->GetPlayerLives() <= 0) {
			state = gameState::End;
			end_menu.ResetLeaderBoard(LeaderBoard());
		}
		break;
	case App::gameState::End:
		end_menu.Update();
		if (end_menu.GetRestartGame()) {
			end_menu.SetRestartGame(false);
			state = gameState::Ingame;
			RestartGame();
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