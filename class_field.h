#ifndef CLASS_FIELD_H
#define CLASS_FIELD_H
#include <iostream>
#include "class_fruit.h"
#include "classes.h"

typedef struct field
{
	int type;

}field;
	
class Body
{
public:
	int x, y;
	Body *next;
	Body(int set_x, int set_y) {
		next = NULL;
		x = set_x;
		y = set_y;
	}
	~Body() {}	
};

class Head
{
public:
	int x, y, new_x, new_y, score;
	char course;
	Body *next;
	Body *tail;
	Head() : x(10), y(10), new_x(10), new_y(10) {
		course = 't';
		tail = new Body(10, 10);
		score = 0;
	}
	~Head()	{
		delete tail;
		delete next;
	}
};

class Fields
{
	int i, j;
public:
	Head head1;
	field **snake_matrix;
	int size;	
	Fields() : size(20) {
		snake_matrix = new field* [size];
		
		for (i = 0; i < size; i++) {
			snake_matrix[i] = new field[size];
		}
		
		for (i = 0; i < size; i++)
			for (j = 0; j < size; j++) {
				if(i == 0 || i == size - 1 || j == 0 || j == size - 1)
					snake_matrix[i][j].type = 5;
			}

		snake_matrix[head1.x][head1.y].type = 1;
		head1.next = create_body();
		create(head1.next);
		create(head1.next);
	}
	~Fields() {
		delete snake_matrix;
	}
	void field_update(Fruit *f);
	Body* create_body();
	void eating_fruit(Fruit *f);
	void create(Body *&node);
};

int kbhit();
void print(Fields * s);
void control(Fields * s);
int automotion(Fields * s);

#endif