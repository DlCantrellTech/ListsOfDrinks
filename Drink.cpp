#include "Drink.h"
#include "Recipe.h"

//default constructor
Drink::Drink() {
    drinkName = "";
    alcoholPercentage = 0;
    pairing = "";
    drinkRecipe = nullptr;
}

//constructor
Drink::Drink(string drinkName, int alcoholPercentage, string pairing, Recipe* drinkRecipe) {
    this->drinkName = drinkName;
    this->alcoholPercentage = alcoholPercentage;
    this->pairing = pairing;
    this->drinkRecipe = drinkRecipe;
}

//destructor
Drink::~Drink() {
    delete drinkRecipe;
}

//getter functions
string Drink::getName() {
    return drinkName;
}

int Drink::getAlcoholPercentage() {
    return alcoholPercentage;
}

string Drink::getPairing() {
    return pairing;
}

Recipe* Drink::getRecipe() {
    return drinkRecipe;
}

//setter functions
void Drink::setName(string drinkName) {
    this->drinkName = drinkName;
}

void Drink::setAlc(int alcoholPercentage) {
    this->alcoholPercentage = alcoholPercentage;
}

void Drink::setPairing(string pairing) {
    this->pairing = pairing;
}

void Drink::setRecipe(Recipe* drinkRecipe) {
    this->drinkRecipe = drinkRecipe;
}

//overloaded == operator, checks to see if the drinks attributes are equal to a differnt drink
bool Drink::operator==(const Drink& other) {
    return this->drinkName == other.drinkName
        && this->alcoholPercentage == other.alcoholPercentage
        && this->pairing == other.pairing
        && this->drinkRecipe == drinkRecipe;
}

//overloaded < operator, checks if the alcoholPercentage is < a different drinks alcoholPercentage
bool Drink::operator<(const Drink& other) {
    return this->alcoholPercentage < other.alcoholPercentage;
}

//overloaded > operator, checks if the alcoholPercentage is > a different drinks alcoholPercentage
bool Drink::operator>(const Drink& other) {
    return this->alcoholPercentage > other.alcoholPercentage;
}

//overloaded << operator
ostream& operator<<(ostream& os, const Drink& drink) {
    os << "\tDrink Name: " << drink.drinkName << endl
       << "\tAlcohol Percentage: " << drink.alcoholPercentage << "%\n"
       << "\tPairing: " << drink.pairing << endl
       << "\tRecipe:\n" << *drink.drinkRecipe;

    return os;
}