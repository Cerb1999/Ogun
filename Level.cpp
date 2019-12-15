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
    l_map = new int[25*52];
}

void Level::loadStage() {
    printf("early load\n");
    ostringstream oss;
    stringstream str;
    oss << "maps/stage" << l_depth << ".txt";

    string filename = oss.str();

    FILE* pFile;
    char c;
    int n = 0, j = 0;
    pFile = fopen(filename.c_str(),"r");
    if(pFile != NULL){
        do{
            c = fgetc(pFile);
			int val = (c- '0');

            if (c != '\n'){
                l_map[n] = val;
				Coordinates c = Coordinates(n/25,n%25,l_map);
				switch (val) {
					case 3:
						l_monsters.push_back(Monster(l_depth, &c));
						break;
					case 5:
						l_crates.push_back(Destructible(c));
						break;
					case 8:
						l_drop.push_back(Drop(c, false));
						break;
				}
                n++;
            }
        } while(c != EOF);
        fclose(pFile);
        printf("File contains %d carac\n", n);
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
	while ( l_map[(i*25)+j] != 4 && i < 25 ) {
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
	while ( l_map[(i*25)+j] != 6 && i < 25 ) {
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