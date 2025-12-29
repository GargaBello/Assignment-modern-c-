#pragma once
#include "raylib.h"
#include "vector"

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