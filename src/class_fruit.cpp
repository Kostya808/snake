#include <ctime>
#include <cstdlib>
#include <class_field.h>
#include <class_fruit.h>

void Fruit::fruit_making(Fields *s) {
	int flag = 1, rand_type, check_X, check_Y;
	srand(time(NULL));
	while(flag == 1) {
		check_X = rand() % s->size;
		check_Y = rand() % s->size;
		if(s->snake_matrix[check_X][check_Y] == 0) {
			flag = 0;
			Set(check_X, check_Y);
		}
	}
	rand_type = rand() % 10;
	if(rand_type % 2 == 0) {
		Set('a');
		score = 100;
		growth = 1;
	}
	else {
		Set('b');
		score = 200;
		growth = 2;
	}
	life = 1;
}

void Fruit::fruit_print(Fields * s) {
	if (life != 1) {
		fruit_making(s);
  	}
	if(Get_type() == 'a')
		s->snake_matrix[Get_X()][Get_Y()] = 3;
	else
		s->snake_matrix[Get_X()][Get_Y()] = 4;	
}
void Fruit::Set(int set_x, int set_y){
	x = set_x;
	y = set_y;
}

int Fruit::Get_X(){
	return x;
}

int Fruit::Get_Y(){
	return y;
}

void Fruit::Set(char set_type) {
	type = set_type;
}
char Fruit::Get_type() {
	return type;
}

void Fruit::Set_score(int set_score) {
	score = set_score;
}
int Fruit::Get_score() {
	return score;
}
void Fruit::Set_growth(int set_growth) {
	growth = set_growth;
}
int Fruit::Get_growth() {
	return growth;
}
void Fruit::Set_life(int set_life) {
	life = set_life;
}
int Fruit::Get_life() {
	return life;
}