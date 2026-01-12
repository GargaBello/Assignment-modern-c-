#include "end_menu.h"
#include <string>

/* TODO: make work
*/

void EndMenu::Update() {
	if (IsKeyReleased(KEY_ENTER) && !Leaderboard.newHighScore)
	{
		restartGame = true;
	}



	if (Leaderboard.newHighScore)
	{
		if (CheckCollisionPointRec(GetMousePosition(), box.textBox)) box.mouseOnText = true;
		else box.mouseOnText = false;

		if (box.mouseOnText) //TODO: invert the tests and reduce nesting.
		{ 
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key > 31) && (key <= 125) && (box.letterCount < 9)) //TODO: simplify tests, make them say what they're asking. "isValidCharacter()"
				{
					box.name.push_back( (char)key);
				//	box.name[box.letterCount + 1] = '\0'; // Add null terminator at the end of the string.
					box.letterCount++; //TODO: string knows it own length. stop couting. 
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			//Remove chars 
			if (IsKeyPressed(KEY_BACKSPACE))
			{
				//TODO: you have the string. just pop_back()
				box.letterCount--;
				if (box.letterCount < 0) box.letterCount = 0;
				box.name[box.letterCount] = '\0';
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

		// If the name is right legth and enter is pressed, exit screen by setting highscore to false and add 
		// name + score to scoreboard
		if (box.letterCount > 0 && box.letterCount < 9 && IsKeyReleased(KEY_ENTER))
		{
			std::string nameEntry(box.name);

			Leaderboard.InsertNewHighScore(nameEntry, 0); //TODO: Fill in real score later

			Leaderboard.newHighScore = false;
		}


	}
}

void EndMenu::Render() noexcept {
	if (Leaderboard.newHighScore)
	{
		DrawText("NEW HIGHSCORE!", 600, 300, 60, YELLOW);

		// BELOW CODE IS FOR NAME INPUT RENDER
		DrawText("PLACE MOUSE OVER INPUT BOX!", 600, 400, 20, YELLOW);

		DrawRectangleRec(box.textBox, LIGHTGRAY);
		if (box.mouseOnText)
		{
			// HOVER CONFIRMIATION
			DrawRectangleLines((int)box.textBox.x, (int)box.textBox.y, (int)box.textBox.width, (int)box.textBox.height, RED);
		}
		else
		{
			DrawRectangleLines((int)box.textBox.x, (int)box.textBox.y, (int)box.textBox.width, (int)box.textBox.height, DARKGRAY);
		}

		//Draw the name being typed out
		DrawText(box.name.data(), (int)box.textBox.x + 5, (int)box.textBox.y + 8, 40, MAROON);

		//Draw the text explaining how many characters are used
		DrawText(TextFormat("INPUT CHARS: %i/%i", box.letterCount, 8), 600, 600, 20, YELLOW);

		if (box.mouseOnText)
		{
			if (box.letterCount < 9)
			{
				// Draw blinking underscore char
				if (((box.framesCounter / 20) % 2) == 0)
				{
					DrawText("_", (int)box.textBox.x + 8 + MeasureText(box.name.data(), 40), (int)box.textBox.y + 12, 40, MAROON);
				}

			}
			else
			{
				//Name needs to be shorter
				DrawText("Press BACKSPACE to delete chars...", 600, 650, 20, YELLOW);
			}

		}

		// Explain how to continue when name is input
		if (box.letterCount > 0 && box.letterCount < 9)
		{
			DrawText("PRESS ENTER TO CONTINUE", 600, 800, 40, YELLOW);
		}

	}
	else {
		// If no highscore or name is entered, show scoreboard and call it a day
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