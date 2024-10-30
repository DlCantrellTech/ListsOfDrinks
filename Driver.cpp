#include "LinkedList.h"
#include <iostream>

using namespace std;

//function prototypes
int displayMenuGetChoice();
int validateInt(string), validateInt(string, int, int);
void sortOptions();
template <typename typNode>

int main () {
    int choice;
    readIn();
    sortItOut();
    do {
        choice = displayMenuGetChoice();

        switch(choice) {
            case 1: //next drink
                // ListNode iterator use
                break;
            case 2: //previous drink
                // ListNode iterator use
                break;
            case 3: //add drink
                typNode value;
                LinkedList<typNode>.addTo(value);
                break;
            case 4: //edit drink

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
template <typename typNode>
void sortItOut()
{
    int ascending;

    cout << "\n\t\tChoose sorting order (Alcohol %):\n";
    cout << "\t\t1. Ascending\n";
    cout << "\t\t2. Descending\n";
    cout << "\t\tEnter your choice: ";
    cin >> ascending;

    LinkedList<typNode>.sortList(ascending);
}