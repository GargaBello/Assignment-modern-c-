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



class ShipTexture {
private:
	std::vector<Texture2D> shipTextures{};
public:

	ShipTexture();
	~ShipTexture();

	std::vector<Texture2D> GetTexture();

	ShipTexture(const ShipTexture&) = delete;
	ShipTexture& operator=(const ShipTexture&) = delete;

	ShipTexture(const ShipTexture&&) = delete;
	ShipTexture& operator=(const ShipTexture&&) = delete;
};

class AlienTexture {
private:
	Texture2D alienTexture{};

public:

	AlienTexture();
	~AlienTexture();

	Texture2D GetTexture();

	AlienTexture(const AlienTexture&) = delete;
	AlienTexture& operator=(const AlienTexture&) = delete;

	AlienTexture(const AlienTexture&&) = delete;
	AlienTexture& operator=(const AlienTexture&&) = delete;

};

class BarrierTexture {
private:
	Texture2D barrierTexture{};

public:

	BarrierTexture();
	~BarrierTexture();

	Texture2D GetTexture();

	BarrierTexture(const BarrierTexture&) = delete;
	BarrierTexture& operator=(const BarrierTexture&) = delete;

	BarrierTexture(const BarrierTexture&&) = delete;
	BarrierTexture& operator=(const BarrierTexture&&) = delete;

};

class LaserTexture {
private:
	Texture2D laserTexture{};

public:

	LaserTexture();
	~LaserTexture();

	Texture2D GetTexture();

	LaserTexture(const LaserTexture&) = delete;
	LaserTexture& operator=(const LaserTexture&) = delete;

	LaserTexture(const LaserTexture&&) = delete;
	LaserTexture& operator=(const LaserTexture&&) = delete;

};

class Window {
private:
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
	//void Load();
	//void Unload();

	ShipTexture shipTextures = ShipTexture();
	AlienTexture alienTexture = AlienTexture();
	BarrierTexture barrierTexture = BarrierTexture();
	LaserTexture laserTexture = LaserTexture();

	Resources() = default;

	/*std::vector<Texture2D> shipTextures;
	Texture2D alienTexture;
	Texture2D barrierTexture;
	Texture2D laserTexture;*/

};