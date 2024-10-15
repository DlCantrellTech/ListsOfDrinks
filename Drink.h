#ifndef DRINK_H
#define DRINK_H

#include <iostream>

using namespace std;

class Recipe;

class Drink {
    private:
        string drinkName, pairing;
        int alcoholPercentage;
        Recipe* drinkRecipe;

    public:
        //constructor
        Drink();
        Drink(string, int, string, Recipe*);
        
        //destructor
        ~Drink();

        //getter functions
        string getName();
        string getPairing();
        int getAlcoholPercentage();
        Recipe* getRecipe();

        //setter functions
        void setName(string);
        void setPairing(string);
        void setAlc(int);
        void setRecipe(Recipe*);

        //function prototypes
        bool operator==(const Drink&);
        bool operator<(const Drink&);
        bool operator>(const Drink&);
        friend ostream &operator<<(ostream&, const Drink&);
};

#endif