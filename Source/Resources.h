#pragma once
#include "raylib.h"
#include <string_view>

class TextureHandler {
private:
	Texture2D texture{};

public:

	TextureHandler(std::string_view path);
	~TextureHandler();

	Texture2D GetTexture() const noexcept;

	TextureHandler(const TextureHandler&) = delete;
	TextureHandler& operator=(const TextureHandler&) = delete;

	TextureHandler(const TextureHandler&&) = delete;
	TextureHandler& operator=(const TextureHandler&&) = delete;

};

class Window {
private:
	// Todo: Make arguments to pass in
	static constexpr int windowHeight = 1080;			
	static constexpr int windowWidth = 1920;			
	static constexpr std::string_view title = "Space invaders";		
public:

	Window();
	~Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	Window(const Window&&) = delete;
	Window& operator=(const Window&&) = delete;
};

class Drawer {
private:

public:

	Drawer();

	~Drawer();

	Drawer(const Drawer&) = delete;
	Drawer& operator=(const Drawer&) = delete;

	Drawer(const Drawer&&) = delete;
	Drawer& operator=(const Drawer&&) = delete;
};

class Resources
{
private:
	TextureHandler shipTexture;
	TextureHandler alienTexture;
	TextureHandler barrierTexture;
	TextureHandler laserTexture;

public:

	Resources();

	Texture2D GetShipTexture() const noexcept;
	Texture2D GetAlienTexture() const noexcept;
	Texture2D GetBarrierTexture() const noexcept;
	Texture2D GetLaserTexture() const noexcept;
};