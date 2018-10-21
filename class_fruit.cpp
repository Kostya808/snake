#include "class_field.h"
#include "class_fruit.h"
#include <ctime>
#include <cstdlib>

void Fruit::fruit_making(Fields *s) {
	int flag = 1, rand_type;
	srand(time(NULL));
	while(flag == 1) {
		x = rand() % s->size;
		y = rand() % s->size;
		if(s->snake_matrix[x][y].type == 0)
			flag = 0;
	}
	rand_type = rand() % 10;
	if(rand_type % 2 == 0) {
		type = 'a';
		score = 100;
		growth = 1;
	}
	else {
		type = 'b';
		score = 200;
		growth = 2;
	}
	life = 1;
}

void Fruit::fruit_print(Fields * s) {
	if (life != 1) {
		fruit_making(s);
  	}
	else {
		if(type == 'a')
			s->snake_matrix[x][y].type = 3;
		else
			s->snake_matrix[x][y].type = 4;
	}
}