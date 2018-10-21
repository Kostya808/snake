#ifndef CLASS_HEAD_H
#define CLASS_HEAD_H

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
	int x, y, new_x, new_y, score, type_body, type_head;
	char course;
	Body *next;
	Body *tail;
	Head(int add_x, int add_y, int type1, int type2) : x(add_x), y(add_y), new_x(add_x), new_y(add_y) {
		type_head = type1;
		type_body = type2;
		course = 't';
		tail = new Body(add_x, add_y);
		score = 0;
	}
	~Head()	{
		delete tail;
		delete next;
	}
};

#endif