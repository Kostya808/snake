#include "function.h"
#include <unistd.h>

int main() {
	Fields s;
	while(1) {
	print(&s);
	automotion(&s);
	s.field_update();
	control(&s);
	usleep(170000);
	}
	return 0;
}