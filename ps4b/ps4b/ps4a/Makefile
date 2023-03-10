CC = g++
CFLAGS = -std=c++14 -Wall -pedantic
OBJ = sokoban.o main.o
DEPS = sokoban.hpp
LIB = -lsfml-graphics -lsfml-window -lsfml-system
EXE = test

all: ps4 
ps4: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LIB)
lint:
	        cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir --root=. *

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< 

clean:
	rm $(OBJ) $(EXE)
