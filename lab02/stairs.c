# include "karel.h"

void climb_stairs();
void turn_right();
bool is_right_blocked();
bool is_front_clear();

int main() {
	turn_on("stairs3.kw");
	set_step_delay(200);

	while(is_front_clear()) {
		step();
	}

	do {
		while(beepers_present()) {
			pick_beeper();
		}
		climb_stairs();
	} while(!is_front_clear());

	while(beepers_in_bag()) {
		put_beeper();
	}

	turn_off();

	return 0;
}

void climb_stairs() {
	turn_left();

	do {
		step();
	} while(is_right_blocked());

	turn_right();
	step();
}

void turn_right() {
	turn_left();
	turn_left();
	turn_left();
}

bool is_right_blocked() {
	turn_right();
	bool result = !is_front_clear();
	turn_left();

	return result;
}

bool is_front_clear() {
	return front_is_clear();
}
