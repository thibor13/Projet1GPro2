#pragma once
#include "SFML/Graphics.hpp"
#include "AllTexture.hpp"
#include <vector>
#include "Ennemy.hpp"


using namespace sf;
using namespace std;

class Game;
class BulletManager {
public:

	BulletManager() {};
	BulletManager(Game* _games);

	class Bullet {
	public:

		Sprite snowBall;
		Vector2f traj;
		bool isDestroyed = false;
	};
	
	Game* games = nullptr;
	AllTexture textures;
	Ennemy* ennemy = nullptr;

	float BulletSpeed = 4;
	vector<Bullet> bullets;

	void bulletRender();
	void spawningBullet(Vector2f& trajectoire);
	void updateBullets(float dt);

	

};

