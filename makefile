all:
	clang++ -Weverything -Werror -std=c++11 -pedantic -o Gosh main.cpp GoL.cpp -lncurses

clean:
	rm ./mainClass
