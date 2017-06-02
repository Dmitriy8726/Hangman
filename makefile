.PHONY: clean all test 
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
	make bin/hangman_test.exe 
	bin/hangman_test.exe 

bin/hangman_test.exe: build/test/main.o build/test/otherfunc_test.o
	@gcc $(CFLAGS) build/test/main.o build/test/otherfunc_test.o build/test/otherfunc.o -o bin/hangman_test.exe 

build/test/main.o: test/main.c test/otherfunc2.h 
	@gcc $(CFLAGS) -I thirdparty -c test/main.c -o build/test/main.o 
	@gcc $(CFLAGS) -c test/otherfunc2.c -o build/test/otherfunc.o 

build/test/otherfunc_test.o: test/otherfunc2.h test/otherfunc_test.c
	@gcc $(CFlAGS) -c -I thirdparty test/otherfunc_test.c -o build/test/otherfunc_test.o 

build/test/otherfunc.o: test/otherfunc2.h test/otherfunc2.c 
	@gcc $(CFLAGS) -c test/otherfunc2.c -o build/test/otherfunc.o 

clean:
	@echo "Cleaning files in build directory" 	
	@rm -rf build/*.d build/*.o 
	@rm -rf build/test/*.d build/test/*.o
	@echo "Cleaning binaries"
	@rm -rf bin/hangman.exe 
	@rm -rf bin/hangman_test.exe 
	@echo "All files have been cleaned."	

-include build/*.d
