#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 2 //number of button

class Menu{
public:
	Menu(float width, float height);
	~Menu();
	
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getPressedIndex() { return selectedIndex; }

private:

	int selectedIndex;
	Text menu[MAX_NUMBER_OF_ITEMS];
	Font font;
};

class Levels{
public:

	Game(float width, float height);
	~Game();

	void draw(RenderWindow& window);
	
};