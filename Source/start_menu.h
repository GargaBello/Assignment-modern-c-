#pragma once

class StartMenu {
private:
	bool start_game = false;

public:

	bool& GetStartGame() noexcept;
	void SetStarGame(bool condition) noexcept;

	void Render() const noexcept;

	void Update() noexcept;
};