#ifndef CLASS_FIELD_H
#define CLASS_FIELD_H
#include <iostream>

class Body;
class Head;
class Fruit;

class Fields
{
	int i, j, size;	
	int **snake_matrix;
public:
	Fields() : size(40) { //перегрузка конструктора
		initial_field();
	}
	Fields(int set_size);
	~Fields() {
		delete snake_matrix;
	}
	void initial_field();
	void initial_snake_making(Head *h);
	int field_update(Fruit *f[], Head *h);
	Body* create_body(Head *h);
	void eating_fruit(Fruit *f, Head *h);
	void create(Body *&node, Head *h);
	void print(Head * h1, Head * h2);
	void print(Head * h);
	int automotion(Head *h);
	void add_fruit(Fields *s, Fruit * f);
	void fruit_making(Fruit *f);
};

#endif