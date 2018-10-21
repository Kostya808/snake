#ifndef CLASS_FRUIT_H
#define CLASS_FRUIT_H

#include "classes.h"

class Fruit
{
public:
	char type;
	int score, growth, x, y, life;
	Fruit() {}
	~Fruit() {}
	void fruit_making(Fields * s);
	void fruit_print(Fields * s);
};

#endif
