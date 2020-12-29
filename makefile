main: input.o snake.o snakemap.o
	g++ main.cpp input.o snake.o snakemap.o -o main -lpthread
input.o: input.cpp
	g++ -c input.cpp -o input.o
snake.o: snake.cpp
	g++ -c snake.cpp -o snake.o
snakemap.o: snakemap.cpp
	g++ -c snakemap.cpp -o snakemap.o
clean:
	rm -f *.o
	rm main
