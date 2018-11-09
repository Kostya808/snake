#ifndef FUNCTION_H
#define FUNCTION_H

class Head;
class Fields;

int kbhit();
void control(Head *h1, Head *h2);
int automotion(Fields * s, Head *h);
int check_head(Head *h1, Head *h2);

#endif