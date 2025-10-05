SRCDIR=src

prog.out : src/main.cpp
	g++ $(SRCDIR)/*.cpp -o prog.out