#include <iostream> // inclut un entete/header appelé iostream

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>
#include "Dice.hpp"
#include "Lib.hpp"
#include "Game.hpp"
#include "Interp.hpp"
#include <SFML/OpenGL.hpp>
#include "Scene.hpp"

using namespace std;
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "SFML works!");
	window.setVerticalSyncEnabled(true);

	Font font;

	if (!font.loadFromFile("res/ARIAL.TTF")) {
		cout << "ERROR NO FONT" << endl;
		return 1;
	}

	if (!sf::Shader::isAvailable())
	{
		cout << "ERROR NO SHADER SYSTEM" << endl;
		return 1;
	}

	Menu menu(window.getSize().x, window.getSize().y);
	Game g(&window);

	Vector2i winPos;

	View v = window.getDefaultView();
	Vector2f viewCenter = v.getCenter();
	float shakeStrength = 0.0;

	sf::Text fpsCounter;
	fpsCounter.setFont(font);
	fpsCounter.setString("FPS:");

	double frameStart = 0.0;
	double frameEnd = 0.0;
	while (window.isOpen())
	{
		double dt = frameEnd - frameStart;
		frameStart = Lib::getTimeStamp();

		if (dt < 0.001) {
			dt = 0.001;
		}

		sf::Event event;
		while (window.pollEvent(event)) { //sort un evenement de la liste pour le traiter

			switch (event.type) {

			case Event::KeyReleased:
				switch (event.key.code) {

				case Keyboard::Up:
					menu.MoveUp();
					break;
				case Keyboard::Down:
					menu.MoveDown();
					break;
				case Keyboard::Return:
					switch (menu.getPressedIndex()) {
					case 0:
						//load game scene 
						break;
					case 1:
						//close game
						window.close();
						break;
					}
					
				}
				break;
			case Event::Closed:
				window.close();
				break;
			}
			g.processInput(event);

		}
			

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			shakeStrength = 15.0;
		}

		g.update(dt);

		window.clear();

		window.setView(v);

		Vector2f n(viewCenter); //viewCenter.x = shakeStrength * 10;
		n.x += cos(shakeStrength * 1 * Dice::randSign());
		n.y += sin(-shakeStrength * 1 * Dice::randSign());
		v.setCenter(n);

		window.setView(v);

		menu.draw(window);
		g.draw(window);

		window.draw(fpsCounter);
		window.display();

		shakeStrength *= 0.85;
		if (shakeStrength <= 0.01)
			shakeStrength = 0.0;

		frameEnd = Lib::getTimeStamp();
		fpsCounter.setString("FPS:" + std::to_string(1.0 / dt));
	}

	return 0;
}