#include <class_fruit.h>

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