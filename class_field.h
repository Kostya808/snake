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
	Head(int add_x, int add_y) : x(add_x), y(add_y), new_x(add_x), new_y(add_y) {
		course = 't';
		tail = new Body(add_x, add_y);
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
	field **snake_matrix;
	int size;	
	Fields() : size(40) {
		snake_matrix = new field* [size];
		
		for (i = 0; i < size; i++) {
			snake_matrix[i] = new field[size];
		}
		
		for (i = 0; i < size; i++)
			for (j = 0; j < size; j++) {
				if(i == 0 || i == size - 1 || j == 0 || j == size - 1)
					snake_matrix[i][j].type = 5;
			}
	}
	~Fields() {
		delete snake_matrix;
	}
	void initial_snake_making(Head *h);
	void field_update(Fruit *f, Head *h);
	Body* create_body(Head *h);
	void eating_fruit(Fruit *f, Head *h);
	void create(Body *&node, Head *h);
};

int kbhit();
void print(Fields * s, Head * h1, Head * h2);
void control(Head *h1, Head *h2);
int automotion(Fields * s, Head *h);

#endif