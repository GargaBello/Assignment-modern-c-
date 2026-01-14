#include "end_menu.h"

bool EndMenu::isValidCharacter(int key) noexcept
{
	if ((key > 31) && (key < 125)) {
		return true;
	}
	return false;
}

void EndMenu::Update() noexcept {

	if (IsKeyReleased(KEY_ENTER) && !Leaderboard.newHighScore)
	{
		restartGame = true;
	}

	if (Leaderboard.newHighScore)
	{
		if (CheckCollisionPointRec(GetMousePosition(), box.textBox)) box.mouseOnText = true;
		else box.mouseOnText = false;

		if (box.mouseOnText)
		{ 
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			int key = GetCharPressed();

			if (isValidCharacter(key))
			{
				box.name.push_back(gsl::narrow_cast<char>(key));
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				box.name.pop_back();
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

		if (box.mouseOnText)
		{
			box.framesCounter++;
		}
		else
		{
			box.framesCounter = 0;
		}

		if (IsKeyReleased(KEY_ENTER))
		{
			Leaderboard.InsertNewHighScore(box.name, playerScore.score);
			Leaderboard.newHighScore = false;
		}
	}
}

void EndMenu::Render() const noexcept {
	if (Leaderboard.newHighScore)
	{
		DrawText("NEW HIGHSCORE!", 600, 300, 60, YELLOW);

		DrawText("PLACE MOUSE OVER INPUT BOX!", 600, 400, 20, YELLOW);

		DrawRectangleRec(box.textBox, LIGHTGRAY);
		if (box.mouseOnText)
		{
			DrawRectangleLinesEx(box.textBox, 2, RED);
			if (((box.framesCounter / 20) % 2) == 0)
			{
				DrawText("_", gsl::narrow_cast<int>(box.textBox.x + 8 + MeasureText(box.name.data(), 40)), gsl::narrow_cast<int>(box.textBox.y + 12), 40, MAROON);
			}
		}
		else
		{
			DrawRectangleLinesEx(box.textBox, 3, DARKGRAY);
		}

		DrawText(box.name.data(), gsl::narrow_cast<int>(box.textBox.x + 5), gsl::narrow_cast<int>(box.textBox.y + 8), 40, MAROON);

		if (!box.name.size() == 0)
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