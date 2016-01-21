/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
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
#include "multiplayer.h"

#include <stdio.h>

int main()
{
	struct cell_position initial;
	initial.x = 5;
	initial.y = 5;
	initial = cell_new(initial);
	printf("%d %d\n", initial.x, initial.y);
	
	struct cell_move_data good;
	good.move_direction = 2;
	good.cell_energy = 3;
	good = cell_move(good);
	printf("%d %d\n", good.cell_energy, good.move_direction);
}
