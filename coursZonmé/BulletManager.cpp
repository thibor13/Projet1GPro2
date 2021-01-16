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
		games->win->draw(rendBullets.snowBall);
}

void BulletManager::updateBullets(float dt) {

	for (int i = 0; i < bullets.size(); i++) {

		bullets[i].snowBall.setPosition((bullets[i].snowBall.getPosition()) + (bullets[i].traj * dt * BulletSpeed));
	}

	
}

void BulletManager::spawningBullet(Vector2f &trajectoire) {
	
	Bullet bullet;

	bullet.snowBall.setPosition(games->mario.spr.getPosition().x, games->mario.spr.getPosition().y);
	bullet.snowBall.setScale(0.05f, 0.05f);
	bullet.snowBall.setTexture(textures.snowballs);
	bullet.traj = trajectoire;
	bullets.push_back(bullet);
}

void BulletManager::DestroyBullet(bool) {

	
}