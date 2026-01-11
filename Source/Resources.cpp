#include "Resources.h"


/* Todo: Initialize in constructor, check if multiple ship textures are used
* Check how the textures are unloaded and add to destructor
*/


/* TODO: Maybe make error handling a free function performed after construction or 
make constructor take a argument to not make it a default constructor
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
			throw std::runtime_error("Failed to load texture: ShipTexture" + std::to_string(posInVec));
		}
	}
}

ShipTexture::~ShipTexture() {
	for (auto& textures : shipTextures) {
		UnloadTexture(textures);
	}

	shipTextures.clear();
}

std::vector<Texture2D> ShipTexture::GetTexture()
{
	return shipTextures;
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

Texture2D BarrierTexture::GetTexture() {
	return barrierTexture;
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

Texture2D AlienTexture::GetTexture() {
	return alienTexture;
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

Texture2D LaserTexture::GetTexture() {
	return laserTexture;
}

Window::Window() noexcept
{
	InitWindow(windowWidth, windowHeight, title.data());
}

Window::~Window()
{
	CloseWindow();
}

AudioDevice::AudioDevice(auto sound)
{
	InitAudioDevice();
	this->sound = LoadSound(sound);

	if (!IsSoundReady(this->sound)) {
		throw std::runtime_error("Failed to load sound :" + std::to_string(sound));
	}

}

AudioDevice::~AudioDevice()
{
	CloseAudioDevice();
}

Drawer::Drawer()
{
	BeginDrawing();

	ClearBackground(BLACK);
}

Drawer::~Drawer()
{
	EndDrawing();
}
