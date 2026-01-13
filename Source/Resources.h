#pragma once
#include "raylib.h"
#include <vector>
#include <string_view>
#include <string>
#include <iostream>
#include <exception>
#include <ranges>

/* TODO: Check if used, make loading part of construction
* make destructor, check if rule of five is needed, 
add error checks to see if everything loaded properly
Maybe split textures into individual classes for easier managment
Add the textures and files into the resource files in the project, as in the thing between source files and header files
*/

//TODO: we only need a single Texture type, if you pass the path to load into the constructor.
class TextureHandler {
private:
	Texture2D texture{};

public:

	TextureHandler(std::string_view path);
	~TextureHandler();

	Texture2D GetTexture();

	TextureHandler(const TextureHandler&) = delete;
	TextureHandler& operator=(const TextureHandler&) = delete;

	TextureHandler(const TextureHandler&&) = delete;
	TextureHandler& operator=(const TextureHandler&&) = delete;

};

class Window {
private:
	// Todo: Make arguments to pass in
	const int windowHeight = 1080;
	const int windowWidth = 1920;
	std::string_view title = "Space invaders";
public:

	Window() noexcept;
	~Window();

	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	Window(const Window&&) = delete;
	Window& operator=(const Window&&) = delete;
};

class AudioDevice {
private:
	Sound sound{};
public:

	AudioDevice(auto sound);

	~AudioDevice();

	AudioDevice(const AudioDevice&) = delete;
	AudioDevice& operator=(const AudioDevice&) = delete;

	AudioDevice(const AudioDevice&&) = delete;
	AudioDevice& operator=(const AudioDevice&&) = delete;
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

struct Resources
{

	//TODO: move into each of the entities
	TextureHandler shipTexture;
	TextureHandler alienTexture;
	TextureHandler barrierTexture;
	TextureHandler laserTexture;

	Resources() 
		: alienTexture("./Assets/Alien.png")
		, barrierTexture("./Assets/Barrier.png")
		, laserTexture("./Assets/Laser.png")
		, shipTexture("./Assets/Ship2.png")
	{
	}
};