#ifndef CLASS_FIELD_H
#define CLASS_FIELD_H
#include <iostream>

class Body;
class Head;
class Fruit;

class Fields
{
	int i, j;
public:
	int **snake_matrix;
	int size;	
	Fields() : size(40) { 
		snake_matrix = new int* [size];
		
		for (i = 0; i < size; i++) {
			snake_matrix[i] = new int[size];
		}
		
		for (i = 0; i < size; i++)
			for (j = 0; j < size; j++) {
				if(i == 0 || i == size - 1 || j == 0 || j == size - 1)
					snake_matrix[i][j] = 5;
			}
	}
	~Fields() {
		delete snake_matrix;
	}
	void initial_snake_making(Head *h);
	int field_update(Fruit *f1, Fruit *f2, Head *h);
	Body* create_body(Head *h);
	void eating_fruit(Fruit *f, Head *h);
	void create(Body *&node, Head *h);
};

#endif