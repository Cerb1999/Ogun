#include "Level.h"
#include "Room.h"

Level::Level(int d, Monster monsters[], Destructible crates[]) {
    l_cleared = false;
    l_depth = d;
    l_monsters = monsters;
    l_crates = crates;
    l_map[25][52];
}

boolean Level::isCleared(){
    return l_cleared;
}

Monster* getMonsters(){
    return l_monsters;
}

Destructible* getDestructibles(){
    return l_crates;
};

int** getMap(){
    return l_map;
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