#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <ctime>
#include "AllTexture.hpp"
#include "BulletManager.hpp"

using namespace std;
using namespace sf;

class Game;
class EnnemyManager {
public:
	
	EnnemyManager() {};
	EnnemyManager(Game* _gaming);

	AllTexture textures;
	Game *gaming = nullptr;
	BulletManager bullet;

	class Ennemy {
	public:

		float hp;
		int points;
		Sprite mob;

	};

	vector<Ennemy> ennemies;
	vector<Ennemy> smallEnnemies;
	vector<Ennemy> bigEnnemies;

	//Time
	float spawnTimer = 0.f; 
	float spawnTimerSmall = 0.f;
	float spawnTimerBig = 0.f;

	float maxSpawnTimer = 1.5f;
	float maxSpawnTimerSmall = 3.f;
	float maxSpawnTimerBig = 6.f;

	//size max
	int maxSpawn = 10;  
	int maxSpawnSmall = 15;
	int maxSpawnBig = 5;

	//speed
	float speedNormal = 20.5f;
	float speedSmall = 30.5f;
	float speedBig = 12.5f;

	bool cantSpawn = false;
	bool cantSpawnSmall = false;
	bool cantSpawnBig = false;

	void SpawningEnnemies(float posX, float posY);
	void SpawningSmallEnnemies(float posX, float posY);
	void SpawningBigEnnemies(float posX, float posY);
	void UpdateEnnemies(Vector2f& posPlayer, float dt);
	void RenderEnnemies();
    float OtherSpawn(Vector2f newPos);

};

