#ifndef CLASS_FRUIT_H
#define CLASS_FRUIT_H

#include "base_class.h" 

class Fields;

class Fruit : public Base
{
private:
	char type;
	int score, growth, life;
public:
	void Set(int set_x, int set_y);
	int Get_X();
	int Get_Y();
	void Set(char set_type);
	char Get_type();
	void fruit_making(Fields * s);
	void fruit_print(Fields * s);
	void Set_score(int set_score);
	int Get_score();
	void Set_growth(int set_growth);
	int Get_growth();
	void Set_life(int set_life);
	int Get_life();
};

#endif
