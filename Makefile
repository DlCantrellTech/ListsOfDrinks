ListOfDrinks: Drink.o Driver.o  Recipe.o
	g++ Drink.o Driver.o  Recipe.o -o ListOfDrinks

Drink.o: Drink.cpp Drink.h
	g++ -c Drink.cpp

Driver.o: Driver.cpp
	g++ -c Driver.cpp

Recipe.o: Recipe.cpp Recipe.h
	g++ -c Recipe.cpp

clean:
	del -f *.o *.exe ListOfDrinks