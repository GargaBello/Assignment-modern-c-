#include "Resources.h"
#include <iostream>;

/* Todo: Initialize in constructor, check if multiple ship textures are used
* Check how the textures are unloaded and add to destructor
*/
void Resources::Load()
{
	std::cout << "Yay"; // yes
	alienTexture = LoadTexture("./Assets/Alien.png");
	barrierTexture = LoadTexture("./Assets/Barrier.png");
	shipTextures.push_back(LoadTexture("./Assets/Ship1.png"));
	shipTextures.push_back(LoadTexture("./Assets/Ship2.png"));
	shipTextures.push_back(LoadTexture("./Assets/Ship3.png"));
	laserTexture = LoadTexture("./Assets/Laser.png");
}
/*
void Resources::Unload()
{
	UnloadTexture(barrierTexture);
	UnloadTexture(alienTexture);
}
*/