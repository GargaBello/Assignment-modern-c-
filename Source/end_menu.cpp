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
	if ((key > 31) && (key < 125)) {
		return true;
	}
	return false;
}

void EndMenu::Update() noexcept {

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
		DrawText("NEW HIGHSCORE!", 600, 300, 60, YELLOW);

		DrawText("PLACE MOUSE OVER INPUT BOX!", 600, 400, 20, YELLOW);

		DrawRectangleRec(box.GetRect(), LIGHTGRAY);
		if (box.GetMouseOnText())
		{
			DrawRectangleLinesEx(box.GetRect(), 2, RED);
			DrawText("_", gsl::narrow_cast<int>(box.GetRect().x + 8 + MeasureText(box.GetName().data(), 40)), gsl::narrow_cast<int>(box.GetRect().y + 12), 40, MAROON);
		}
		else
		{
			DrawRectangleLinesEx(box.GetRect(), 3, DARKGRAY);
		}

		DrawText(box.GetName().data(), gsl::narrow_cast<int>(box.GetRect().x + 5), gsl::narrow_cast<int>(box.GetRect().y + 8), 40, MAROON);

		if (!box.GetName().size() == 0)
		{
			DrawText("PRESS ENTER TO CONTINUE", 600, 800, 40, YELLOW);
		}
	}
	else {
		DrawText("PRESS ENTER TO CONTINUE", 600, 200, 40, YELLOW);

		DrawText("LEADERBOARD", 50, 100, 40, YELLOW);

		int nameOffset = 0;
		for (auto& name : Leaderboard.GetLeaderboard())
		{
			++nameOffset;
			DrawText(name.name.data(), 50, 140 + (nameOffset * 40), 40, YELLOW);
			DrawText(TextFormat("%i", name.score), 350, 140 + (nameOffset * 40), 40, YELLOW);
		}
	}
}