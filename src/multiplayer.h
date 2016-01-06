//
// Created by dell-iman on 1/6/2016.
//

#ifndef GOOD_MULTIPLAYER_H
#define GOOD_MULTIPLAYER_H

struct cell_move_data {
    int cell_id;
    int move_direction;
};

int cell_new();

struct cell_move_data cell_move(struct cell_move_data your_move);

#endif //GOOD_MULTIPLAYER_H
