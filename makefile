.PHONY: clean all
CFLAGS = -Wall -Werror -MP -MMD

all: bin/hangman.exe

bin/hangman.exe: build/main.o build/graph.o build/otherfunc.o
	g++ $(CFLAGS) build/main.o build/graph.o build/otherfunc.o -o bin/hangman.exe
	
build/main.o: src/main.cpp src/graph.h 
	g++ $(CFLAGS) -c src/main.cpp -o build/main.o

build/graph.o: src/graph.cpp src/graph.h
	g++ $(CFLAGS) -c src/graph.cpp -o build/graph.o

build/otherfunc.o: src/otherfunc.cpp src/otherfunc.h src/graph.h
	g++ $(CFLAGS) -c src/otherfunc.cpp -o build/otherfunc.o
	
clean:
	rm -rf bin/hangman.exe
	rm -rf build/*

