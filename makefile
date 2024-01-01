all: SnakeGame

SnakeGame: apple.o board.o direction.o game_engine.o painter.o point.o snake.o main.o
	g++ -o Snake.exe apple.o board.o direction.o game_engine.o painter.o point.o snake.o main.o

apple.o: apple.cpp
	g++ apple.cpp -o apple.o -c

board.o: board.cpp
	g++ board.cpp -o board.o -c

direction.o: direction.cpp
	g++ direction.cpp -o direction.o -c

game_engine.o: game_engine.cpp
	g++ game_engine.cpp -o game_engine.o -c

painter.o: painter.cpp
	g++ painter.cpp -o painter.o -c

point.o: point.cpp
	g++ point.cpp -o point.o -c

snake.o: snake.cpp
	g++ snake.cpp -o snake.o -c

main.o: main.cpp
	g++ main.cpp -o main.o -c

clean:
	rm -f *.o *.exe