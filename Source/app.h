#pragma once
#include "game.h"
#include "start_menu.h"
#include "end_menu.h"


class App {	// TODO Make this, and all non-simple structs, into class (look up guidelines for why) C.2
private:
	Window window;
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
	// TODO Consider making inline. SE SF.2
	App() noexcept {
		game = std::make_unique<Game>();
	}

	void Run();
};