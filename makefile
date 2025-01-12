HEADERS := $(wildcard src/headers/*.hpp) # nothing

compile:
	@g++ -c main.cpp -IC:/SFML-3.0.0/include

link:
	@g++ main.o -o sfml-app -LC:/SFML-3.0.0/lib -lsfml-graphics -lsfml-window -lsfml-system

execute:
	@./sfml-app

remove:
	@del sfml-app.exe
	@del main.o

build: compile link execute remove