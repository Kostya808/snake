#ifndef BASE_CLASS_H
#define BASE_CLASS_H

class Base
{
protected:
	int x, y;	
public:
	virtual void Set (int, int) = 0;
	virtual int Get_X () = 0;
	virtual int Get_Y () = 0;
	virtual ~Base(){}
};

#endif