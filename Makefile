SRCDIR=src
FLAGS=-lsqlite3

prog.out : src/main.cpp
	g++ $(SRCDIR)/*.cpp $(FLAGS) -o prog.out

clean: 
	rm *.out