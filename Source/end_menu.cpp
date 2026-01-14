#include "end_menu.h"
#include "raylib.h"
#include "gsl/algorithm"
#include "playerScore.h"
#include <string>

bool& EndMenu::GetRestartGame() noexcept
{
	return restartGame;
}

void EndMenu::SetRestartGame(bool condition) noexcept
{
	restartGame = condition;
}

void EndMenu::ResetLeaderBoard(LeaderBoard board) noexcept
{
	Leaderboard = board;
}

bool EndMenu::isValidCharacter(int key) noexcept
{
	static constexpr int lower_bound_of_keyboard_keys = 31, upper_bound_of_keyboard_keys = 125;
	if ((key > lower_bound_of_keyboard_keys) && (key < upper_bound_of_keyboard_keys)) {
		return true;
	}
	return false;
}

void EndMenu::Update() {

	if (IsKeyReleased(KEY_ENTER) && !Leaderboard.GetNewHighScore())
	{
		restartGame = true;
	}

	if (Leaderboard.GetNewHighScore())
	{
		if (CheckCollisionPointRec(GetMousePosition(), box.GetRect())) box.SetMouseOnText(true);
		else box.SetMouseOnText(false);

		if (box.GetMouseOnText())
		{ 
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			int key = GetCharPressed();

			if (isValidCharacter(key))
			{
				box.GetName().push_back(gsl::narrow_cast<char>(key));
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				box.GetName().pop_back();
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

		if (IsKeyReleased(KEY_ENTER))
		{
			Leaderboard.InsertNewHighScore(box.GetName().data(), playerScore.GetScore());
			Leaderboard.SetNewHighScore(false);
		}
	}
}

void EndMenu::Render() const noexcept {
	if (Leaderboard.GetNewHighScore())
	{
		static constexpr int X_pos = 600, Y_pos = 300, Thickness = 60;
		DrawText("NEW HIGHSCORE!", X_pos, Y_pos, Thickness, YELLOW);
		static constexpr int Y_pos2 = 400, Thickness2 = 20;
		DrawText("PLACE MOUSE OVER INPUT BOX!", X_pos, Y_pos2, Thickness2, YELLOW);

		DrawRectangleRec(box.GetRect(), LIGHTGRAY);
		if (box.GetMouseOnText())
		{
			static constexpr int Thickness3 = 2;
			DrawRectangleLinesEx(box.GetRect(), Thickness, RED);
			static constexpr int X_pos_offset = 8, Thickness4 = 40, Y_pos_offset = 12;
			DrawText("_", 
				gsl::narrow_cast<int>(box.GetRect().x + X_pos_offset + MeasureText(box.GetName().data(), Thickness2)), 
				gsl::narrow_cast<int>(box.GetRect().y + Y_pos_offset), 
				Thickness2, 
				MAROON);
		}
		else
		{
			static constexpr int Thickness3 = 2;
			DrawRectangleLinesEx(box.GetRect(), Thickness3, DARKGRAY);
		}

		static constexpr int X_pos_offset = 5, Y_pos_offset = 8;
		DrawText(box.GetName().data(), gsl::narrow_cast<int>(box.GetRect().x + X_pos_offset), gsl::narrow_cast<int>(box.GetRect().y + Y_pos_offset), Thickness, MAROON);

		if (!box.GetName().size() == 0)
		{
			static constexpr int Y_pos3 = 800, Thickness4 = 40;
			DrawText("PRESS ENTER TO CONTINUE", X_pos, Y_pos3, Thickness4, YELLOW);
		}
	}
	else {
		static constexpr int X_pos = 600, Y_pos = 200, Thickness = 40;
		DrawText("PRESS ENTER TO CONTINUE", X_pos, Y_pos, Thickness, YELLOW);
		static constexpr int X_pos2 = 50, Y_pos2 = 100;
		DrawText("LEADERBOARD", X_pos2, Y_pos2, Thickness, YELLOW);

		int nameOffset = 0;
		for (auto& name : Leaderboard.GetLeaderboard())
		{
			++nameOffset;
			static constexpr int Y_pos3 = 140, Y_pos_multiplier = 40;
			DrawText(name.GetName().data(), X_pos2, Y_pos + (nameOffset * Y_pos_multiplier), Thickness, YELLOW);
			static constexpr int X_pos3 = 350;
			DrawText(TextFormat("%i", name.GetScore()), X_pos2, Y_pos3 + (nameOffset * Y_pos_multiplier), Thickness, YELLOW);
		}
	}
}