#include "BulletManager.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

BulletManager::BulletManager(Game* _games)
{
	games = _games;
	ennemy = &games->spawningMore;
}

void BulletManager::bulletRender() {

	for (auto& rendBullets : bullets)
		games->win->draw(rendBullets.snowBall);
}

void BulletManager::updateBullets(float dt) {

	for (int i = bullets.size() - 1; i >= 0; i--) {
		
		bullets[i].snowBall.setPosition((bullets[i].snowBall.getPosition()) + (bullets[i].traj * dt * BulletSpeed));

		Vector2f posBullets = bullets[i].snowBall.getPosition();

		//destroy when out of win
		if (bullets[i].isDestroyed == false) {
			if (posBullets.x > 1280 || posBullets.y > 720 || posBullets.x < 0 || posBullets.y < 0) {
				bullets[i].isDestroyed = true;
			}
		}
		
		//destroy when hit ennemies
		if (bullets[i].isDestroyed == false) {
			for (int b = ennemy->ennemies.size() - 1; b >= 0; b--) {
				if (ennemy->ennemies[b].mob.getGlobalBounds().contains(posBullets)) {
					bullets[i].isDestroyed = true;
					
					continue;
				}
			}
		}
		if (bullets[i].isDestroyed == false) {
			for (int c = ennemy->bigEnnemies.size() - 1; c >= 0; c--) {
				if (ennemy->bigEnnemies[c].mob.getGlobalBounds().contains(posBullets)) {
					bullets[i].isDestroyed = true;
					continue;
				}
			}
		}
		if (bullets[i].isDestroyed == false) {
			for (int d = ennemy->smallEnnemies.size() - 1; d >= 0; d--) {
				if (ennemy->smallEnnemies[d].mob.getGlobalBounds().contains(posBullets)) {
					bullets[i].isDestroyed = true;
					continue;
				}
			}
		}
		if(bullets[i].isDestroyed == true)
			bullets.erase(bullets.begin() + i);
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

