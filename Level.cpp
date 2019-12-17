#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Level.h"

using namespace std;

Level::Level(short d) {
    l_cleared = false;
    l_depth = d;
    l_map = new short[25*52];
	loadStage();
	SetHero();
}

void Level::loadStage() {
    ostringstream oss;
    stringstream str;
    oss << "maps/stage" << l_depth << ".txt";

    string filename = oss.str();

    FILE* pFile;
    char c;
    short n = 0, j = 0;
    pFile = fopen(filename.c_str(),"r");
    if(pFile != NULL){
        do{
            c = fgetc(pFile);
			short val = (c - '0');

            if (c != '\n' && c != EOF){
                l_map[n] = val;
				short x = n%52;
				short y = n/52;
				switch (val) {
					case 3:
						l_monsters.push_back(Monster(l_depth, x, y, l_map));
						break;
					case 4:
						b_x = x;
						b_y = y;
						break;
					case 5:
						l_crates.push_back(Destructible(x, y, l_map));
						break;
					case 6:
						e_x = x;
						e_y = y;
					case 8:
						l_drop.push_back(Drop(x, y, l_map, false));
						break;
				}
                n++;
            }
        } while(c != EOF);
        fclose(pFile);
    }
}

void Level::SetHero() {
	switch (l_depth) {
		case 1:
		h_x = 7;
		h_y = 7;
		break;
		case 2:
		h_x = 5;
		h_y = 8;
		break;
		case 3:
		h_x = 21;
		h_y = 10;
		break;
		case 4:
		h_x = 20;
		h_y = 19;
		break;
		case 5:
		h_x = 20;
		h_y = 7;
		break;
	}
}