#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <ctime>
#include "Game.hpp"
#include "Char.hpp"
#include "AllTexture.hpp"

using namespace std;
using namespace sf;

class Ennemy {
public:
	
	Ennemy() {};
	Ennemy(Game* _game) {};

	AllTexture textures;
	Char player;
	Game *gaming = nullptr;

	Sprite mob;
	Sprite smallMob;
	Sprite bigMob;

	vector<Sprite> ennemies;
	vector<Sprite> smallEnnemies;
	vector<Sprite> bigEnnemies;

	//Time
	float spawnTimer = 0.f; 
	float spawnTimerSmall = 0.f;
	float spawnTimerBig = 0.f;

	float maxSpawnTimer = 1.5f;
	float maxSpawnTimerSmall = 3.f;
	float maxSpawnTimerBig = 6.f;

	//size max
	int maxSpawn = 10;  
	int maxSpawnSmall = 12;
	int maxSpawnBig = 5;

	//give points
	int points = 10; 
	int smallPoints = 20;
	int bigPoints = 40;

	//life
	float hp = 100.f; 
	float hpSmall = 60.f;
	float hpBig = 500.f;

	//speed
	float speedNormal = 4.f;
	float speedSmall = 10.f;
	float speedBig = 2.f;

	bool cantSpawn = false;
	bool cantSpawnSmall = false;
	bool cantSpawnBig = false;

	FloatRect boundBoxMob = mob.getGlobalBounds(); //get collider
	FloatRect boundBoxSmallMob = smallMob.getGlobalBounds();
	FloatRect boundBoxBigMob = bigMob.getGlobalBounds();

	void SpawningEnnemies();
	void SpawningSmallEnnemies();
	void SpawningBigEnnemies();
	void UpdateEnnemies(Vector2f& posPlayer);
	void RenderEnnemies();

};