ListOfDrinks: Drink.o Driver.o LinkedList.o ListNode.o Recipe.o
	g++ Drink.o Driver.o LinkedList.o ListNode.o Recipe.o -o ListOfDrinks

Drink.o: Drink.cpp Drink.h
	g++ -c Drink.cpp

Driver.o: Driver.cpp
	g++ -c 