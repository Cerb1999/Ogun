#include "Level.h"
#include <stdio.h>

Level::Level(int d) {
    l_cleared = false;
    l_depth = d;
    l_map = new int[25][52];
}

void loadStage(){
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