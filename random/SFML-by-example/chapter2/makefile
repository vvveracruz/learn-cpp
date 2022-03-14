SOURCES = main.cpp Window.cpp Game.cpp
OBJECTS = $(SOURCES:.c=.o)

run:
	g++ -c -std=c++11 $(SOURCES) -I../include
	g++ -std=c++11 $(OBJECTS) -o sfml-app -L../lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=../lib && ./sfml-app

.PHONY: clean

clean:
	clear
	rm *.o
	rm sfml-app
