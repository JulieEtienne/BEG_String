
all: main.cpp String.cpp String.h
	g++ -std=gnu++0x *.cpp -o cookie

d_all: main.cpp String.cpp String.h
	g++ -g -Wall -Wextra -std=gnu++0x *.cpp -o cookie
