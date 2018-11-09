#ifndef CLASS_HEAD_H
#define CLASS_HEAD_H

#include "base_class.h"
#include <iostream>

class Body : public Base
{
public:
	Body *next;
	Body(int setX, int setY) {
		next = NULL;
		x = setX;
		y = setY;
	}
	~Body();
	void Set(int set_x, int set_y);
	int Get_X();
	int Get_Y();	
};

class Head : public Base
{
private:
	int type_head, type_body, score, new_x, new_y;
	char course;
public:
	Body *next;
	Body *tail;
	Head(int add_x, int add_y, int t1, int t2) : new_x(add_x), new_y(add_y) {
		type_head = t1;
		type_body = t2;
		score = 0;
		x = add_x;
		y = add_y;
		course = 't';
		tail = new Body(add_x, add_y);
		score = 0;
	}
	void Set(int set_x, int set_y);
	int Get_X();
	int Get_Y();
	void Set_Type_head(int set_t_h);
	int Get_Type_head();
	void Set_Type_head(char set_t_h_c);
	char Get_Type_head_course();
	void Set_Type_body(int set_t_b);
	int Get_Type_body();
	void Set_score(int set_score);
	int Get_score();
	void Set_new_x(int set_new_x);
	int Get_new_x();
	void Set_new_y(int set_new_y);
	int Get_new_y();
	~Head();
};

#endif