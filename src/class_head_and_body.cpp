#include <class_head.h>

void Body::Set(int set_x, int set_y){
	x = set_x;
	y = set_y;
}

int Body::Get_X(){
	return x;
}

int Body::Get_Y(){
	return y;
}

Body::~Body(){
	if(next != NULL)
		delete next;
}

void Head::Set(int set_x, int set_y){
	x = set_x;
	y = set_y;
}

int Head::Get_X(){
	return x;
}

int Head::Get_Y(){
	return y;
}

void Head::Set_Type_head(int set_t_h) {
	type_head = set_t_h;
}
int Head::Get_Type_head() {
	return type_head;
}

void Head::Set_Type_head(char set_t_h_c) { //Перегрузка
	course = set_t_h_c;
}
char Head::Get_Type_head_course() {
	return course;
}

void Head::Set_Type_body(int set_t_b) {
	type_body = set_t_b;
}
int Head::Get_Type_body() {
	return type_body;
}
void Head::Set_score(int set_score){
	score = set_score;
}
int Head::Get_score(){
	return score;
}

void Head::Set_new_x(int set_new_x){
	new_x = set_new_x;
}
int Head::Get_new_x() {
	return new_x;
}
void Head::Set_new_y(int set_new_y) {
	new_y = set_new_y;
}
int Head::Get_new_y() {
	return new_y;
}

Head::~Head(){
	if(tail != NULL)
		delete tail;
	if(next != NULL)
		delete next;
}