#pragma once

#include "SFML/Graphics.hpp"
#include <functional>
#include "AllTexture.hpp"

using namespace sf;
using namespace std;

class Game;

enum State {
	Idle,
	Walking,
	Running,
	Cover,
	WalkTo,
	Dead,
};

class Char;


class Char {
public:
	static constexpr int GRID_SIZE = 16;
	AllTexture texturing;
	sf::Sprite spr;
	float duration;
	int currentFrame;
	int lastFrame;
	int maxFrame;

	Clock cloks;
	Time dt;
	
	Game* game = nullptr;

	Char(Game* g = nullptr) {
		spr.setOrigin(8, 16 * 2.5);
		this->game = g;
		
	}

	float speedX = 0.0; //rx par secondes
	float speedY = 0.0; //rx par secondes

	State state = Idle;

	int		cx = 0;
	float	rx = 0.0;

	int		cy = 0;
	float	ry = 0.0;

	float frictX = 0.87;
	float frictY = 0.87;

	float destX = 0;
	float destY = 0;

	void setCellPosition(int cx, int cy);
	void setPosition(int rpx, int rpy);
	void spriteUpdate(float dt);


	Vector2f getPositionPixel() {
		return Vector2f(cx * GRID_SIZE + rx * GRID_SIZE, cy * GRID_SIZE + ry * GRID_SIZE);
	}

	void update(double dt);

	void stop();

	void draw(sf::RenderWindow& win) {
		win.draw(spr);
	}

	void defaultFriction();

	void setState(State st);
	bool isWallHit(int cx, int cy);
	void onWallCollision();


};

