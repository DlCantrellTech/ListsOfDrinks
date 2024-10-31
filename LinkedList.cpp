/*  Tilte: LinkedList.cpp
 *  Author: Dalton Cantrell
 *  Date: 10/23/24
 *  Purpose: Defines LinkedList class functions
 */

#include "LinkedList.h"
#include "ListNode.h"
#include "Drink.h"
#include "Recipe.h"
#include <fstream>
#include <iostream>

using namespace std;

// default constructor
template <typename typNode>
LinkedList<typNode>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

// constructor
template <typename typNode>
LinkedList<typNode>::LinkedList(ListNode<typNode> *head, ListNode<typNode> *tail, int listSize)
{
    this->head = head;
    this->tail = tail;
    this->listSize = listSize;
}

// destructor
template <typename typNode>
LinkedList<typNode>::~LinkedList() {
    while (head != nullptr) {
        ListNode<typNode>* temp = head;
        head = head->getNext();
        delete temp;
    }
}

template <typename typNode>
void LinkedList<typNode>::getFrom()
{
    string drinkName, pairing, glassware, instructions;
    int alcoholPercentage, numIngredients;
    
    cout << "\nAdding Drink:\n";

    //gets the drinks infromation from the user
    cin.ignore();
    cout << "\t\tEnter Drink Name: ";
    getline(cin, drinkName);

    cout << "\t\tEnter the alcohol Percentage: ";
    while(!(cin >> alcoholPercentage)) {
        cout << "Error Try Again:\n\t\tEnter the alcohol Percentage: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore();
    
    cout << "\t\tEnter a Pairing: ";
    getline(cin, pairing);

    cout << "\t\tNumber of Ingredients: ";
    while(!(cin >> numIngredients)) {
        cout << "Error Try Again:\n\t\tNumber of Ingredients: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore();

    string* ingredients = new string[numIngredients];
    for (int j = 0; j < numIngredients; j++) {
        cout << "\t\tIngredient #" << (j + 1) << ": ";
        getline(cin, ingredients[j]);
    }

    cout << "\t\tGlassware: ";
    getline(cin, glassware);

    cout << "\t\tInstructions (type full instructions before hitting enter): ";
    getline(cin, instructions);

    // Create a new Recipe object
    Recipe* drinkRecipe = new Recipe(numIngredients, ingredients, glassware, instructions);

    // creates a new Drink object
    Drink* newDrink = new Drink(drinkName, alcoholPercentage, pairing, drinkRecipe);

    this->addTo(newDrink);
}

// function prototypes
template <typename typNode>
void LinkedList<typNode>::addTo(typNode* value)
{
    // make new node
    //typename listNode<typNode>::NodeCell *newNode = new typename ListNode<typNode>::NodeCell(value);
    ListNode<typNode> *newNode = new ListNode<typNode>(value);

    if (head == nullptr)                       // if list is empty, set current node to head/tail
    {
        head = newNode;
        tail = newNode;
    }
    else                                    // if not, move pointers around to add to end of list
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }

    listSize ++;                            // add to list size
}

template <typename typNode>
void LinkedList<typNode>::removeFrom()
{
    // check if list is empty
    if (head == nullptr)
    {
        cout << "\n\t\tError! List is already empty!\n";
        return;
    }

    // make a temporary pointer to the old head
    ListNode<typNode> *temp = head;
    head = head->getNext();                      // move the head of the list
    
    // if new head has content, update prev point. Else, set new initialize tail pointer
    if (head != nullptr)
    {
        head->setPrev(nullptr);
    }
    else
    {
        tail = nullptr;
    }

    delete temp;                            // clean up
    listSize--;                             // remove from list size
}

template <typename typNode>
void LinkedList<typNode>::remove(Iterator it) {
    if(it.getNode() == nullptr) {
        cout << "\n\n\t\tError: current drink is empty\n\n";
        return;
    }

    ListNode<typNode>* nodeToDelete = it.getNode();

     if (nodeToDelete == head) {
            head = head->getNext();
            if (head) head->setPrev(nullptr);
            else tail = nullptr; // List is empty now
        } else {
            ListNode<typNode>* prevNode = nodeToDelete->getPrev();
            ListNode<typNode>* nextNode = nodeToDelete->getNext();

            if (prevNode) prevNode->setNext(nextNode);
            if (nextNode) nextNode->setPrev(prevNode);

            // Update tail if necessary
            if (nodeToDelete == tail) {
                tail = prevNode;
            }
        }

        delete nodeToDelete; // Free memory
        listSize--; // Decrease list size
}


//getter
template <typename typNode>
ListNode<typNode>* LinkedList<typNode>::getHead() const
{
    return this->head;
}

template <typename typNode>
int LinkedList<typNode>::getListSize() const
{
    return this->listSize;
}

//setter
template <typename typNode>
void LinkedList<typNode>::setListSize()
{
    this->listSize = listSize;
}

//friend function prototypes
template <typename typNode>
void sortList(LinkedList<typNode>& list,int ascending)
{
    switch(ascending)
    {
        case 1: // ascending order
            quickSort(list.head, list.tail);
            break;
        case 2: // descending order
            quickSortDesc(list.head, list.tail);
            break;
        default:
            cout << "\n\t\tInvalid choice!" << endl;
            //sortItOut();
            return;
    }

}

template <typename typNode>
void quickSort(typename ListNode<typNode>::NodeCell* low, typename ListNode<typNode>::NodeCell* high)
{
    if (high != nullptr && low != high && low != high->next) 
    {
        typename ListNode<typNode>::NodeCell* p = partition(low, high); // Partition the list
        quickSort(low, p->prev);                                     // Recursively sort before partition
        quickSort(p->next, high);                                    // Recursively sort after partition
    }
}

template <typename typNode>
void quickSortDesc(typename ListNode<typNode>::NodeCell* low, typename ListNode<typNode>::NodeCell* high) 
{
    if (high != nullptr && low != high && low != high->next) 
    {
        typename ListNode<typNode>::NodeCell* p = partitionDesc(low, high); // Partition the list
        quickSortDesc(low, p->prev);                                     // Recursively sort before partition
        quickSortDesc(p->next, high);                                    // Recursively sort after partition
    }
}

template <typename typNode>
typename ListNode<typNode>::NodeCell* partition(typename ListNode<typNode>::NodeCell* low, typename ListNode<typNode>::NodeCell* high)
{
    // Using the last element as the pivot
    typNode pivot = high->value;
    typename ListNode<typNode>::NodeCell* i = low->prev;                // Pointer for the greater element

    for (typename ListNode<typNode>::NodeCell* j = low; j != high; j = j->next) 
    {
        if (*j->value < pivot) {                                        // Use overloaded < operator
            i = (i == nullptr) ? low : i->next;                         // Move pointer for the greater element
            swap(i->value, j->value);                                   // Swap values
        }
    }
    i = (i == nullptr) ? low : i->next;                                 // Move to the next element
    swap(i->value, high->value);                                        // Swap the pivot

    return (i);                                                         // Return the partitioning index
}

template <typename typNode>
typename ListNode<typNode>::NodeCell* partitionDesc(typename ListNode<typNode>::NodeCell* low, typename ListNode<typNode>::NodeCell* high)
{
    // Using the last element as the pivot
    typNode pivot = high->value;
    typename ListNode<typNode>::NodeCell* i = low->prev;                // Pointer for the greater element

    for (typename ListNode<typNode>::NodeCell* j = low; j != high; j = j->next) 
    {
                                                                        // Change the comparison for descending order
        if (*j->value > pivot) {                                        // Use overloaded > operator
            i = (i == nullptr) ? low : i->next;                         // Move pointer for the greater element
            swap(i->value, j->value);                                   // Swap values
        }
    }
    i = (i == nullptr) ? low : i->next;                                 // Move to the next element
    swap(i->value, high->value);                                        // Swap the pivot

    return (i);                                                         // Return the partitioning index
}

template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& LinkedList)
{
    os << "\n********************\n"
       <<  this->value
       << "\n********************\n" << endl;
    return os;
};

