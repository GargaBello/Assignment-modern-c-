#include "Resources.h"


/* Todo: Initialize in constructor, check if multiple ship textures are used
* Check how the textures are unloaded and add to destructor
*/


/* TODO: Maybe make error handling a free function performed after construction or 
make constructor take a argument to not make it a default constructor
*/


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

Texture2D TextureHandler::GetTexture() {
	return texture;
}

//TODO: A RAII type only ever handles ONE resource. 
//TODO: then you build containers / sets / aggregates / collections out of those RAII handles. 


Window::Window() noexcept
{
	SetConfigFlags(FLAG_FULLSCREEN_MODE);
	InitWindow(0, 0, title.data());
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

	SetTargetFPS(60);
}

Drawer::~Drawer()
{
	EndDrawing();
}
