all: TicTacToe

TicTacToe: build/game.o build/grid.o build/bot.o build/player.o build/human.o
	g++ -o TicTacToe build/game.o build/grid.o build/bot.o build/human.o

build/grid.o: src/grid.cpp include/grid.hpp
	g++ -c src/grid.cpp -o build/grid.o

build/game.o: src/game.cpp include/grid.hpp include/bot.hpp include/player.hpp include/human.hpp
	g++ -c src/game.cpp -o build/game.o

build/bot.o: src/bot.cpp include/bot.hpp include/player.hpp
	g++ -c src/bot.cpp -o build/bot.o

build/human.o: src/human.cpp include/human.hpp include/player.hpp
	g++ -c src/human.cpp -o build/human.o

build/player.o: src/player.cpp include/player.hpp
	g++ -c src/player.cpp -o build/player.o

clean:
	rm -f TicTacToe build/*.o
