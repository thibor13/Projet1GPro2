#include "Char.hpp"
#include "Game.hpp"
#include "AllTexture.hpp"

void Char::setCellPosition(int cx, int cy) {
	rx = 0.5;
	ry = 0.99;
	this->cx = cx;
	this->cy = cy;
	setState(Running);
}

void Char::setPosition(int rpx, int rpy) {
	cx = rpx / GRID_SIZE;
	rx = rpx - (cx * GRID_SIZE);

	cy = rpy / GRID_SIZE;
	ry = rpy - (cy * GRID_SIZE);
}

void Char::onWallCollision() {
	if (state == WalkTo) stop();
}

void Char::update(double dt) {

	rx += speedX * dt;
	ry += speedY * dt;

	spriteUpdate(dt);

	while (rx > 1) {
		if (isWallHit(cx + 1, cy)) {
			rx = 0.95;
			onWallCollision();
		}
		else {
			rx--;
			cx++;
		}
	}

	while (rx < 0) {
		if (isWallHit(cx - 1, cy)) {
			rx = 0.05;
			onWallCollision();
		}
		else {
			rx++;
			cx--;
		}
	}

	while (ry > 1) {
		if (isWallHit(cx, cy + 1)) {
			ry = 0.95;
			onWallCollision();
		}
		else {
			ry--;
			cy++;
		}
	}

	while (ry < 0) {
		if (isWallHit(cx, cy - 1)) {
			ry = 0.05;
			onWallCollision();
		}
		else {
			ry++;
			cy--;
		}
	}

	switch (state)
	{
	case WalkTo:
	
		if ((((int)destX) == cx) && (((int)destY) == cy)) {
			speedX = 0.0;
			speedY = 0.0;
			setState(Idle);
		}
	
	break;
	case Idle:
		if (
			isWallHit(cx, cy - 1)
			|| isWallHit(cx, cy + 1)
			|| isWallHit(cx - 1, cy)
			|| isWallHit(cx + 1, cy)
			) {
			setState(Cover);
		}
		break;
	case Cover:
		break;
	case Walking:
		if ((abs(speedX) < 0.01) && (abs(speedY) < 0.01)) {
			speedX = 0.0;
			speedY = 0.0;
			setState(Idle);
			maxFrame = 15;
			currentFrame = 0;
		}
		break;
	case Running:
		if ((abs(speedX) < 0.01) && (abs(speedY) < 0.01)) {
			speedX = 0.0;
			speedY = 0.0;
			setState(Idle);
			maxFrame = 15;
			currentFrame = 0;
		}
		break;
	default:
		break;
	}

	speedX *= frictX;
	speedY *= frictY;

	spr.setPosition(getPositionPixel());
}

void Char::spriteUpdate(float dt) {
	duration += dt;

	if (duration > 0.04f) {
		duration = 0;
		currentFrame = (currentFrame + 1)% maxFrame;

		switch (state)
		{
		case Idle:
			spr.setTexture(texturing.arrayIdle[currentFrame]);
			break;
		case Walking:
			spr.setTexture(texturing.arrayWalk[currentFrame]);
			break;
		case Running:
			spr.setTexture(texturing.arrayRun[currentFrame]);
			break;
		case Cover:
			spr.setTexture(texturing.arrayIdle[currentFrame]);
			break;
		case WalkTo:
			spr.setTexture(texturing.arrayWalk[currentFrame]);
			break;
		case Dead:
			spr.setTexture(texturing.arrayDead[currentFrame]);
			break;
		default:
			break;
		}
	}
}

void Char::stop() {
	speedX = 0.0;
	speedY = 0.0;
	setState(Idle);
	maxFrame = 15;
	currentFrame = 0;
}

void Char::defaultFriction() {
	frictX = 0.87;
	frictY = 0.87;
}

void Char::setState(State st) {
	state = st;

	destX = 0;
	destY = 0;

	defaultFriction();

	switch (state)
	{
	case WalkTo:
		frictX = 1.0;
		frictY = 1.0;
		break;
	case Idle:
		break;
	case Cover:
		break;
	case Walking:
		break;
	case Running:
		break;
	case Dead:
		break;
	default:
		break;
	}
}

bool Char::isWallHit(int cx, int cy)
{
	return game->isWall(cx, cy);
}