template <typename typNode>
void LinkedList<typNode>::readIn()
{
    ifstream input;                 // cin file

    int choice, numDrinks = 0;
    string fileName, inputCounter;
    
    cout << "\n\nWhich file would you like to read from?\n\n\t1. Working Library\n\t2. Other\n\t3. Back\n";
    
    while(!(cin >> choice) || (choice > 3 || choice <= 0)) {
        cout << "Error Try Again:\n" << "\n\nWhich file would you like to read from?\n\n\t1. Working Library\n\t2. Other\n\t3. Back\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    switch(choice)
    {
        case 1:
            fileName = "WORKING_LIBRARY.txt";
            break;
        case 2:
            fileName.clear();
            cout << "\n\t\tEnter name of file or hit Enter key to exit: " << endl;
            cin.ignore();
            getline(cin, fileName);
            if(fileName.empty())
            {
                return;
            }
            break;
        case 3:
            break;
        default:
            cout << "\nInvalid selection!";
            break;
    }

    input.open(fileName);

    if (input.fail())               // fail case
    {
        cout << "\n\t\tFailed to open input file. Check for " << fileName << " and try again." << endl;
        return;
    }

    // count numDrinks
    while (getline(input, inputCounter, '\n'))
    {
        numDrinks++;
    }
    
    input.clear();
    input.seekg(0);

    for (int i = 0; i < numDrinks; i++)
    {
        string name, pairing, glassware, instructions;
        int alcoholPercentage, numIngredients;

        // obtain values for parameters from input file
        getline(input, name, '*');

        input >> alcoholPercentage;
        input.ignore();               // ignore *

        getline(input, pairing, '*');

        input >> numIngredients;
        input.ignore();               // ingore *

        string* ingredients = new string[numIngredients];
        for(int j = 0; j < numIngredients; j++)
        {
        getline(input, ingredients[j], '*');
        }

        getline(input, glassware, '*');

        getline(input, instructions, '*');

        Recipe* recipe = new Recipe(numIngredients, ingredients, glassware, instructions);
        Drink* newDrink = new Drink(name, alcoholPercentage, pairing, recipe);
        
        addTo(newDrink);
        //addTo(Drink(name, alcoholPercentage, pairing, new Recipe(numIngredients, ingredients, glassware, instructions)));
        input.ignore();

        delete[] ingredients;
    }

    cout << "\nSuccessfully read input file: " << fileName << endl;

    input.close();
}

template <typename typNode>
void LinkedList<typNode>::makeNew() 
{
    ofstream output;  // output file stream
    string fileName;
    string* ingredients;

    cout << "\n\tEnter the name of the new library file (ex. myDrinks.txt): ";
    cin >> fileName;
    output.open(fileName);

    // fail case
    if (output.fail()) {
        cout << "\n\t\tFailed to open output file." << endl;
        return;
    }

    // Write drinks to the file using * as delimiter !!!!!!!!!!!!!!!!!!!! change
    for(typename LinkedList<typNode>::Iterator it = this->begin(); it != this->end();) {
        typNode& drink = *it;

        output << drink.getName() << "*"
               << drink.getAlcoholPercentage() << "*"
               << drink.getPairing() << "*"
               << drink.getRecipe()->getNumIngredients() << "*";

        ingredients = drink.getRecipe()->getIngredients();
        for (int j = 0; j < drink.getRecipe()->getNumIngredients(); j++) {
            output << ingredients[j] << (j < drink.getRecipe()->getNumIngredients() - 1 ? "*" : "");
        }

        output << "*" 
               << drink.getRecipe()->getGlassware() << "*" 
               << drink.getRecipe()->getInstructions() << "*" << endl;

        this->remove(it);
        it = this->begin();
    }

    output.close();
    cout << "\nNew drink library saved to " << fileName << endl;

}

template class LinkedList<Drink>;