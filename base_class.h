#ifndef BASE_CLASS_H
#define BASE_CLASS_H

class Base
{
//private:
//    int coox;
//    int cooy;

public:
    Base() {}
    virtual void setx() = 0;
    virtual void sety() = 0;
//    virtual int get_x();
//    virtual int get_y();
    virtual ~Base();
};

#endif
