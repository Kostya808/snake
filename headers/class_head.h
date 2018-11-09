#ifndef CLASS_HEAD_H
#define CLASS_HEAD_H

class Body : public Base
{
public:
	Body *next;
	Body(int set_x, int set_y) {
		next = NULL;
		x = set_x;
		y = set_y;
	}
	~Body() {
		delete next;
	}	
};

class Head : public Base
{
public:
	int new_x, new_y, score, type_body, type_head;
	char course;
	Body *next;
	Body *tail;
	Head(int add_x, int add_y, int t1, int t2) : new_x(add_x), new_y(add_y), score(0), type_body(t2), type_head(t1) {
		x = add_x;
		y = add_y;
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