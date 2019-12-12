#include <stdio.h>
#include "Level.h"

Level::Level(int d) {
    l_cleared = false;
    l_depth = d;
    l_map[25][52];
}

void Level::loadStage() {
    int c;
    int l = 0;
    int col = 0;
    while ((c = getchar()) != EOF) {
        col++;
        if(col == 25){
            col = 0;
            l++;
        }
        l_map[l][col] = c;
    }
}

Coordinates* Level::heroPosition() {
	Coordinates c = Coordinates(0., 0.);
	switch (l_depth) {
		case 1:
		c.set(7.,7.);
		break;
		case 2:
		c.set(5.,8.);
		break;
		case 3:
		c.set(21.,10.);
		break;
		case 4:
		c.set(20.,19.);
		break;
		case 5:
		c.set(20.,7.);
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
	Coordinates c = Coordinates(double(i), double(j));
	return &c;
}
