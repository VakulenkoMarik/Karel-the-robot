# include "karel.h"
# include "stairs.h"

int main() {
	turn_on("stairs3.kw");
	set_step_delay(200);

	run();
	
	turn_off();

	return 0;
}

void run() {
	while(is_front_clear()) {
		step();
	}

	do {
		try_pick_beeper();	
		climb_stairs();
	} while(!is_front_clear());	

	put_all_beepers();
}

void try_pick_beeper() {
	while(beepers_present()) {
		pick_beeper();
	}
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

void put_all_beepers() {
	while(beepers_in_bag()) {
		put_beeper();
	}
}
