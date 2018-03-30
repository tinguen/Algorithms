tree: clean tree.o
	g++ tree.o main.cpp -o tree.o
tree.o: 
	g++ -c tree.cpp
test:	clean tree.o
	g++ tree.o test.cpp -o test.o
clean:
	rm -f *.o