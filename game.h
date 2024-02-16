//
//  game.h
//  Minesweeper
//
//  Created by Kirill Gusev on 17.02.2024.
//

#ifndef game_h
#define game_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define map_height 10
#define map_width 10
// MARK: - struct Mine Cell

typedef struct {
    bool mine;
    bool flag;
    bool open;
    int count_near_mines;
} mine_cell;

void new_game(void);
bool cell_in_map(int x, int y);

#endif /* game_h */
