/*
 * In The Name Of God
 * ========================================
 * [] File Name : multiplayer.h
 *
 * [] Creation Date : 19-01-2016
 *
 * [] Created By : Iman Tabrizian (tabrizian@outlook.com)
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani and Iman Tabrizian.
*/
#ifndef GOOD_MULTIPLAYER_H
#define GOOD_MULTIPLAYER_H

struct cell_move_data {
    int cell_id;
    int move_direction;
};

int cell_new();

struct cell_move_data cell_move(struct cell_move_data your_move);

#endif //GOOD_MULTIPLAYER_H
