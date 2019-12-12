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
    l_map[25][52];
}

void Level::loadStage() {
	ostringstream oss;
	oss << "maps/stage" << l_depth << ".txt";
	cout << oss.str();
    ifstream infile("maps/stage1.txt");

	int i = -1; int j = -1;
	while(infile){
		string s;
		if(!getline(infile, s)) break;
		i++;
		istringstream ss(s);
		 	
		while(ss){
			j++;
			if(i == 25) i = -1;
			string s;
			if(!getline(ss,s, ' '))break;
			l_map[i][j] = atoi(s.c_str());
			printf("%d, %d \n", i, j);
		}
	}
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
	while ( l_map[i][j] != 6 || i < 25 ) {
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
