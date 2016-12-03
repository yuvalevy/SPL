# All Targets
all: reviiyot

reviiyot: bin/Card.o bin/Hand.o bin/Player.o bin/Deck.o bin/Game.o bin/reviiyot.o 
	@echo 'Building target: reviiyot'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/reviiyot bin/Card.o bin/Hand.o bin/Player.o bin/Deck.o bin/Game.o bin/reviiyot.o
	@echo 'Finished building target: reviiyot'
	@echo ' '

# Depends on the source and header files 
bin/reviiyot.o: src/reviiyot.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/reviiyot.o src/reviiyot.cpp

# Depends on the source and header files 
bin/Game.o: src/Game.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Game.o src/Game.cpp

# Depends on the source and header files 
bin/Deck.o: src/Deck.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Deck.o src/Deck.cpp

# Depends on the source and header files 
bin/Player.o: src/Player.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Player.o src/Player.cpp


# Depends on the source and header files 
bin/Hand.o: src/Hand.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Hand.o src/Hand.cpp


# Depends on the source and header files 
bin/Card.o: src/Card.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Card.o src/Card.cpp

#Clean the build directory
clean:
	rm -f bin/*