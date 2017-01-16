
all: main.cpp String.cpp String.h
	g++ *.cpp -o cookie

d_all: main.cpp String.cpp String.h
	g++ -g *.cpp -o cookie
