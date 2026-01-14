#pragma once
#include "raylib.h"
#include <string>
#include <vector>

class Wall
{
private:
	Vector2 position{};
	bool active = true;
	int health = 50;
	static constexpr float width = 100.0f;
	static constexpr int textOffsetX = 70;
	static constexpr int textOffsetY = 100;

	Rectangle rect = { position.x, position.y, width * 2, width };

public:
	void ReduceHealth() noexcept {
		static constexpr int damage = 1;
		health -= damage;
	}

	bool& GetActive() noexcept {
		return active;
	}

	const bool& GetActive() const noexcept {
		return active;
	}

	Vector2& GetPosition() noexcept {
		return position;
	}

	Rectangle& GetCollisionBox() noexcept {
		return rect;
	}

	void Render(Texture2D texture) const noexcept {
		DrawTextureV(texture, position, WHITE);
		static constexpr int Thickness = 50;
		DrawText(std::to_string(health).data(), gsl::narrow_cast<int>(position.x + textOffsetX), gsl::narrow_cast<int>(position.y + textOffsetY), Thickness, WHITE);
	}

	void Update() noexcept {
		if (health < 1)
		{
			active = false;
		}

		rect.x = position.x;
		rect.y = position.y + textOffsetY;
	}

	Wall(Vector2 position) noexcept
		: position(position)
	{
	}
};


class Walls
{
private:
	static constexpr int wallCount = 5; 
	static constexpr int wall_y_offset = 400;
	std::vector<Wall> walls_vec{};

public:

	std::vector<Wall>& GetVector() noexcept {
		return walls_vec;
	}

	const std::vector<Wall>& GetVector() const  noexcept {
		return walls_vec;
	}

	void RemoveInactive() noexcept {
		std::erase_if(walls_vec, [](const Wall& wall) noexcept {return !wall.GetActive(); });
	}

	Walls() noexcept {
		 const float window_width = gsl::narrow_cast<float>(GetScreenWidth());
		 const float window_height = gsl::narrow_cast<float>(GetScreenHeight());
		 const float wall_distance = window_width / wallCount;
		 
		 for (const int i : std::views::iota(0, wallCount)) {
			 walls_vec.emplace_back(Vector2{ wall_distance * i, window_height - wall_y_offset });
		 }
	}
};