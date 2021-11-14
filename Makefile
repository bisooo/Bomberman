CXXFLAGS = -Wall -pedantic -Wno-long-long -Wextra -lncurses
CXX = g++
RM = rm -rf
BIN = ./samymbas
DOXY = Doxyfile
OBJECTS = src/main.o src/User.o src/Game.o src/Play.o src/Object/Object.o \
					src/Object/Space.o src/Object/Wall.o src/Box/Box.o src/Map.o \
					src/Bomb/Bomb.o src/Bomb/BombA.o src/Bomb/BombB.o src/Man.o \
					src/Enemy/Enemy.o src/Enemy/Dollar.o src/Enemy/Pacman.o
MAIN = src/main.cpp src/User.h src/Play.h src/Game.h src/Man.h src/Map.h \
			 src/Object/Object.h src/Object/Wall.h src/Object/Space.h src/Box/Box.h \
 		 	 src/Enemy/Pacman.h src/Enemy/Enemy.h src/Enemy/Dollar.h src/Bomb/BombA.h \
 		 	 src/Bomb/Bomb.h src/Bomb/BombB.h
USER = src/User.cpp src/User.h src/Play.h src/Game.h src/Man.h src/Map.h \
 			 src/Object/Object.h src/Object/Wall.h src/Object/Space.h src/Box/Box.h \
 		 	 src/Enemy/Pacman.h src/Enemy/Enemy.h src/Enemy/Dollar.h src/Bomb/BombA.h \
 		 	 src/Bomb/Bomb.h src/Bomb/BombB.h
GAME = src/Game.cpp src/Game.h src/Man.h src/Map.h src/Object/Object.h \
 			 src/Object/Wall.h src/Object/Space.h src/Box/Box.h src/Enemy/Pacman.h \
 		 	 src/Enemy/Enemy.h src/Enemy/Dollar.h src/Bomb/BombA.h src/Bomb/Bomb.h \
 		 	 src/Bomb/BombB.h
PLAY = src/Play.cpp src/Play.h src/Game.h src/Man.h src/Map.h \
 			 src/Object/Object.h src/Object/Wall.h src/Object/Space.h src/Box/Box.h \
 		 	 src/Enemy/Pacman.h src/Enemy/Enemy.h src/Enemy/Dollar.h src/Bomb/BombA.h \
 		 	 src/Bomb/Bomb.h src/Bomb/BombB.h
MAP = src/Map.cpp src/Map.h src/Object/Object.h src/Object/Wall.h \
 			src/Object/Space.h src/Box/Box.h src/Enemy/Pacman.h src/Enemy/Enemy.h \
 			src/Enemy/Dollar.h src/Man.h


all: $(OBJECTS)


compile: $(BIN)


run: $(BIN)
		 $(BIN)


clean:
			$(RM) doc $(BIN) $(OBJECTS)


doc: $(DOXY)
		 rm -Rf doc
		 mkdir doc
		 doxygen $(DOXY)


$(BIN): $(OBJECTS)
			  $(CXX) $(CXXFLAGS) $(OBJECTS) -o $(BIN)


src/main.o: $(MAIN)
						$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

src/User.o: $(USER)
						$(CXX) $(CXXFLAGS) -c src/User.cpp -o src/User.o

src/Game.o: $(GAME)
						$(CXX) $(CXXFLAGS) -c src/Game.cpp -o src/Game.o

src/Play.o: $(PLAY)
						$(CXX) $(CXXFLAGS) -c src/Play.cpp -o src/Play.o

src/Map.o: $(MAP)
					 $(CXX) $(CXXFLAGS) -c src/Map.cpp -o src/Map.o

src/Man.o: src/Man.cpp src/Man.h
					 $(CXX) $(CXXFLAGS) -c src/Man.cpp -o src/Man.o

src/Object/Object.o: src/Object/Object.cpp src/Object/Object.h
										 $(CXX) $(CXXFLAGS) -c src/Object/Object.cpp -o src/Object/Object.o

src/Box/Box.o: src/Box/Box.cpp src/Box/Box.h src/Object/../Object/Object.h
							 $(CXX) $(CXXFLAGS) -c src/Box/Box.cpp -o src/Box/Box.o

src/Object/Space.o: src/Object/Space.cpp src/Object/Space.h src/Object/../Object/Object.h
										$(CXX) $(CXXFLAGS) -c src/Object/Space.cpp -o src/Object/Space.o

src/Object/Wall.o: src/Object/Wall.cpp src/Object/Wall.h src/Object/../Object/Object.h
									 $(CXX) $(CXXFLAGS) -c src/Object/Wall.cpp -o src/Object/Wall.o

src/Bomb/Bomb.o: src/Bomb/Bomb.cpp src/Bomb/Bomb.h src/Bomb/../Object/Object.h
								 $(CXX) $(CXXFLAGS) -c src/Bomb/Bomb.cpp -o src/Bomb/Bomb.o

src/BombA.o: src/Bomb/BombA.cpp src/Bomb/BombA.h src/Bomb/Bomb.h src/Bomb/../Object/Object.h
						 $(CXX) $(CXXFLAGS) -c src/Bomb/BombA.cpp -o src/Bomb/BombA.o

src/BombB.o: src/Bomb/BombB.cpp src/Bomb/BombB.h src/Bomb/Bomb.h src/Bomb/../Object/Object.h
						 $(CXX) $(CXXFLAGS) -c src/Bomb/BombB.cpp -o src/Bomb/BombB.o

src/Enemy/Enemy.o: src/Enemy/Enemy.cpp src/Enemy/Enemy.h src/Enemy/../Object/Object.h
									 $(CXX) $(CXXFLAGS) -c src/Enemy/Enemy.cpp -o src/Enemy/Enemy.o

src/Enemy/Dollar.o: src/Enemy/Dollar.cpp src/Enemy/Dollar.h src/Enemy/Enemy.h src/Enemy/../Object/Object.h
										$(CXX) $(CXXFLAGS) -c src/Enemy/Dollar.cpp -o src/Enemy/Dollar.o

src/Enemy/Pacman.o: src/Enemy/Pacman.cpp src/Enemy/Pacman.h src/Enemy/Enemy.h src/Enemy/../Object/Object.h
										$(CXX) $(CXXFLAGS) -c src/Enemy/Pacman.cpp -o src/Enemy/Pacman.o
