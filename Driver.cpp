#include "LinkedList.h"
#include <iostream>
#include <list>

using namespace std;

//function prototypes
int displayMenuGetChoice();
int validateInt(string), validateInt(string, int, int);

int main () {
    int choice;

    LinkedList<Drink> drinksList;

    drinksList.readIn();                              // access library data
    sortItOut(drinksList);                            // sort data

    LinkedList<Drink>::Iterator it = drinksList.begin();

    do {
        if(drinksList.getListSize() > 0) {
        // display current Drink and num drinks in library
            cout << "------------------------------------------------------------------------------------------------------------------"
                 << "\n\tCurrent Drink:\n\n" << *it 
                 << "------------------------------------------------------------------------------------------------------------------"    
                 << "\n\n\tCurrent Number of Drinks in Library: " << drinksList.getListSize() << endl;
        } else
            cout << "\n\t\tLibrary is currently empty. Please load or add drinks.\n\n";
        choice = displayMenuGetChoice();               // display main menu
        
        switch(choice) {
            case 1: //print current library
                if (drinksList.begin() != nullptr)
                {
                    cout << "\n" << drinksList << endl;
                }
                else    // grab or start new library if list is empty
                {
                    cout << "\n\t\tLibrary is Currently Empty!\n\n";
                    drinksList.getFrom();
                }
                break;
            case 2: //next drink
                if (it == drinksList.end())
                    it = drinksList.begin();
                else
                    ++it;
                break;
            case 3: //previous drink
                if(it == drinksList.begin())
                    it = drinksList.end();
                else
                    --it;
                break;
            case 4: //add drink
                drinksList.getFrom();
                sortItOut(drinksList);
                break;
            case 5: //remove drink
                drinksList.remove(it);
                it = drinksList.begin();
                break;
            case 6: //save file
                drinksList.makeNew();
                break;
            case 7: //change library
                while(drinksList.begin() != drinksList.end())
                    drinksList.remove(drinksList.begin());
                drinksList.remove(drinksList.end());
                drinksList.readIn();
                sortItOut(drinksList);   
                it = drinksList.begin();
                break;
            case 8: //exit program
                cout << "\n\t\tExiting Program.\n";
                return(0);
            default:
                cout << "\n\t\tInvalid choice Please try again.\n";
        }

    } while(choice != 8);

    return (0);
}

//prints main menu
int displayMenuGetChoice() {

    return validateInt("\n--------------------------------------------\n\t\tDRINK LIBRARY\n--------------------------------------------\n\t1 - Print Current Library\n\t2 - Next Drink\n\t3 - Previous Drink\n\t4 - Add a Drink\n\t5 - Remove Current Drink\n\t6 - Save New Library File\n\t7 - Change Library\n\t8 - End the Program\n\nCHOICE: ", 8, 0);

}

//validates ints
int validateInt(string prompt) {
    int num = 0;
    cout << prompt;

    while(!(cin >> num)) {
        cout << "Error Try Again:\n" << prompt;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return num;
}
int validateInt(string prompt, int high, int low) {
    int num = 0;
    cout << prompt;

    while(!(cin >> num) || (num > high || num <= low)) {
        cout << "Error Try Again:\n" << prompt;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return num;
}