double: clean list.o
	g++ list.o main.cpp -o double.o
list.o: 
	g++ -c list.cpp
test:	clean list.o
	g++ list.o test.cpp -o test.o
clean:
	rm -f *.o