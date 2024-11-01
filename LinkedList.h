/*  Tilte: ListNode.h
 *  Author: Dalton Cantrell
 *  Date: 10/23/24
 *  Purpose: Declares LinkedList class and defines its functions
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"
#include "Drink.h"
#include "Recipe.h"
#include <fstream>
#include <iostream>

using namespace std;

template <typename typNode>
class LinkedList {
    private:
        ListNode<typNode> *head;
        ListNode<typNode> *tail;
        int listSize;

        //friend function prototypes
        
        template <typename T>
        friend ostream& operator<<(ostream&, const LinkedList<T>&);

        template <typename T>
        friend void quickSort(LinkedList<typNode>&, ListNode<typNode>*, ListNode<typNode>*, bool);

        template <typename T>
        friend ListNode<typNode>* partition(LinkedList<typNode>&, ListNode<typNode>*, ListNode<typNode>*, bool);

        template <typename T>
        friend void sortItOut(LinkedList<T>& listToSort);

        template <typename T>
        friend void swapNodes(LinkedList<T>&, ListNode<T>*, ListNode<T>*);

    public:
        //constructors
        LinkedList();
        LinkedList(ListNode<typNode>*, ListNode<typNode>*, int);

        //destructor
        ~LinkedList();

        //function prototypes
        void addTo(typNode* value);
        void getFrom();
        void readIn();
        void makeNew();


        //getter
        int getListSize();

        //setter
        void setListSize();

        class Iterator {
            private:
                ListNode<typNode>* current;

            public:
                Iterator(ListNode<typNode>* node) {current = node;}

                typNode& operator*() {return *current->getValue();}

                Iterator& operator++() {if(current) {current = current->getNext();} return *this;}

                Iterator& operator--() {if(current) {current = current->getPrev();} return *this;}

                bool operator==(const Iterator& other) {return current == other.current;}

                bool operator!=(const Iterator& other) {return current != other.current;}

                ListNode<typNode> * getNode() {return current;}
        };

        //iterator class functions
        Iterator begin() {return Iterator(head);}
        Iterator end() {return Iterator(tail);}
        void remove(Iterator);
};

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

// function prototypes
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

    // get ingredients list from user via array
    string* ingredients = new string[numIngredients];
    for (int j = 0; j < numIngredients; j++) {
        cout << "\t\tIngredient #" << (j + 1) << ": ";
        getline(cin, ingredients[j]);
    }

    cout << "\t\tGlassware: ";
    getline(cin, glassware);

    cout << "\t\tInstructions (type full instructions before hitting enter): ";
    getline(cin, instructions);

    // Create a new Recipe object and populates it
    Recipe* drinkRecipe = new Recipe(numIngredients, ingredients, glassware, instructions);

    // creates a new Drink object and populates it
    Drink* newDrink = new Drink(drinkName, alcoholPercentage, pairing, drinkRecipe);
    this->addTo(newDrink);
}

template <typename typNode>
void LinkedList<typNode>::addTo(typNode* value)
{
    // make new node
    ListNode<typNode> *newNode = new ListNode<typNode>(value);

    if (head == nullptr)                    // if list is empty, set current node to head/tail
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

        delete nodeToDelete;    // Free memory
        listSize--;             // Decrease list size
}

//getter
template <typename typNode>
int LinkedList<typNode>::getListSize()
{
    return this->listSize;
}

//setter
template <typename typNode>
void LinkedList<typNode>::setListSize()
{
    this->listSize = listSize;
}

template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& linkedList)
{
    ListNode<T>* current = linkedList.head;
    while (current != nullptr) {
        os << "\n********************\n" << *current->getValue() << "\n********************\n"; // Using the overloaded << for Drink
        current = current->getNext();
    }
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

    // Write drinks to the file using * as delimiter
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

template <typename T>
void sortItOut(LinkedList<T>& listToSort)
{
    int ascending;

    cout << "\n\t\tChoose sorting order (Alcohol %):\n";
    cout << "\t\t1. Ascending\n";
    cout << "\t\t2. Descending\n";
    cout << "\t\tEnter your choice: ";
    
    while(!(cin >> ascending) || (ascending != 1 && ascending != 2)) {
        cout << "Error Try Again:\n\t\tChoose sorting order (Alcohol %):\n\t\t1. Ascending\n\t\t2. Descending\n\t\tEnter your choice: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    quickSort(listToSort, listToSort.head, listToSort.tail, (ascending==2));
}

template <typename typNode>
void quickSort(LinkedList<typNode>& list, ListNode<typNode>* low, ListNode<typNode>* high, bool ascending)
{
     if (low != nullptr && high != nullptr && low != high && low != high->getNext()) {
        // Partition the list
        ListNode<typNode>* pivot = partition(list, low, high, ascending);

        // Recursively sort the elements before and after partition
        quickSort(list, low, pivot->getPrev(), ascending); // Sort the left part
        quickSort(list, pivot->getNext(), high, ascending); // Sort the right part

    }
}

template <typename typNode>
ListNode<typNode>* partition(LinkedList<typNode>& list, ListNode<typNode>* low, ListNode<typNode>* high, bool ascending) {
    typNode* pivot = high->getValue();  // Use the value of the high node as the pivot
    ListNode<typNode>* i = low;          // Start from the low end of the list

    for (ListNode<typNode>* j = low; j != high; j = j->getNext()) {
        // Determine if we should swap based on ascending or descending order
        if ((ascending && *j->getValue() > *pivot) || 
            (!ascending && *j->getValue() < *pivot)) {
            if (i != j) {
                // Swap values (pointers) of i and j
                typNode* temp = i->getValue();
                i->setValue(j->getValue()); // Use setValue to assign j's value to i
                j->setValue(temp);           // Use setValue to assign temp (value of i) to j
            }
            i = i->getNext();  // Move the i pointer forward
        }
    }

    // Swap the pivot with the i pointer
    if (i != high) {
        typNode* temp = i->getValue();
        i->setValue(high->getValue()); // Use setValue to assign high's value to i
        high->setValue(temp);           // Use setValue to assign temp (value of i) to high
    }

    return i;  // Return the new partition point
}

#endif