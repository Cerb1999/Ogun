#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Level.h"

using namespace std;

Level::Level(int d) {
    l_cleared = false;
    l_depth = d;
    l_map = (int *) malloc(25*52*sizeof(int));
}

void Level::loadStage() {
	stringstream str;
	ostringstream oss;
	oss << "maps/stage" << l_depth << ".txt";

	int i = 0; int j = - 1;
	char x;
	ifstream inFile(oss.str());
	printf("test");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1);
	}
	while (x != '\n') {
		while (inFile >> x) {
			if(j == 52){ j = 0; i++; }else{ j++; };

			str << x;
			int b;
			str >> b;
			l_map[(i*j)+j] = b;

		}
	}
	for (int k = 0; k < 25; ++k) {
		for (int l = 0; l < 52; ++l) {
		}
	}
	inFile.close();


	l_cleared = l_monsters.size() > 0;
}

Coordinates* Level::heroPosition() {
	Coordinates c = Coordinates(0., 0., l_map);
	switch (l_depth) {
		case 1:
		c.setX(7.);
		c.setY(7.);
		break;
		case 2:
		c.setX(5.);
		c.setY(8.);
		break;
		case 3:
		c.setX(21.);
		c.setY(10.);
		break;
		case 4:
		c.setX(20.);
		c.setY(19.);
		break;
		case 5:
		c.setX(20.);
		c.setY(7.);
		break;
	}
	return &c;
}

Coordinates* Level::bossPosition() {
	int i = 0; int j = 0;
	while ( l_map[(i*j)+j] != 4 || i < 25 ) {
		j++;
		if ( i < 25 ) {
			if ( j == 52 ) {
				j = 0;
				i++;
			}
		}
	}
	Coordinates c = Coordinates(double(i), double(j), l_map);
	return &c;
}

Coordinates* Level::exitPosition() {
	int i = 0; int j = 0;
	while ( l_map[(i*j)+j] != 6 || i < 25 ) {
		j++;
		if ( i < 25 ) {
			if ( j == 52 ) {
				j = 0;
				i++;
			}
		}
	}
	Coordinates c = Coordinates(double(i), double(j), l_map);
	return &c;
}