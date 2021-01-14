#include "Ennemy.hpp"

using namespace std;
using namespace sf;

Ennemy::Ennemy(Game *_game)
{
	gaming = _game;
}

void Ennemy::SpawningEnnemies() {

	float posY = float(rand() % 720);
	float posX = float(rand() % 1280);

	mob.setPosition(posX, posY);
	mob.setTexture(textures.kdoMedium);
	ennemies.push_back(mob);
}

void Ennemy::SpawningSmallEnnemies() {

	float posY = float(rand() % 720);
	float posX = float(rand() % 1280);

	smallMob.setPosition(posX, posY);
	smallMob.setTexture(textures.kdoSmall);
	smallEnnemies.push_back(smallMob);
}

void Ennemy::SpawningBigEnnemies() {

	float posY = float(rand() % 720);
	float posX = float(rand() % 1280);

	bigMob.setPosition(posX, posY);
	bigMob.setTexture(textures.kdoBig);
	bigEnnemies.push_back(bigMob);
}

void Ennemy::RenderEnnemies() {

	for (auto& rendEnnemies : ennemies)
		gaming->win->draw(rendEnnemies);
	for (auto& rendEnnemiesSmall : smallEnnemies)
		gaming->win->draw(rendEnnemiesSmall);
	for (auto& rendEnnemiesBig : bigEnnemies)
		gaming->win->draw(rendEnnemiesBig);
}

void Ennemy::UpdateEnnemies(Vector2f &posPlayer) {

	//Pr eviter le pop sur player
	CircleShape notSpawnCircle;
	notSpawnCircle.setRadius(4.5f);
	notSpawnCircle.setPosition(posPlayer.x,posPlayer.y);
	notSpawnCircle.getPointCount();

	if (boundBoxMob.contains(notSpawnCircle.getPoint(notSpawnCircle.getPointCount())))
		cantSpawn = true;
	else
		cantSpawn = false;

	if (boundBoxSmallMob.contains(notSpawnCircle.getPoint(notSpawnCircle.getPointCount())))
		cantSpawnSmall = true;
	else
		cantSpawnSmall = false;

	if (boundBoxBigMob.contains(notSpawnCircle.getPoint(notSpawnCircle.getPointCount())))
		cantSpawnBig = true;
	else
		cantSpawnBig = false;

	//spawnNormal
	if (cantSpawn == false) {
		if (ennemies.size() < maxSpawn) {
			if (spawnTimer >= maxSpawnTimer) {
				SpawningEnnemies();
				spawnTimer = 0.f;
			}
			else
				spawnTimer += 1.0f;
		}
	}

	//spawnSmall
	if (cantSpawnSmall == false) {
		if (smallEnnemies.size() < maxSpawnSmall) {
			if (spawnTimerSmall >= maxSpawnTimerSmall) {
				SpawningSmallEnnemies();
				spawnTimerSmall = 0.f;
			}
			else
				spawnTimerSmall += 1.f;
		}
	}

	//spawnBig
	if (cantSpawnBig == false) {
		if (bigEnnemies.size() < maxSpawnBig) {
			if (spawnTimerBig >= maxSpawnTimerBig) {
				SpawningBigEnnemies();
				spawnTimerBig = 0.f;
			}
			else
				spawnTimerBig += 1.f;
		}
	}

	//ennemies moving to the player
	for (auto& moveEnnemies : ennemies)
		moveEnnemies.move(player.spr.getPosition() * speedNormal);
	for (auto& moveEnnemiesSmall : smallEnnemies)
		moveEnnemiesSmall.move(player.spr.getPosition() * speedSmall);
	for (auto& moveEnnemiesBig : bigEnnemies)
		moveEnnemiesBig.move(player.spr.getPosition() * speedBig);
}