run:
	g++ -std=c++11 -O KD_Tree.cpp
	./a.out

check:
	valgrind --leak-check=full g++ -std=c++11 -O KD_Tree.cpp

clean:
	rm ./a.out
