#pragma once
#include "SFML/Graphics.hpp"
#include "AllTexture.hpp"
#include <vector>

using namespace sf;
using namespace std;

class Bullet {
public:

	Sprite snowBall;
	vector<Sprite> bullets;

	float BulletSpeed;

	bool IsDestroyed();
	void Destroy(bool);
	
	void Calculate(RenderWindow& app);

};