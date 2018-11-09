#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include <function.h>
#include <class_field.h>
#include <class_fruit.h>
#include <class_head.h>

int main() {
	int flag1 = 1, flag2 = 1, flag3 = 1, pause = 170000, fast1 = 0, fast2 = 0, i;
	Fields s;
	Fruit *fruit[3]; //массив указателей на объекты
	fruit[0] = new Fruit;
	fruit[1] = new Fruit;
	fruit[2] = new Fruit;
	Head h1(20, 30, 1, 2);
	Head h2(20, 10, 6, 7);
	s.initial_snake_making(&h1);//Инициализация голов змеек
	s.initial_snake_making(&h2);//
	while(flag1 == 1 && flag2 == 1 && flag3 == 1) {
		s.print(&h1, &h2);//Вывод дмумернного массива
		for(i = 0; i < 3; i++)
			s.add_fruit(&s, fruit[i]);//Инициализация фруктов
		control(&h1, &h2);//Получение направления движения 

		flag1 = s.automotion(&h1);//Шаг змейки
		flag2 = s.automotion(&h2);//

		fast1 = s.field_update(fruit, &h1);//Обновление двуммерного массива с условием хода
		fast2 = s.field_update(fruit, &h2);//

		flag3 = check_head(&h1, &h2);//Проверка на баг

		usleep(pause);//Пауза

		if ((fast1 == 1 || fast2 == 1) && pause > 70000) {//Повышение скорости после съедания фрукта
			pause -= 5000;
			fast1 = 0;
			fast2 = 0;
		}
	}
    endwin();//выход из ncurses
	if (flag1 == 0)
		printf("Первый игрок проиграл\n");
	else if (flag2 == 0)
		printf("Второй игрок проиграл\n");
	else if (flag3 == 0)
		printf("Вы съели друг друга\n");
	return 0;
}