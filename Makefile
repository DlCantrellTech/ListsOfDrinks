ListOfDrinks: Drink.o Driver.o LinkedList.o ListNode.o Recipe.o
	g++ Drink.o Driver.o LinkedList.o ListNode.o Recipe.o -o ListOfDrinks

Drink.o: Drink.cpp Drink.h
	g++ -c Drink.cpp

Driver.o: Driver.cpp
	g++ -c Driver.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

ListNode.o:	ListNode.cpp ListNode.h
	g++ -c ListNode.cpp

Recipe.o: Recipe.cpp Recipe.h
	g++ -c Recipe.cpp

clean:
	del -f *.o *.exe ListOfDrinks