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
	
test: 
	bin/hangman_test.exe

bin/hangman_test.exe: build/test/main.o build/test/otherfunc_test.o
	g++ $(CFLAGS) -c build/test/main.o build/test/otherfunc_test.o build/test/otherfunc.o -o bin/hangman_test.exe
	
build/test/main.o: test/main.cpp src/otherfunc.h
	g++ $(CFLAGS) -I thirdparty -c test/main.cpp -o build/test/main.o
	g++ $(CFLAGS) -c src/otherfunc.cpp -o build/test/otherfunc.o
	
build/test/otherfunc_test.o: src/otherfunc.h test/otherfunc_test.cpp
	g++ $(CFlAGS) -c -I thirdparty test/otherfunc_test.cpp -o build/test/otherfunc_test.o
	
build/test/otherfunc.o: src/otherfunc.h src/otherfunc.cpp
	g++ $(CFLAGS) -c src/otherfunc.cpp -o build/test/otherfunc.o
		
clean:
	rm -rf bin/hangman.exe
	rm -rf bin/hangman_test.exe
	rm -rf build/*
	rm -rf build/test/*

-include build/*.d
