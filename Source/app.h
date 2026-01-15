#pragma once
#include "game.h"
#include "start_menu.h"
#include "end_menu.h"


class App {
private:
	static constexpr int windowHeight = 1080, windowWidth = 1920;
	static constexpr std::string_view title = "Space Invaders";
	Window window =  Window(windowWidth, windowHeight, title);
	StartMenu start_menu;
	EndMenu end_menu;
	std::unique_ptr<Game> game;

	enum class gameState {
		Start,
		Ingame,
		End,
	};

	gameState state = gameState::Start;

	void RestartGame();

	void Update();
	void Render() const;

public:
	App();

	void Run();
};