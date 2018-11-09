All: snake

snake: main.o function.o class_field.o class_fruit.o
	g++ -Wall -o snake main.o function.o class_field.o class_fruit.o -lncurses 

main.o: src/main.cpp
	g++ -Wall -o main.o -c src/main.cpp -Iheaders

function.o: src/function.cpp
	g++ -Wall -o function.o -c src/function.cpp -Iheaders

class_field.o: src/class_field.cpp
	g++ -Wall -o class_field.o -c src/class_field.cpp -Iheaders

class_fruit.o: src/class_fruit.cpp
	g++ -Wall -o class_fruit.o -c src/class_fruit.cpp -Iheaders

clean:
	rm -rf *.o