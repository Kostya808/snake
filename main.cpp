#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include "function.h"
#include "class_field.h"
#include "class_fruit.h"
#include "class_head.h"

int main() {
	int flag1 = 1, flag2 = 1, flag3 = 1, pause = 170000, fast1 = 0, fast2 = 0;
	Fields s;
	Fruit f1;
	Fruit f2;
	Head h1(20, 30, 1, 2);
	Head h2(20, 10, 6, 7);
	s.initial_snake_making(&h1);
	s.initial_snake_making(&h2);
	while(flag1 == 1 && flag2 == 1 && flag3 == 1) {
		print(&s, &h1, &h2);
		f1.fruit_print(&s);
		f2.fruit_print(&s);
		control(&h1, &h2);

		flag1 = automotion(&s, &h1);
		flag2 = automotion(&s, &h2);

		fast1 = s.field_update(&f1, &f2, &h1);
		fast2 = s.field_update(&f1, &f2, &h2);

		flag3 = check_head(&h1, &h2);

		usleep(pause);

		if ((fast1 == 1 || fast2 == 1) && pause > 70000) {
			pause -= 10000;
			fast1 = 0;
			fast2 = 0;
		}
	}
    endwin();
	if (flag1 == 0)
		printf("Первый игрок проиграл\n");
	else if (flag2 == 0)
		printf("Второй игрок проиграл\n");
	else if (flag3 == 0)
		printf("Вы съели друг друга\n");
	return 0;
}