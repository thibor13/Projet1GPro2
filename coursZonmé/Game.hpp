#pragma once

#pragma once

#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
//#include "Particle.hpp"
//#include "ParticleMan.hpp"
#include "Char.hpp"
#include "Ennemy.hpp"

using namespace sf;

class HotReloadShader;
class Game {
public:
	sf::RenderWindow* win = nullptr;

	sf::RectangleShape  bg;
	HotReloadShader* bgShader = nullptr;
	sf::Texture tex;
	
	Ennemy spawningMore;
	Char mario;

	bool closing = false;
	bool shift = false;
	
	std::vector<sf::Vector2i>walls;
	std::vector<sf::RectangleShape>wallSprites;

	//ParticleMan beforeParts;
	//ParticleMan afterParts;

	Game(sf::RenderWindow* win);

	void cacheWalls();
	void processInput(sf::Event ev);
	bool wasPressed = false;
	void pollInput(double dt);
	void onSpacePressed();

	void update(double dt);

	void draw(sf::RenderWindow& win);

	void onFileTick();
	bool isWall(int cx, int cy);
};

