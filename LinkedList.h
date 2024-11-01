/*  Tilte: ListNode.h
 *  Author: Dalton Cantrell
 *  Date: 10/23/24
 *  Purpose: Declares LinkedList class
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
        friend void quickSort(LinkedList<T>&, ListNode<T>*, ListNode<T>*, bool);

        template <typename T>
        friend ListNode<T>* partition(LinkedList<T>&, ListNode<T>*, ListNode<T>*, bool);

        template <typename T>
        friend void sortItOut(LinkedList<T>& listToSort);

    public:
        //constructors
        LinkedList();
        LinkedList(ListNode<typNode>*, ListNode<typNode>*, int);

        //destructor
        ~LinkedList();

        //function prototypes
        void add();
        void addTo(typNode* value);
        void removeFrom();
        void getFrom();
        void readIn();
        void makeNew();
        //void swap(typNode& a, typNode& b);


        //getter
        ListNode<typNode>* getHead();
        int getListSize();

        //setter
        void setListSize();

        //friend void sortList(LinkedList<T>&, int);

        class Iterator {
            private:
                ListNode<typNode>* current;

            public:
                Iterator(ListNode<typNode>* node) {current = node;}

                typNode& operator*() {return current->getValue();}

                Iterator& operator++() {if(current) {current = current->getNext();} return *this;}

                Iterator& operator--() {if(current) {current = current->getPrev();} return *this;}

                bool operator==(const Iterator& other) {return current == other.current;}

                bool operator!=(const Iterator& other) {return current != other.current;}

                ListNode<typNode> * getNode() {return current;}
        };

        //iterator class functions
        Iterator begin() {return Iterator(head);}
        Iterator end() {return Iterator(nullptr);}
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
ListNode<typNode>* LinkedList<typNode>::getHead()
{
    return this->head;
}

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

// template <typename typNode>
// void LinkedList<typNode>::swap(typNode& a, typNode& b) {
//     typNode temp = a;
//     a = b;
//     b = temp;
// }

//friend function prototypes


// template <typename typNode>
// void quickSort(ListNode<typNode>* low, ListNode<typNode>* high)
// {
//     if (high != nullptr && low != high && low != high->getNext()) 
//     {
//         ListNode<typNode>* p = partition(low, high); // Partition the list
//         quickSort(low, p->getPrev());                                     // Recursively sort before partition
//         quickSort(p->getNext(), high);                                    // Recursively sort after partition
//     }
// }

// template <typename typNode>
// void quickSortDesc(ListNode<typNode>* low, ListNode<typNode>* high) 
// {
//     if (high != nullptr && low != high && low != high->getNext()) 
//     {
//         ListNode<typNode>* p = partitionDesc(low, high); // Partition the list
//         quickSortDesc(low, p->getPrev());                                     // Recursively sort before partition
//         quickSortDesc(p->getNext(), high);                                    // Recursively sort after partition
//     }
// }

// template <typename typNode>
// ListNode<typNode>* partition(ListNode<typNode>* low, ListNode<typNode>* high)
// {
//     // Using the last element as the pivot
//     typNode pivot = high->getValue();
//     ListNode<typNode>* i = low->getPrev();                // Pointer for the greater element

//     for (ListNode<typNode>* j = low; j != high; j = j->getNext()) 
//     {
//         if (j->getValue() < pivot) {                                        // Use overloaded < operator
//             i = (i == nullptr) ? low : i->getNext();                         // Move pointer for the greater element
//             swap(i->getValue(), j->getValue());                                   // Swap values
//         }
//     }
//     i = (i == nullptr) ? low : i->getNext();                                 // Move to the next element
//     swap(i->getValue(), high->getValue());                                        // Swap the pivot

//     return i;                                                         // Return the partitioning index
// }

// template <typename typNode>
// ListNode<typNode>* partitionDesc(ListNode<typNode>* low, ListNode<typNode>* high)
// {
//     // Using the last element as the pivot
//     typNode pivot = high->getValue();
//     ListNode<typNode>* i = low->getPrev();                // Pointer for the greater element

//     for (ListNode<typNode>* j = low; j != high; j = j->getNext()) 
//     {
//                                                                         // Change the comparison for descending order
//         if (j->getValue() > pivot) {                                        // Use overloaded > operator
//             i = (i == nullptr) ? low : i->getNext();                         // Move pointer for the greater element
//             swap(i->getValue(), j->getValue());                                   // Swap values
//         }
//     }
//     i = (i == nullptr) ? low : i->getNext();                                 // Move to the next element
//     swap(i->getValue(), high->getValue());                                        // Swap the pivot

//     return i;                                                         // Return the partitioning index
// }

template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& linkedList)
{
    ListNode<T>* current = linkedList.head;
    while (current != nullptr) {
        os << "\n********************\n" << current->getValue() << "\n********************\n"; // Using the overloaded << for Drink
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


// template <typename T>
// void sortList(LinkedList<T>& list, bool ascending)
// {
//     if(ascending) // ascending order
//         quickSort(list.head, list.tail);
//     else         // descending order
//         quickSortDesc(list.head, list.tail);
// }


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

<<<<<<< HEAD
=======
    cout << listToSort.tail->getValue() << endl;

>>>>>>> 16746435d2537bd82bd2a1f462b1ecdefad21aa8
    quickSort(listToSort, listToSort.head, listToSort.tail, (ascending==1));
    //sortList(listToSort, ascending==1);
}

template <typename T>
void quickSort(LinkedList<T>& list, ListNode<T>* low, ListNode<T>* high, bool ascending)
{
<<<<<<< HEAD
     if (low != nullptr && high != nullptr && low != high && low != high->getNext()) {
        // Partition the list
        ListNode<T>* pivot = partition(list, low, high, ascending);

        // Recursively sort the elements before and after partition
        quickSort(list, low, pivot->getPrev(), ascending); // Sort the left part
        quickSort(list, pivot->getNext(), high, ascending); // Sort the right part

    }
}

//template <typename typNode>
// ListNode<typNode>* partition(ListNode<typNode>* low, ListNode<typNode>* high)
// {
//     // Using the last element as the pivot
//     typNode pivot = high->getValue();
//     ListNode<typNode>* i = low->getPrev();                // Pointer for the greater element

//     for (ListNode<typNode>* j = low; j != high; j = j->getNext()) 
//     {
//         if (j->getValue() < pivot) {                                        // Use overloaded < operator
//             i = (i == nullptr) ? low : i->getNext();                         // Move pointer for the greater element
//             list.swapNodes(i, j);                                   // Swap values
//         }
//     }
//     i = (i == nullptr) ? low : i->getNext();                                 // Move to the next element
//     list.swapNodes(i, high);                                        // Swap the pivot

//     return i;                                                         // Return the partitioning index
// }

template <typename T>
ListNode<T>* partition(LinkedList<T>& list, ListNode<T>* low, ListNode<T>* high, bool ascending) {
    T pivot = high->getValue();
    ListNode<T>* i = low->getPrev(); // Pointer for the greater element
    cout << list;
    for (ListNode<T>* j = low; j != high; j = j->getNext()) {
        bool condition;
        if (ascending) {
            condition = (j->getValue() < pivot);
        } else {
            condition = (j->getValue() > pivot);
        }
        cout << condition;
        if (condition) {
            if (i == nullptr) {
                i = low;
            } else {
                i = i->getNext();
            }
            swapNodes(list, i, j);
            cout << "Swapped: " << i->getValue() << " with " << j->getValue() << endl;
            
        }
    }

    cout << list;

    if (i == nullptr) {
        i = low;
    } else {
        i = i->getNext();
    }

    swapNodes(list, i, high); // Swap the pivot

    return i; // Return the partitioning index
}



template <typename T>
void swapNodes(LinkedList<T>& list, ListNode<T>* nodeA, ListNode<T>* nodeB) {
    // Ensure the nodes are valid and not the same
    if (!nodeA || !nodeB || nodeA == nodeB) return;

    // Store previous and next nodes
    ListNode<T>* prevA = nodeA->getPrev();
    ListNode<T>* nextA = nodeA->getNext();
    ListNode<T>* prevB = nodeB->getPrev();
    ListNode<T>* nextB = nodeB->getNext();

    if (nextA == nodeB) {
        // A comes before B
        nodeA->setNext(nextB);  // A's next is now B's next
        nodeB->setPrev(prevA);   // B's prev is now A's prev
        nodeB->setNext(nodeA);    // B's next is A
        nodeA->setPrev(nodeB);    // A's prev is B
    } else if (nextB == nodeA) {
        // B comes before A
        nodeB->setNext(nextA);   // B's next is now A's next
        nodeA->setPrev(prevB);    // A's prev is now B's prev
        nodeA->setNext(nodeB);     // A's next is B
        nodeB->setPrev(nodeA);     // B's prev is A
    } else {
        // Non-adjacent nodes
        if (prevA) prevA->setNext(nodeB);
        if (nextA) nextA->setPrev(nodeB);
        if (prevB) prevB->setNext(nodeA);
        if (nextB) nextB->setPrev(nodeA);

        nodeA->setNext(nextB);
        nodeA->setPrev(prevB);
        nodeB->setNext(nextA);
        nodeB->setPrev(prevA);
    }
=======
    if (high && low != high && low != high->getNext()) {
        ListNode<T>* p = partition(list, low, high, ascending); // Partition the list
        cout << p->getValue();
        if (p) {
            quickSort(list, low, p->getPrev(), ascending); // Recursively sort before partition
            quickSort(list, p->getNext(), high, ascending); // Recursively sort after partition
        }
    }
}

template <typename T>
ListNode<T>* partition(LinkedList<T>& list, ListNode<T>* low, ListNode<T>* high, bool ascending)
{
    // Using the last element as the pivot
    T pivot = high->getValue();
    //cout << pivot;
    ListNode<T>* i = low->getPrev();                // Pointer for the greater element

    for (ListNode<T>* j = low; j != high; j = j->getNext()) 
    {
        if ((ascending && j->getValue() < pivot) || (!ascending && j->getValue() > pivot)) {      // Use overloaded < operator
            i = (i == nullptr) ? low : i->getNext();                         // Move pointer for the greater element
            swap(i->getValue(), j->getValue());                                   // Swap values
        }
    }
    i = (i == nullptr) ? low : i->getNext();                                 // Move to the next element
    swap(i->getValue(), high->getValue());                                        // Swap the pivot

    return i;                                                         // Return the partitioning index
>>>>>>> 16746435d2537bd82bd2a1f462b1ecdefad21aa8
}

#endif