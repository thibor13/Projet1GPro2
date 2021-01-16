#include "BulletManager.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

BulletManager::BulletManager(Game* _games)
{
	games = _games;
}

void BulletManager::bulletRender() {

	for (auto& rendBullets : bullets)
		games->win->draw(rendBullets);
}

void BulletManager::updateBullets(float dt) {

	Bullet bullet;

	bullet.snowBall.setPosition((bullet.snowBall.getPosition()) + (bullet.traj * dt * BulletSpeed));
}

void BulletManager::spawningBullet(Vector2f &trajectoire) {
	
	Bullet bullet;

	bullet.snowBall.setPosition(games->mario.spr.getPosition().x, games->mario.spr.getPosition().y);
	bullet.snowBall.setScale(0.2f, 0.2f);
	bullet.snowBall.setTexture(textures.snowballs);
	bullet.traj = trajectoire;
	bullets.push_back(bullet.snowBall);
}

void BulletManager::DestroyBullet(bool) {

	
}