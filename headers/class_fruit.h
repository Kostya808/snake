#ifndef CLASS_FRUIT_H
#define CLASS_FRUIT_H

#include "base_class.h" 

class Fields;

class Fruit : public Base
{
public:
	char type;
	int score, growth, life;
	Fruit() {}
	~Fruit() {}
	void fruit_making(Fields * s);
	void fruit_print(Fields * s);
};

#endif
