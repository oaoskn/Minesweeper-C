//
//  game.c
//  Minesweeper
//
//  Created by Kirill Gusev on 17.02.2024.
//

#include "game.h"

const int map_height = MAP_HEIGHT;
const int map_width = MAP_WIDTH;// TODO: change from game difficult

mine_cell map[MAP_HEIGHT][MAP_WIDTH];
int mines, closed_cells;

void new_game(void) {

    memset(map, 0, sizeof(map));
    mines = 20;
    closed_cells = map_height * map_width;

    for (int i = 0; i < mines; i++) {
        int x = rand() % map_width; //TODO: refactor this logic, because mines not changed
        int y = rand() % map_height;

        if (map[x][y].mine) {
            i--;
        }
        else {
            map[x][y].mine = true; // установка мины

            for (int dx = -1; dx < 2; dx++) {
                for (int dy = -1; dy < 2; dy++) {
                    if (cell_in_map(x + dx, y + dy)) {
                        map[x + dx][y + dy].count_near_mines += 1;
                    }
                }
            }
        }
    }
}

bool cell_in_map(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < map_width) && (y < map_height);
}