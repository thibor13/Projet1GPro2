#include "EnnemyManager.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

EnnemyManager::EnnemyManager(Game *_gaming)
{
	gaming = _gaming;
}

void EnnemyManager::SpawningEnnemies(float posX, float posY) {

	Ennemy ennemy;

	ennemy.mob.setPosition(posX, posY);
	ennemy.mob.setScale(Vector2f(0.08f, 0.16f));
	ennemy.mob.setTexture(textures.kdoMedium);
	ennemies.push_back(ennemy);
}

void EnnemyManager::SpawningSmallEnnemies(float posY, float posX) {

	Ennemy smallEnnemy;

	smallEnnemy.mob.setPosition(posX, posY);
	smallEnnemy.mob.setScale(Vector2f(0.08f, 0.16f));
	smallEnnemy.mob.setTexture(textures.kdoSmall);
	smallEnnemies.push_back(smallEnnemy);
}

float EnnemyManager::OtherSpawn(Vector2f newPos) {

	return sqrt(newPos.x * newPos.x + newPos.y * newPos.y); 
}

void EnnemyManager::SpawningBigEnnemies(float posX, float posY) {

	Ennemy bigEnnemy;

	bigEnnemy.mob.setPosition(posX, posY);
	bigEnnemy.mob.setScale(Vector2f(0.08f, 0.16f));
	bigEnnemy.mob.setTexture(textures.kdoBig);
	bigEnnemies.push_back(bigEnnemy);
}

void EnnemyManager::RenderEnnemies() {

	for (auto& rendEnnemies : ennemies)
		gaming->win->draw(rendEnnemies.mob);
	for (auto& rendEnnemiesSmall : smallEnnemies)
		gaming->win->draw(rendEnnemiesSmall.mob);
	for (auto& rendEnnemiesBig : bigEnnemies)
		gaming->win->draw(rendEnnemiesBig.mob);
}

void EnnemyManager::UpdateEnnemies(Vector2f &posPlayer, float dt) {

	//Pr eviter le pop sur player
	CircleShape notSpawnCircle;
	notSpawnCircle.setRadius(100);
	notSpawnCircle.setOrigin(4.5f, 4.5f);
	notSpawnCircle.setPosition(posPlayer.x,posPlayer.y);

	Vector2f spawnPos(float(rand() % 1280), float(rand() % 720));
	Vector2f newPos(posPlayer - spawnPos);
	

	while (OtherSpawn(newPos) < 200) {
		spawnPos = Vector2f(float(rand() % 1280), float(rand() % 720));
		newPos = posPlayer - spawnPos;
	}

	//collision Ennemies
	for (int i = ennemies.size() - 1;i >= 0; i--) {
		
		if (gaming->mario.spr.getGlobalBounds().contains(ennemies[i].mob.getPosition())) {
			ennemies.erase(ennemies.begin()+i);
			gaming->mario.lifeSpr -= 10;
			continue;
		}
	}
	for (int i = smallEnnemies.size() - 1; i >= 0; i--) {

		if (gaming->mario.spr.getGlobalBounds().contains(smallEnnemies[i].mob.getPosition())) {
			smallEnnemies.erase(smallEnnemies.begin() + i);
			gaming->mario.lifeSpr -= 5;
			continue;
		}
	}
	for (int i = bigEnnemies.size() - 1; i >= 0; i--) {

		if (gaming->mario.spr.getGlobalBounds().contains(bigEnnemies[i].mob.getPosition())) {
			bigEnnemies.erase(bigEnnemies.begin() + i);
			gaming->mario.lifeSpr -= 20;
			continue;
		}
	}

	//spawnNormal
	if (cantSpawn == false) {
		if (ennemies.size() < maxSpawn) {
			if (spawnTimer >= maxSpawnTimer) {
				SpawningEnnemies(float(rand() % 1280), float(rand() % 720));
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
				SpawningSmallEnnemies(float(rand() % 1280), float(rand() % 720));
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
				SpawningBigEnnemies(float(rand() % 1280), float(rand() % 720));
				spawnTimerBig = 0.f;
			}
			else
				spawnTimerBig += 1.f;
		}
	}

	//ennemies moving to the player
	for (auto& moveEnnemies : ennemies) {
		Vector2f dir = gaming->mario.spr.getPosition() - moveEnnemies.mob.getPosition();
		float norme = sqrt(dir.x * dir.x + dir.y * dir.y);
		Vector2f normal(dir.x / norme, dir.y / norme);
		moveEnnemies.mob.move(normal * speedNormal * dt);
	}
	for (auto& moveEnnemiesSmall : smallEnnemies) {
		Vector2f dir = gaming->mario.spr.getPosition() - moveEnnemiesSmall.mob.getPosition();
		float norme = sqrt(dir.x * dir.x + dir.y * dir.y);
		Vector2f normal(dir.x / norme, dir.y / norme);
		moveEnnemiesSmall.mob.move(normal * speedNormal * dt);
	}
	for (auto& moveEnnemiesBig : bigEnnemies) {
		Vector2f dir = gaming->mario.spr.getPosition() - moveEnnemiesBig.mob.getPosition();
		float norme = sqrt(dir.x * dir.x + dir.y * dir.y);
		Vector2f normal(dir.x / norme, dir.y / norme);
		moveEnnemiesBig.mob.move(normal * speedNormal * dt);
	}
}