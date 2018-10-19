#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>

typedef struct coordinats
{
	int x, y, new_x, new_y, type;
	char course;
}coordinats;
	

class Fields
{
	int i;
public:
	int **snake_matrix, size;	
	coordinats head;	
	Fields() : size(20) {
		head.x = 10; 
		head.y = 10;
		head.new_x = 10; 
		head.new_y = 10;
		head.type = 1;
		head.course = 't';
		snake_matrix = new int* [size];
		for (i = 0; i < size; i++) {
			snake_matrix[i] = new int[size];
		}
		snake_matrix[head.x][head.y] = head.type;
	}
	~Fields() {
		delete snake_matrix;
	}

	void field_update() {
		if(head.new_x != head.x || head.new_y != head.y) {
			snake_matrix[head.new_x][head.new_y] = head.type;
			snake_matrix[head.x][head.y] = 0;
			head.x = head.new_x; 
			head.y = head.new_y;
		}
	}
	
};

class snake_length
{
public:
	snake_length();
	~snake_length();
	
};
int kbhit();
void print(Fields * s);
void control(Fields * s);
void automotion(Fields * s);

#endif