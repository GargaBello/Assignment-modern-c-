#include "Resources.h"


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

ShipTexture::ShipTexture()
{
	shipTextures.push_back(LoadTexture("./Assets/Ship1.png"));
	shipTextures.push_back(LoadTexture("./Assets/Ship2.png"));
	shipTextures.push_back(LoadTexture("./Assets/Ship3.png"));

	int posInVec = 0;
	for (auto& texture : shipTextures) {
		++posInVec;
		if (texture.id == 0) {
			throw std::runtime_error("Failed to load texture: ShipTexture" + posInVec);
		}
	}
}

ShipTexture::~ShipTexture() {
	for (auto& textures : shipTextures) {
		UnloadTexture(textures);
	}

	shipTextures.clear();
}

BarrierTexture::BarrierTexture() :
	barrierTexture(LoadTexture("./Assets/Barrier.png"))
{
	if (barrierTexture.id == 0) {
		throw std::runtime_error("Failed to load texture: Barrier.png");
	}
}

BarrierTexture::~BarrierTexture() {
	UnloadTexture(barrierTexture);
}

AlienTexture::AlienTexture() :
	alienTexture(LoadTexture("./Assets/Alien.png"))
{
	if (alienTexture.id == 0) {
		throw std::runtime_error("Failed to load texture: Alien.png");
	}
}

AlienTexture::~AlienTexture() {
	UnloadTexture(alienTexture);
}

LaserTexture::LaserTexture() :
	laserTexture(LoadTexture("./Assets/Laser.png"))
{
	if (laserTexture.id == 0) {
		throw std::runtime_error("Failed to load texture: Laser.png");
	}
}

LaserTexture::~LaserTexture() {
	UnloadTexture(laserTexture);
}