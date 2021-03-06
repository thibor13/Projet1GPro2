#include "Char.hpp"
#include "Game.hpp"
#include "HotReloadShader.hpp"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

static int cols = 1280 / Char::GRID_SIZE;
static int lastLine = 720 / Char::GRID_SIZE - 1;

Game::Game(sf::RenderWindow* win) {
	this->win = win;
	bg = sf::RectangleShape(Vector2f(win->getSize().x, win->getSize().y));
	//displace = sf::RectangleShape(Vector2f(1280, 720));
	spawningMore = EnnemyManager(this);
	bulletSpawn = BulletManager(this);

	bool isOk = tex.loadFromFile("res/bg.jpg");
	if (!isOk) {
		printf("ERR : LOAD FAILED\n");
	}

	bg.setTexture(&tex);
	
	bg.setSize(sf::Vector2f(1280, 720));

	bgShader = new HotReloadShader("res/bg.vert", "res/bg_time.frag");
	//doubleShader = new HotReloadShader("res/bg.vert", "res/double.frag");
	//displaceShader = new HotReloadShader("res/bg.vert", "res/displace.frag");

	for (int i = 0; i < 1280 / Char::GRID_SIZE; ++i) {
		walls.push_back(Vector2i(i, 0));
		walls.push_back(Vector2i(i, lastLine));

		walls.push_back(Vector2i(0, i));
		walls.push_back(Vector2i(cols - 1, i));
	}

	cacheWalls();

	//perso
	mario = Char(this);
	mario.setCellPosition(cols >> 1, lastLine -25); // spr pos
	mario.spr.setScale(sf::Vector2f(0.08f, 0.16f));
	mario.spr.setTexture(mario.texturing.arrayIdle[0]);
};

void Game::cacheWalls()
{
	wallSprites.clear();
	for (Vector2i& w : walls) {
		sf::RectangleShape rect(Vector2f(16, 16));
		rect.setPosition(w.x * Char::GRID_SIZE, w.y * Char::GRID_SIZE);
		rect.setFillColor(sf::Color(0x07ff07ff));
		wallSprites.push_back(rect);
	}
}

void Game::processInput(sf::Event ev) {
	if (ev.type == sf::Event::Closed) {
		win->close();
		closing = true;
		return;
	}

	//fire on click
	if (ev.type == sf::Event::MouseButtonPressed) {

		sf::Vector2f mousePosition = win->mapPixelToCoords(sf::Mouse::getPosition(*win));
		sf::Vector2f trajectoire ((mousePosition.x - mario.spr.getPosition().x), (mousePosition.y - mario.spr.getPosition().y));
		bulletSpawn.spawningBullet(trajectoire);
	}
}

static float g_time = 0.0;
static float g_tickTimer = 0.0;
void Game::update(double dt) {

	pollInput(dt);
	g_time += dt;

	g_tickTimer -= dt;
	if (g_tickTimer <= 0.0) {
		onFileTick();
		g_tickTimer = 0.1;
	}
	//if (doubleShader) doubleShader->update(dt);
	//if (displaceShader) displaceShader->update(dt);
    //beforeParts.update(dt);
	if (mario.lifeSpr <= 0) {
		gameOver = true;
	}
	if (!gameOver) {
		
		if (bgShader) bgShader->update(dt);

		mario.update(dt);
		Vector2f currentPos(mario.spr.getPosition());
		spawningMore.UpdateEnnemies(currentPos, dt);
		bulletSpawn.updateBullets(dt);
		//afterParts.update(dt);

		
	}
}

void Game::draw(sf::RenderWindow& win) {
	if (closing) return;
	{
		sf::RenderStates states = sf::RenderStates::Default;
		
		//sf::Shader* sh = &bgShader->sh;
		//states.shader = sh;
		//sh->setUniform("texture", tex);

		//sh->setUniform("time", g_time);
		win.draw(bg, states);
		spawningMore.RenderEnnemies();
		bulletSpawn.bulletRender();
	}

	{
		sf::RenderStates states = sf::RenderStates::Default;
		/*sf::Shader* sh = &displaceShader->sh;
		states.shader = sh;
		sh->setUniform("texture", tex);
		sh->setUniform("texture2", displaceMap);
		sh->setUniform("uvTranslateDisp", Glsl::Vec2::Vector2(0, 0));
		sh->setUniform("uvScaleDisp", Glsl::Vec2::Vector2(1, 1));
		sh->setUniform("time", g_time);*/
		//win.draw(displace, states);
	}

	//beforeParts.draw(win);

	mario.draw(win);

	//afterParts.draw(win);
}

void Game::pollInput(double dt) {

	float lateralSpeed = 1.0;
	float maxSpeed = 10.0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
		mario.setState(Running);
		mario.currentFrame = 0;
		mario.maxFrame = 11;
	}

	if (mario.state == Running) {
		lateralSpeed *= 2.0;
		maxSpeed *= 10.0;
	}
	
	bool moved = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
		mario.speedX -= lateralSpeed;
		if (mario.speedX < -maxSpeed)
			mario.speedX = -maxSpeed;
		moved = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		mario.speedX += lateralSpeed;
		if (mario.speedX > maxSpeed)
			mario.speedX = maxSpeed;
		moved = true;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
		mario.speedY -= lateralSpeed;
		if (mario.speedY < -maxSpeed)
			mario.speedY = -maxSpeed;
		moved = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		mario.speedY += lateralSpeed;
		if (mario.speedY > maxSpeed)
			mario.speedY = maxSpeed;
		moved = true;
	}

	if (moved && mario.state == Cover || mario.state == Idle) {

		if (mario.state == Cover)
			mario.setState(Walking);
		
		if (mario.state == Idle)
			mario.setState(Walking);

		mario.currentFrame = 0;
		mario.maxFrame = 13;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		if (!wasPressed) {
			onSpacePressed();
			wasPressed = true;
		}
	}
	else {
		wasPressed = false;
	}

}

void Game::onSpacePressed() {

}

void Game::onFileTick() {

}

bool Game::isWall(int cx, int cy)
{
	for (Vector2i& w : walls) {
		if (w.x == cx && w.y == cy)
			return true;
	}
	return false;
}
