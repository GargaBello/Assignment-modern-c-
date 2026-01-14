#include "Resources.h"
#include <iostream>
#include <exception>

TextureHandler::TextureHandler(std::string_view path) :
	texture(LoadTexture(path.data()))
{
	if (texture.id == 0) {
		throw std::runtime_error(std::string("Failed to load texture: ") + std::string(path));
	}
}

TextureHandler::~TextureHandler() {
	UnloadTexture(texture);
}

Texture2D TextureHandler::GetTexture() const noexcept{
	return texture;
}

Window::Window(int height, int width, std::string_view title)
{
	InitWindow(height, width, title.data());
}

Window::~Window()
{
	CloseWindow();
}

Drawer::Drawer() 
{
	BeginDrawing();

	ClearBackground(BLACK);

	SetTargetFPS(60);
}

Drawer::~Drawer()
{
	EndDrawing();
}

Resources::Resources()
	: shipTexture("./Assets/Ship2.png")
	, alienTexture("./Assets/Alien.png")
	, barrierTexture("./Assets/Barrier.png")
	, laserTexture("./Assets/Laser.png")
{
}

Texture2D Resources::GetShipTexture() const noexcept
{
	return shipTexture.GetTexture();
}

Texture2D Resources::GetAlienTexture() const noexcept
{
	return alienTexture.GetTexture();
}

Texture2D Resources::GetBarrierTexture() const noexcept
{
	return barrierTexture.GetTexture();
}

Texture2D Resources::GetLaserTexture() const noexcept
{
	return laserTexture.GetTexture();
}
