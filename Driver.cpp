#include "LinkedList.h"
#include <iostream>

using namespace std;

//function prototypes
int displayMenuGetChoice();
int validateInt(string), validateInt(string, int, int);
template <typename typNode>

int main () {
    int choice;

    do {
        choice = displayMenuGetChoice();

        switch(choice) {
            case 1: //print all drinks

                break;
            case 2: //add drink
                typNode value;
                LinkedList<typNode>.addTo(value);
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

    return validateInt("\n--------------------------------------------\n\t\tDRINK LIBRARY\n--------------------------------------------\n\t1 - Next Drink\n\t2 - Previous Drink\n\t3 - Add a Drink\n\t4 - Edit a Drink\n\t5 - Save New Drink Library\n\t6 - Change Library File\n\t7 - End the Program\n\nCHOICE: ", 7, 0);

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
