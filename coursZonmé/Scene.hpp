#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define MAX_NUMBER_OF_ITEMS 2 //number of titles button

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

class GameSc{
public:

	GameSc(float width, float height);
	~GameSc();

	
	
};