#pragma once
#include "SFML/Graphics.hpp"
#include "AllTexture.hpp"
#include <vector>

using namespace sf;
using namespace std;

class Game;
class BulletManager {
public:

	BulletManager() {};
	BulletManager(Game* _games);
	
	Game* games = nullptr;
	AllTexture textures;

	float BulletSpeed = 4;
	vector<Sprite> bullets;

	

	bool IsDestroyed = false;
	void DestroyBullet(bool);
	
	void bulletRender();
	void spawningBullet(Vector2f& trajectoire);
	void updateBullets(float dt);

	class Bullet {
	public:

		Sprite snowBall;
		Vector2f traj;
		
	};

};

