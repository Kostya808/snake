#include "class_field.h"
#include "class_fruit.h"
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>

int main() {
	int flag = 1;
	Fields s;
	Fruit f;
	Head h;
	s.initial_snake_making(&h);
	f.fruit_making(&s);
	while(flag == 1) {
		print(&s, &h);
		f.fruit_print(&s);
		control(&h);
		flag = automotion(&s, &h);
		s.field_update(&f, &h);
		usleep(150000);
	}
   endwin();
	return 0;
}