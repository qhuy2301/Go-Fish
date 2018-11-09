gofish: card.o deck.o player.o main.o
	c++ -o gofish main.o card.o player.o deck.o
card.o: card.cpp
	c++ -c card.cpp
deck.o: deck.cpp
	c++ -c deck.cpp
player.o: player.cpp
	c++ -c player.cpp
main.o: main.cpp
	c++ -c main.cpp
