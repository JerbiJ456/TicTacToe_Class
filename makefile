all: TicTacToe

TicTacToe: build/game.o build/gamefunc.o
	g++ -o TicTacToe build/game.o build/gamefunc.o 

build/gamefunc.o: src/gamefunc.cpp include/gamefunc.hpp
	g++ -c src/gamefunc.cpp -o build/gamefunc.o

build/game.o: src/game.cpp include/gamefunc.hpp
	g++ -c src/game.cpp -o build/game.o

clean:
	rm -f TicTacToe build/*.o
