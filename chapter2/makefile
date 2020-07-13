SOURCES = main.cpp Window.cpp
OBJECTS = $(SOURCES:.c=.o)

run:
	g++ -c $(SOURCES) -I../include
	g++ $(OBJECTS) -o sfml-app -L../lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=../lib && ./sfml-app

.PHONY: clean

clean:
	rm sfml-app
	rm *.o
