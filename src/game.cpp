#include <game.h>
#include <function.h>
#include <unistd.h>
#include <ncurses.h>
#include <class_head.h>

Game::Game() {
    flag1 = 1, flag2 = 1, flag3 = 1, pause = 170000, fast1 = 0, fast2 = 0;
}

void Game::game() {
    Fields s;
    int m = 0, i;
    m = mode();
    if (m == 1) {
        Fruit *fruit[3];
	    fruit[0] = new Fruit;
	    fruit[1] = new Fruit;
	    fruit[2] = new Fruit;
        Head h1(20, 30, 1, 2);
	    Head h2(20, 10, 6, 7);
        s.initial_snake_making(&h1);
        s.initial_snake_making(&h2);
        while (flag1 == 1 && flag2 == 1 && flag3 == 1) {
            s.print(&h1, &h2);//Вывод дмумернного массива
            for (i = 0; i < 3; i++) {
                s.add_fruit(&s, fruit[i]);//Инициализация фруктов
            }
            control(&h1, &h2);//Получение направления движения 

            flag1 = s.automotion(&h1);//Шаг змейки
            flag2 = s.automotion(&h2);//

            fast1 = s.field_update(fruit, &h1, 3);//Обновление двуммерного массива с условием хода
            fast2 = s.field_update(fruit, &h2, 3);//

            flag3 = check_head(&h1, &h2);//Проверка на баг

            usleep(pause);//Пауза

            if ((fast1 == 1 || fast2 == 1) && pause > 70000) {//Повышение скорости после съедания фрукта
                pause -= 5000;
                fast1 = 0;
                fast2 = 0;
            }
	    }
    } else {
        if (m == 0) {
            Fruit *fruit[2];
            fruit[0] = new Fruit;
            fruit[1] = new Fruit;
            Head h1(20, 10, 6, 7);
            s.initial_snake_making(&h1);
            while (flag1 == 1 && flag2 == 1) {
                s.print(&h1);
                for (i = 0; i < 2; i++) {
                    s.add_fruit(&s, fruit[i]);
                }
                control_one(&h1);

                flag1 = s.automotion(&h1);

                fast1 = s.field_update(fruit, &h1, 2);

                usleep(pause);

                if (fast1 == 1 && pause > 70000) {
                    pause -= 5000;
                    fast1 = 0;
                }
	        }
        }
    }
    endwin();
}

int Game::loser() {
    int row, col;

    initscr();

    clear();

    getmaxyx(stdscr, row, col);

	if (flag1 == 0)
		mvwprintw(stdscr, row / 2, (col - 30) / 2, "The first player died");
	else if (flag2 == 0)
		mvwprintw(stdscr, row / 2, (col - 30) / 2, "The first second died");
	else if (flag3 == 0)
		mvwprintw(stdscr, row / 2, (col - 30) / 2, "You ate each other");
    getch();
    endwin();
	return 0;
}