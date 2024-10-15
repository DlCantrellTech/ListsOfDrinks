#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>

using namespace std;

class Recipe {
    private:
        int numIngredients;
        string* ingredients;
        string glassware, instructions;

    public:
        //constructor
        Recipe();
        Recipe(int, string*, string, string);

        //destructor
        ~Recipe();

        //getter functions
        int getNumIngredients();
        string* getIngredients();
        string getGlassware();
        string getInstructions();

        //setter functions
        void setNumIngredients(int);
        void setIngredients(string*);
        void setGlassware(string);
        void setInstructions(string);

        //function prototypes
        bool operator==(const Recipe&);
        bool operator<(const Recipe&);
        bool operator>(const Recipe&);
        friend ostream& operator<<(ostream&, const Recipe&);
};

#endif