#include "LinkedList.h"
#include <iostream>

using namespace std;

//function prototypes
int displayMenuGetChoice();
int validateInt(string), validateInt(string, int, int);

int main () {
    int choice;

    do {
        choice = displayMenuGetChoice();

        switch(choice) {
            case 1: //print all drinks

                break;
            case 2: //add drink

                break;
            case 3: //edit drink

                break;
            case 4: //save file

                break;
            case 5: //change file
                
                break;
            case 6: //exit program
                cout << "\n\t\tExiting Program.\n";
                break;
            default:
                cout << "\n\t\tInvalid choice Please try again.\n";
        }

    } while(choice != 6);

    return (0);
}

//prints main menu
int displayMenuGetChoice() {

    return validateInt("\n--------------------------------------------\n\t\tDRINK LIBRARY\n--------------------------------------------\n\t1 - Display all Drinks\n\t2 - Add a Drink\n\t3 - Edit a Drink\n\t4 - Save New Drink Library\n\t5 - Change Library File\n\t6 - End the Program\n\nCHOICE: ", 6, 0);

}

//validates ints
int validateInt(string prompt) {
    int num;
    cout << prompt;

    while(!(cin >> num)) {
        cout << "Error Try Again:\n" << prompt;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return num;
}
int validateInt(string prompt, int high, int low) {
    int num;
    cout << prompt;

    while(!(cin >> num) || (num > high || num <= low)) {
        cout << "Error Try Again:\n" << prompt;
        cin.clear();
        cin.ignore(1000, '\n');
    }

    return num;
}
