#pragma once
#include "raylib.h"
#include <vector>
#include <random>
#include "Resources.h"

struct Alien
{
private:
	Vector2 position{};
	float radius = 100.0f;								// TODO Should be static constexpr
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

		if (position.x >= GetScreenWidth()) // Combine with else{} below
		{
			speed *= -1;					// TODO This
			position.y += 50;
			rect.y = position.y;
		}
		else if (position.x <= 0)
		{
			speed = 2;
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

	// TODO Make static constexpr
	int formationWidth = 8;
	int formationHeight = 5;
	float alienSpacing = 80;
	float formationX = 100;
	float formationY = 50;
public:

	std::vector<Alien>& GetVector() noexcept {
		return aliens;
	}

	const std::vector<Alien>& GetVector() const  noexcept {
		return aliens;
	}

	void RemoveInactive() noexcept {
		std::erase_if(aliens, [](const Alien& alien) {return !alien.GetActive(); });
	}

	template <typename T>	// TODO Move to cpp file unless another file actually needs it... and if so, make it a sepparate file (it's unrelated to Aliens)
	T& GetRandomElement(std::vector<T>& v, std::mt19937& rng) {
		if (v.empty()) throw std::runtime_error("Cannot get random element from empty vector");
		std::uniform_int_distribution<std::size_t> dist(0, v.size() - 1);
		return v[dist(rng)];
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