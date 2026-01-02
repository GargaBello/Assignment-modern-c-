#pragma once
#include "raylib.h"
#include <vector>
#include <string_view>
#include <iostream>
#include <exception>
#include <ranges>

/* TODO: Check if used, make loading part of construction
* make destructor, check if rule of five is needed, 
add error checks to see if everything loaded properly
Maybe split textures into individual classes for easier managment
Add the textures and files into the resource files in the project, as in the thing between source files and header files
*/

struct Resources 
{
	void Load();
	//void Unload();

	std::vector<Texture2D> shipTextures;
	Texture2D alienTexture;
	Texture2D barrierTexture;
	Texture2D laserTexture;

};

class ShipTexture {
private:
	std::vector<Texture2D> shipTextures{};
public:

	ShipTexture();
	~ShipTexture();

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

	LaserTexture(const LaserTexture&) = delete;
	LaserTexture& operator=(const LaserTexture&) = delete;

	LaserTexture(const LaserTexture&&) = delete;
	LaserTexture& operator=(const LaserTexture&&) = delete;

};