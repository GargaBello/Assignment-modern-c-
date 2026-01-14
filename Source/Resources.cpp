#include "Resources.h"

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

//TODO: A RAII type only ever handles ONE resource. 
//TODO: then you build containers / sets / aggregates / collections out of those RAII handles. 


Window::Window() noexcept
{
	SetConfigFlags(FLAG_BORDERLESS_WINDOWED_MODE);
	InitWindow(0, 0, title.data());
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
