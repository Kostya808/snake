All: snake

snake: main.o function.o class_field.o class_fruit.o
	g++ -Wall -o snake main.o function.o class_field.o class_fruit.o -lncurses 

main.o: main.cpp
	g++ -Wall -o main.o -c main.cpp

function.o: function.cpp
	g++ -Wall -o function.o -c function.cpp

class_field.o: class_field.cpp
	g++ -Wall -o class_field.o -c class_field.cpp 

class_fruit.o: class_fruit.cpp
	g++ -Wall -o class_fruit.o -c class_fruit.cpp 

clean:
	rm -rf *.o