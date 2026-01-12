#pragma once
#include "raylib.h"
#include <vector>
#include "Resources.h"
#include <string>
#include <ranges>
#include <algorithm>
#include <print>


enum struct State
{
	STARTSCREEN,
	GAMEPLAY,
	ENDSCREEN
};

enum struct EntityType //TODO: you are creating another type system. C++ is already strongly typed. encoding types by hand is always a smell. 
{
	PLAYER,
	ENEMY,
	PLAYER_PROJECTILE,
	ENEMY_PROJECTILE
};


//struct PlayerData
//{
//	std::string name{};
//	int score = 0;
//};

/*TODO: Make the player variables initialisation as part of construction
* Maybe add default values as private parts of struct or class
*/

//TODO: move types into their own files. physical structure. 
struct Player
{
	float x_pos				 = 0;
	float speed				 = 0; //TODO: velocity already has direction, so either this or int direction needs to go. 
	float player_base_height = 0;
	float radius			 = 0;
	float timer				 = 0;
	int lives				 = 0;
	int direction			 = 0;
	int activeTexture		 = 0;


	EntityType type = EntityType::PLAYER; //TODO: remove. 

	Player() noexcept;

	void Render(Texture2D texture); //TODO: render should always be const
	void Update(); //TODO: surely this can be noexcept? 
	
};

/* TODO: Make initialisation part of construction
*/
struct Projectile
{
	// INITIALIZE PROJECTILE WHILE DEFINING IF ITS PLAYER OR ENEMY 
	Vector2 position{};
	int speed = 0; // 15 if player //TODO: this comments begs to become a function. Projectile::isPlayerProjectile() { return speed < 0;} 
	bool active = true;  
	EntityType type = {};

	// LINE WILL UPDATE WITH POSITION FOR CALCULATIONS
	Vector2 lineStart{}; //TODO: these are clearly mad. you already have position. The projectile is a simple rectangle. just use rect/rect intersection tests
	Vector2 lineEnd{}; //TODO: refactor the projectile to remove this.

	Projectile(Vector2 pos, EntityType type, int speed);

	void Update(); //noexcept

	void Render(Texture2D texture); //const noexcept
};

/* TODO: Make constructor and initialize variables there
*/

struct Wall 
{
	Vector2 position{};
	bool active = false; 
	int health = 0; 
	int radius = 0; 
	
	Wall(float x, float y) noexcept;

	void Render(Texture2D texture); 
	void Update(); 
};


struct Walls
{
	int wallCount = 0; //TODO: const members are always a problem. They break value semantics, same as a reference-member. 
	float wall_y_offset = 0; //TODO: you meant to write static const or static constexpr. 
	std::vector<Wall> walls_vec{};

	Walls(int wallCount) noexcept;
};
/* TODO: Make constructor
*/

struct Alien
{	
	Color color = WHITE;  //are all of them white? don't store it. 
	Vector2 position{};
	int x = 0; 
	int y = 0; 
	float radius = 0; // 30 //TODO??! just set it to 30 then. :p 
	bool active = true;  
	bool moveRight = true; //TODO: reduindant. speed already encodes the direction! 
	
	EntityType type = EntityType::ENEMY; 

	int speed = 0; //2

	Alien(Vector2 pos);
		 
	void Update(); 
	void Render(Texture2D texture); 
};

/* TODO: Make constructor
*/

struct Star
{
	Vector2 initPosition = { 0, 0 };
	Vector2 position = { 0, 0 }; 
	Color color = SKYBLUE; //TODO: are all stars sky blue? don't store it. 
	float size = 0;

	Star(Vector2 pos, float size);

	void Update(float starOffset);
	void Render();
};

/* TODO: Make constructor
*  Initialize in constructorm, not in separate function or 
	make initialize part of construction depending on how it looks
*/

struct Background
{
	std::vector<Star> Stars{};

	Background(int starAmount);

	void Update(float offset); //TODO: shoul dbe noexcept
	void Render(); //todo: should be const and noexcept

};

/* TODO: Make constructor
* Make resources a class thats raii approved
* Maybe make leaderboard into a struct or class
* Maybe make textbox into struct or class aswell and change char into string or string_view
* Maybe look into making some of the functions free functions
*/

struct Game
{
	// Gamestate
	State gameState = {};

	// Score
	int score = 0;

	// for later, make a file where you can adjust the number of walls (config file) 
	int wallCount = 0; // 5

	//Aliens shooting
	float shootTimer = 0;

	//Aliens stuff? (idk cause liv wrote this)
	Rectangle rec = { 0, 0 ,0 ,0 }; 

	int formationWidth = 0; // 8
	int formationHeight = 0; // 5
	int alienSpacing = 0; //80
	int formationX = 0; //100
	int formationY = 0; //50

	bool newHighScore = false;
	
	//TODO: define the public interface (eg: run()) and then make everything else private)
	Game();

	void Start();
	void End();

	void Continue();
	void Launch();

	void Update();
	void Render();

	void SpawnAliens();

	//TODO: raylib has a rectangle interfection test. use it. Replace all custom collision logic with the library function, and make all entities adhere to the simple
	// Rectangle getCollisionBox() const noexcept interface. 
	bool CheckCollision(Vector2 circlePos, float circleRadius, Vector2 lineTop, Vector2 lineBottom);

	/*bool CheckNewHighScore();

	void InsertNewHighScore(std::string name);

	void LoadLeaderboard();
	void SaveLeaderboard();*/


	// Entity Storage and Resources
	Resources resources; //consider using RAII and just giving each type their own Resource handle. No reason to store those assets here in game. 

	Player player = Player();

	std::vector<Projectile> Projectiles{}; //TODO: consider separating player projects and alien projectile. Use two lists. 

	Walls walls = Walls(wallCount);

	std::vector<Alien> Aliens{};

	//std::vector<PlayerData> Leaderboard = { {"Player 1", 500}, {"Player 2", 400}, {"Player 3", 300}, {"Player 4", 200}, {"Player 5", 100} };
	
	Background background = Background(600);



	Vector2 playerPos{}; //TODO: what are these for? why are they in game? 
	Vector2 alienPos{};
	Vector2 cornerPos{};
	float offset = 0; //



	////TEXTBOX ENTER
	//char name[9 + 1] = "\0";      //One extra space required for null terminator char '\0'
	//int letterCount = 0;

	//Rectangle textBox = { 600, 500, 225, 50 };
	//bool mouseOnText = false;

	int framesCounter = 0; //??? what is this for?

};