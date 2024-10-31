#include "LinkedList.h"
#include "Drink.h"
#include <iostream>
#include <list>

using namespace std;

//function prototypes
int displayMenuGetChoice();
int validateInt(string), validateInt(string, int, int);
//template <typename typNode>
//void sortItOut(LinkedList<typNode> listToSort);

int main () {
    int choice;

    LinkedList<Drink> drinksList;

    drinksList.readIn();                    // access library data
    //sortItOut(drinksList);                            // sort data

    LinkedList<Drink>::Iterator it = drinksList.begin();

    do {
        // display current Drink and num drinks in library
        //if (drinksList.getHead() != nullptr)
        //{
        //    drinksList.getFrom();
        //    cout << "\n\tCurrent Number of Drinks in Library: " << drinksList.getListSize() << endl;
        //}
        //else    // grab or start new library if list is empty
        //{
        //    cout << "\n\t\tLibrary is Currently Empty!\n\n";
            // !!!!!!!!! add drink
            //drinksList.addTo(value);
        //}
        
        // display main menu

        cout << "\nCurrent Drink:\n" << *it << endl;

        choice = displayMenuGetChoice();

        switch(choice) {
            case 1: //next drink
                // ListNode iterator use
                if (it == drinksList.end())
                    it = drinksList.begin();
                else
                    ++it;
                break;
            case 2: //previous drink
                // ListNode iterator use
                if(it == drinksList.begin())
                    it = drinksList.end();
                else
                    --it;
                break;
            case 3: //add drink
                // !!!!!!!!! add drink
                //drinksList.addTo(value);
                
                break;
            case 4: //remove drink
                drinksList.remove(it);
                it = drinksList.begin();
                break;
            case 5: //save file

                break;
            case 6: //change file
                
                break;
            case 7: //exit program
                cout << "\n\t\tExiting Program.\n";
                break;
            default:
                cout << "\n\t\tInvalid choice Please try again.\n";
        }

    } while(choice != 7);

    return (0);
}

//prints main menu
int displayMenuGetChoice() {

    return validateInt("\n--------------------------------------------\n\t\tDRINK LIBRARY\n--------------------------------------------\n\t1 - Next Drink\n\t2 - Previous Drink\n\t3 - Add a Drink\n\t4 - Remove Current Drink\n\t5 - Save New Drink Library\n\t6 - Change Library File\n\t7 - End the Program\n\nCHOICE: ", 7, 0);

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
/*
template <typename typNode>
void sortItOut(LinkedList<typNode> listToSort)
{
    int ascending;

    cout << "\n\t\tChoose sorting order (Alcohol %):\n";
    cout << "\t\t1. Ascending\n";
    cout << "\t\t2. Descending\n";
    cout << "\t\tEnter your choice: ";
    cin >> ascending;

    listToSort.sortList(ascending);
}*/