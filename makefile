all: to.cpp
	clang++ -Weverything -Werror -std=c++11 -pedantic -o mainClass mainClass.cpp -lncurses

clean:
	rm ./mainClass
