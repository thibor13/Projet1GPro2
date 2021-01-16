#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class AllTexture{
public:
	
	Texture arrayIdle[16];
	Texture arrayRun[11];
	Texture arrayDead[17];
	Texture arrayWalk[13];

	Texture kdoSmall;
	Texture kdoMedium;
	Texture kdoBig;

	Texture snowballs;

	AllTexture() {

		//Textures ia
		if (!kdoSmall.loadFromFile("res/KDOSMALL.PNG"))
			printf("Not load : kdoSmall");
		if (!kdoMedium.loadFromFile("res/KDOMEDIUM.PNG"))
			printf("Not load : kdoMedium");
		if (!kdoBig.loadFromFile("res/KDOBIG.PNG"))
			printf("Not load : kdoBig");

		//Texture Bullet
		if (!snowballs.loadFromFile("res/SNOWBALL.JPG"))
			printf("Not load : bullet");

		//Texture perso
		if (!arrayIdle[0].loadFromFile("res/IDLE (1).PNG"))
			printf("Not load : IDLE 1");
		if (!arrayIdle[1].loadFromFile("res/IDLE (2).PNG"))
			printf("Not load : IDLE 2");
		if (!arrayIdle[2].loadFromFile("res/IDLE (3).PNG"))
			printf("Not load : IDLE 3");
		if (!arrayIdle[3].loadFromFile("res/IDLE (4).PNG"))
			printf("Not load : IDLE 4");
		if (!arrayIdle[4].loadFromFile("res/IDLE (5).PNG"))
			printf("Not load : IDLE 5");
		if (!arrayIdle[5].loadFromFile("res/IDLE (6).PNG"))
			printf("Not load : IDLE 6");
		if (!arrayIdle[6].loadFromFile("res/IDLE (7).PNG"))
			printf("Not load : IDLE 7");
		if (!arrayIdle[7].loadFromFile("res/IDLE (8).PNG"))
			printf("Not load : IDLE 8");
		if (!arrayIdle[8].loadFromFile("res/IDLE (9).PNG"))
			printf("Not load : IDLE 9");
		if (!arrayIdle[9].loadFromFile("res/IDLE (10).PNG"))
			printf("Not load : IDLE 10");
		if (!arrayIdle[10].loadFromFile("res/IDLE (11).PNG"))
			printf("Not load : IDLE 11");
		if (!arrayIdle[11].loadFromFile("res/IDLE (12).PNG"))
			printf("Not load : IDLE 12");
		if (!arrayIdle[12].loadFromFile("res/IDLE (13).PNG"))
			printf("Not load : IDLE 13");
		if (!arrayIdle[13].loadFromFile("res/IDLE (14).PNG"))
			printf("Not load : IDLE 14");
		if (!arrayIdle[14].loadFromFile("res/IDLE (15).PNG"))
			printf("Not load : IDLE 15");
		if (!arrayIdle[15].loadFromFile("res/IDLE (16).PNG"))
			printf("Not load : IDLE 16");

		if (!arrayWalk[0].loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!arrayWalk[1].loadFromFile("res/WALK (2).PNG"))
			printf("Not load : WALK 2");
		if (!arrayWalk[2].loadFromFile("res/WALK (3).PNG"))
			printf("Not load : WALK 3");
		if (!arrayWalk[3].loadFromFile("res/WALK (4).PNG"))
			printf("Not load : WALK 4");
		if (!arrayWalk[4].loadFromFile("res/WALK (5).PNG"))
			printf("Not load : WALK 5");
		if (!arrayWalk[5].loadFromFile("res/WALK (6).PNG"))
			printf("Not load : WALK 6");
		if (!arrayWalk[6].loadFromFile("res/WALK (7).PNG"))
			printf("Not load : WALK 7");
		if (!arrayWalk[7].loadFromFile("res/WALK (8).PNG"))
			printf("Not load : WALK 8");
		if (!arrayWalk[8].loadFromFile("res/WALK (9).PNG"))
			printf("Not load : WALK 9");
		if (!arrayWalk[9].loadFromFile("res/WALK (10).PNG"))
			printf("Not load : WALK 10");
		if (!arrayWalk[10].loadFromFile("res/WALK (11).PNG"))
			printf("Not load : WALK 11");
		if (!arrayWalk[11].loadFromFile("res/WALK (12).PNG"))
			printf("Not load : WALK 12");
		if (!arrayWalk[12].loadFromFile("res/WALK (13).PNG"))
			printf("Not load : WALK 13");

		if (!arrayRun[0].loadFromFile("res/RUN (1).PNG"))
			printf("Not load : RUN 1");
		if (!arrayRun[1].loadFromFile("res/RUN (2).PNG"))
			printf("Not load : RUN 2");
		if (!arrayRun[2].loadFromFile("res/RUN (3).PNG"))
			printf("Not load : RUN 3");
		if (!arrayRun[3].loadFromFile("res/RUN (4).PNG"))
			printf("Not load : RUN 4");
		if (!arrayRun[4].loadFromFile("res/RUN (5).PNG"))
			printf("Not load : RUN 5");
		if (!arrayRun[5].loadFromFile("res/RUN (6).PNG"))
			printf("Not load : RUN 6");
		if (!arrayRun[6].loadFromFile("res/RUN (7).PNG"))
			printf("Not load : RUN 7");
		if (!arrayRun[7].loadFromFile("res/RUN (8).PNG"))
			printf("Not load : RUN 8");
		if (!arrayRun[8].loadFromFile("res/RUN (9).PNG"))
			printf("Not load : RUN 9");
		if (!arrayRun[9].loadFromFile("res/RUN (10).PNG"))
			printf("Not load : RUN 10");
		if (!arrayRun[10].loadFromFile("res/RUN (11).PNG"))
			printf("Not load : RUN 11");

		if (!arrayDead[0].loadFromFile("res/DEAD (1).PNG"))
			printf("Not load : DEAD 1");
		if (!arrayDead[1].loadFromFile("res/DEAD (2).PNG"))
			printf("Not load : DEAD 2");
		if (!arrayDead[2].loadFromFile("res/DEAD (3).PNG"))
			printf("Not load : DEAD 3");
		if (!arrayDead[3].loadFromFile("res/DEAD (4).PNG"))
			printf("Not load : DEAD 4");
		if (!arrayDead[4].loadFromFile("res/DEAD (5).PNG"))
			printf("Not load : DEAD 5");
		if (!arrayDead[5].loadFromFile("res/DEAD (6).PNG"))
			printf("Not load : DEAD 6");
		if (!arrayDead[6].loadFromFile("res/DEAD (7).PNG"))
			printf("Not load : DEAD 7");
		if (!arrayDead[7].loadFromFile("res/DEAD (8).PNG"))
			printf("Not load : DEAD 8");
		if (!arrayDead[8].loadFromFile("res/DEAD (9).PNG"))
			printf("Not load : DEAD 9");
		if (!arrayDead[9].loadFromFile("res/DEAD (10).PNG"))
			printf("Not load : DEAD 10");
		if (!arrayDead[10].loadFromFile("res/DEAD (11).PNG"))
			printf("Not load : DEAD 11");
		if (!arrayDead[11].loadFromFile("res/DEAD (12).PNG"))
			printf("Not load : DEAD 12");
		if (!arrayDead[12].loadFromFile("res/DEAD (13).PNG"))
			printf("Not load : DEAD 13");
		if (!arrayDead[13].loadFromFile("res/DEAD (14).PNG"))
			printf("Not load : DEAD 14");
		if (!arrayDead[14].loadFromFile("res/DEAD (15).PNG"))
			printf("Not load : DEAD 15");
		if (!arrayDead[15].loadFromFile("res/DEAD (16).PNG"))
			printf("Not load : DEAD 16");
		if (!arrayDead[16].loadFromFile("res/DEAD (17).PNG"))
			printf("Not load : DEAD 17");

	}
};