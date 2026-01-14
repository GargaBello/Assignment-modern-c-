#pragma once
#include "raylib.h"
#include <vector>
#include <algorithm>
#include <ranges>

struct Alien
{
private:
	Vector2 position{};
	static constexpr float radius = 100.0f;								
	bool active = true;
	int speed = 2;
	static constexpr int player_spawn_offset = 200;

	Rectangle rect = {};
public:

	explicit Alien(Vector2 pos) noexcept
		: position(pos)
		, rect{ pos.x, pos.y, radius, radius }
	{
	}

	void SetActive(bool condition) noexcept {
		active = condition;
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

	Rectangle& GetCollisionBox() noexcept{
		return rect;
	}

	void Update() noexcept {
		position.x += speed;

		if (position.x >= GetScreenWidth() || position.x <= 0) // Combine with else{} below
		{
			speed *= -1;					// TODO This
			position.y += 50;
			rect.y = position.y;
		}
		rect.x = position.x;
	}

	void Render(Texture2D texture) const noexcept{
		DrawTextureV(texture, position, WHITE);
		DrawRectangleLinesEx(rect, 5, DARKPURPLE);
	}
};

struct Aliens {
private:
	std::vector<Alien> aliens{};

	static constexpr int formationWidth = 8;
	static constexpr int formationHeight = 5;
	static constexpr float alienSpacing = 80;
	static constexpr float formationX = 100;
	static constexpr float formationY = 50;
public:

	std::vector<Alien>& GetVector() noexcept {
		return aliens;
	}

	const std::vector<Alien>& GetVector() const  noexcept {
		return aliens;
	}

	void RemoveInactive() noexcept {
		std::erase_if(aliens, [](const Alien& alien) noexcept {return !alien.GetActive(); });
	}


	Aliens() noexcept { // TODO: use other algo than iota
		for (const int& row : std::views::iota(0, formationHeight)) {
			for (const int& col : std::views::iota(0, formationHeight)) {
				aliens.emplace_back(Vector2{ formationX + 450 + (col * alienSpacing), formationY + (row * alienSpacing) });
			}
		}
	}

	void Update() noexcept {
		if (aliens.size() < 1) {
			for (const int& row : std::views::iota(0, formationHeight)) {
				for (const int& col : std::views::iota(0, formationHeight)) {
					aliens.emplace_back(Vector2{ formationX + 450 + (col * alienSpacing), formationY + (row * alienSpacing) });
				}
			}
		}
	}
};