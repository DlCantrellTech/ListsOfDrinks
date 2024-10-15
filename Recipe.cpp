#include "Recipe.h"

//Constructors
Recipe::Recipe()
{
    numIngredients = 0;
    ingredients = nullptr;
    glassware = " ";
    instructions = " ";
}

Recipe::Recipe(int numIngredients, string* ingredients, string glassware, string instructions)
{
    this->numIngredients = numIngredients;
    this->ingredients = ingredients;
    this->glassware = glassware;
    this->instructions = instructions;
}

//Deconstructors
Recipe::~Recipe()
{
    delete[] ingredients;
}

//getter functions
string* Recipe::getIngredients() {
    return ingredients;
}

int Recipe::getNumIngredients() {
    return numIngredients;
}

string Recipe::getGlassware() {
    return glassware;
}

string Recipe::getInstructions() {
    return instructions;
}

//setter functions
void Recipe::setIngredients(string* ingredients) {
    this->ingredients = ingredients;
}

void Recipe::setNumIngredients(int numIngredients) {
    this->numIngredients = numIngredients;
}

void Recipe::setGlassware(string glassware) {
    this->glassware = glassware;
}

void Recipe::setInstructions(string instructions) {
    this->instructions = instructions;
}

//overloaded == operator
bool Recipe::operator==(const Recipe& other) {
    return this->numIngredients == other.numIngredients
        && this->ingredients == other.ingredients
        && this->glassware == other.glassware
        && this->instructions == other.instructions;
}

//overloaded < operator, checks if the number of ingredients is <
bool Recipe::operator<(const Recipe& other) {
    return this->numIngredients < other.numIngredients;
}

//overloaded > operator, checks if the number of ingredients is >
bool Recipe::operator>(const Recipe& other) {
    return this->numIngredients > other.numIngredients;
}

//overloaded << operator
ostream& operator<<(ostream& os, const Recipe& recipe) {
    os << "\t  Ingredients: " << endl;
        for (int j = 0; j < recipe.numIngredients; j++)
        {
            os << "\t   * " << recipe.ingredients[j] << endl;
        }

    os << "\t  Glassware: " << recipe.glassware << endl
       << "\t  Instructions: " << recipe.instructions << endl;

    return os;
}