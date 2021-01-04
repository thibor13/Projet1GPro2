#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class AllTexture{
public:

	Texture textureIdle1;
	Texture textureIdle2;
	Texture textureIdle3;
	Texture textureIdle4;
	Texture textureIdle5;
	Texture textureIdle6;
	Texture textureIdle7;
	Texture textureIdle8;
	Texture textureIdle9;
	Texture textureIdle10;
	Texture textureIdle11;
	Texture textureIdle12;
	Texture textureIdle13;
	Texture textureIdle14;
	Texture textureIdle15;
	Texture textureIdle16;

	Texture textureWalk1;
	Texture textureWalk2;
	Texture textureWalk3;
	Texture textureWalk4;
	Texture textureWalk5;
	Texture textureWalk6;
	Texture textureWalk7;
	Texture textureWalk8;
	Texture textureWalk9;
	Texture textureWalk10;
	Texture textureWalk11;
	Texture textureWalk12;
	Texture textureWalk13;

	Texture textureRun1;
	Texture textureRun2;
	Texture textureRun3;
	Texture textureRun4;
	Texture textureRun5;
	Texture textureRun6;
	Texture textureRun7;
	Texture textureRun8;
	Texture textureRun9;
	Texture textureRun10;
	Texture textureRun11;

	Texture textureDead1;
	Texture textureDead2;
	Texture textureDead3;
	Texture textureDead4;
	Texture textureDead5;
	Texture textureDead6;
	Texture textureDead7;
	Texture textureDead8;
	Texture textureDead9;
	Texture textureDead10;
	Texture textureDead11;
	Texture textureDead12;
	Texture textureDead13;
	Texture textureDead14;
	Texture textureDead15;
	Texture textureDead16;
	Texture textureDead17;

	AllTexture() {

		if (!textureIdle1.loadFromFile("res/IDLE (1).PNG"))
			printf("Not load : IDLE 1");
		if (!textureIdle2.loadFromFile("res/IDLE (2).PNG"))
			printf("Not load : IDLE 2");
		if (!textureIdle3.loadFromFile("res/IDLE (3).PNG"))
			printf("Not load : IDLE 3");
		if (!textureIdle4.loadFromFile("res/IDLE (4).PNG"))
			printf("Not load : IDLE 4");
		if (!textureIdle5.loadFromFile("res/IDLE (5).PNG"))
			printf("Not load : IDLE 5");
		if (!textureIdle6.loadFromFile("res/IDLE (6).PNG"))
			printf("Not load : IDLE 6");
		if (!textureIdle7.loadFromFile("res/IDLE (7).PNG"))
			printf("Not load : IDLE 7");
		if (!textureIdle8.loadFromFile("res/IDLE (8).PNG"))
			printf("Not load : IDLE 8");
		if (!textureIdle9.loadFromFile("res/IDLE (9).PNG"))
			printf("Not load : IDLE 9");
		if (!textureIdle10.loadFromFile("res/IDLE (10).PNG"))
			printf("Not load : IDLE 10");
		if (!textureIdle11.loadFromFile("res/IDLE (11).PNG"))
			printf("Not load : IDLE 11");
		if (!textureIdle12.loadFromFile("res/IDLE (12).PNG"))
			printf("Not load : IDLE 12");
		if (!textureIdle13.loadFromFile("res/IDLE (13).PNG"))
			printf("Not load : IDLE 13");
		if (!textureIdle14.loadFromFile("res/IDLE (14).PNG"))
			printf("Not load : IDLE 14");
		if (!textureIdle15.loadFromFile("res/IDLE (15).PNG"))
			printf("Not load : IDLE 15");
		if (!textureIdle16.loadFromFile("res/IDLE (16).PNG"))
			printf("Not load : IDLE 16");

		if (!textureWalk1.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk2.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk3.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk4.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk5.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk6.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk7.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk8.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk9.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk10.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk11.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk12.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");
		if (!textureWalk13.loadFromFile("res/WALK (1).PNG"))
			printf("Not load : WALK 1");

		if (!textureRun1.loadFromFile("res/RUN (1).PNG"))
			printf("Not load : RUN 1");
		if (!textureRun2.loadFromFile("res/RUN (2).PNG"))
			printf("Not load : RUN 2");
		if (!textureRun3.loadFromFile("res/RUN (3).PNG"))
			printf("Not load : RUN 3");
		if (!textureRun4.loadFromFile("res/RUN (4).PNG"))
			printf("Not load : RUN 4");
		if (!textureRun5.loadFromFile("res/RUN (5).PNG"))
			printf("Not load : RUN 5");
		if (!textureRun6.loadFromFile("res/RUN (6).PNG"))
			printf("Not load : RUN 6");
		if (!textureRun7.loadFromFile("res/RUN (7).PNG"))
			printf("Not load : RUN 7");
		if (!textureRun8.loadFromFile("res/RUN (8).PNG"))
			printf("Not load : RUN 8");
		if (!textureRun9.loadFromFile("res/RUN (9).PNG"))
			printf("Not load : RUN 9");
		if (!textureRun10.loadFromFile("res/RUN (10).PNG"))
			printf("Not load : RUN 10");
		if (!textureRun11.loadFromFile("res/RUN (11).PNG"))
			printf("Not load : RUN 11");

		if (!textureDead1.loadFromFile("res/DEAD (1).PNG"))
			printf("Not load : DEAD 1");
		if (!textureDead2.loadFromFile("res/DEAD (2).PNG"))
			printf("Not load : DEAD 2");
		if (!textureDead3.loadFromFile("res/DEAD (3).PNG"))
			printf("Not load : DEAD 3");
		if (!textureDead4.loadFromFile("res/DEAD (4).PNG"))
			printf("Not load : DEAD 4");
		if (!textureDead5.loadFromFile("res/DEAD (5).PNG"))
			printf("Not load : DEAD 5");
		if (!textureDead6.loadFromFile("res/DEAD (6).PNG"))
			printf("Not load : DEAD 6");
		if (!textureDead7.loadFromFile("res/DEAD (7).PNG"))
			printf("Not load : DEAD 7");
		if (!textureDead8.loadFromFile("res/DEAD (8).PNG"))
			printf("Not load : DEAD 8");
		if (!textureDead9.loadFromFile("res/DEAD (9).PNG"))
			printf("Not load : DEAD 9");
		if (!textureDead10.loadFromFile("res/DEAD (10).PNG"))
			printf("Not load : DEAD 10");
		if (!textureDead11.loadFromFile("res/DEAD (11).PNG"))
			printf("Not load : DEAD 11");
		if (!textureDead12.loadFromFile("res/DEAD (12).PNG"))
			printf("Not load : DEAD 12");
		if (!textureDead13.loadFromFile("res/DEAD (13).PNG"))
			printf("Not load : DEAD 13");
		if (!textureDead14.loadFromFile("res/DEAD (14).PNG"))
			printf("Not load : DEAD 14");
		if (!textureDead15.loadFromFile("res/DEAD (15).PNG"))
			printf("Not load : DEAD 15");
		if (!textureDead16.loadFromFile("res/DEAD (16).PNG"))
			printf("Not load : DEAD 16");
		if (!textureDead17.loadFromFile("res/DEAD (17).PNG"))
			printf("Not load : DEAD 17");

	}
	
};