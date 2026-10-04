#ifndef STAIRS_H
#define STAIRS_H

#include <stdbool.h>

void climb_stairs(void);
void turn_right(void);
void run(void);
void put_all_beepers(void);
void try_pick_beeper(void);

bool is_right_blocked(void);
bool is_front_clear(void);

#endif
