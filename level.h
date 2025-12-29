#pragma once 
#include <iostream>
#include <string>
#include <fstream>

/* TODO: Check if any of this is used, if not delete or make usable
* If making usable add resources like file into a raii class
*/

struct Entity
{
	float x, y;

	void LoadLevelFromAFile(const std::string& filename);
};