#ifndef CLASS_FRUIT_H
#define CLASS_FRUIT_H

#include "classes.h"
#include "base_class.h" 

class Fruit : public Base
{
public:
    Fruit() {}
    void set_x();
    void set_y();
    void get_x();
    void get_y();
	char type;
	int score, growth, life;
	void fruit_making(Fields * s);
	void fruit_print(Fields * s);
    ~Fruit() {}
};

#endif
