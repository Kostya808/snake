#include "class_field.h"
#include "class_fruit.h"
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>

int main() {
	int flag = 1;
	Fields s;
	Fruit f;
	f.fruit_making(&s);
	while(flag == 1) {
		print(&s);
		s.field_update(&f);
		f.fruit_print(&s);
		control(&s);
		usleep(200000);
		flag = automotion(&s);
	}
    endwin();
	return 0;
}