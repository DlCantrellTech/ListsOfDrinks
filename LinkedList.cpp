/*  Tilte: LinkedList.cpp
 *  Author: Dalton Cantrell
 *  Date: 10/23/24
 *  Purpose: Defines LinkedList class functions
 */

#include "LinkedList.h"
#include "ListNode.h"
#include <list>

// default constructor
template <typename typNode>
LinkedList<typNode>::LinkedList()
{
    head = NULL;
    tail = NULL;
    listSize = 0;
}

// constructor
template <typename typNode>
LinkedList<typNode>::LinkedList(typename ListNode<typNode>::NodeCell *head,typename ListNode<typNode>::NodeCell *tail, int listSize)
{
    this->head = head;
    this->tail = tail;
    this->listSize = listSize;
}

// destructor
template <typename typNode>
LinkedList<typNode>::~LinkedList() {
    while (head != NULL) {
        LinkedList temp = head;
        head = head->next;
        delete temp;
    }
}

// function prototypes
template <typename typNode>
void LinkedList<typNode>::addTo(typNode value)
{
    // make new node
    typename listNode<typNode>::NodeCell *newNode = new typename ListNode<typNode>::NodeCell(value);

    if (head == NULL)                       // if list is empty, set current node to head/tail
    {
        head == newNode;
        tail == newNode;
    }
    else                                    // if not, move pointers around to add to end of list
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    listSize ++;                            // add to list size
}

template <typename typNode>
void LinkedList<typNode>::removeFrom()
{
    // check if list is empty
    if (head == NULL)
    {
        cout << "\n\t\tError! List is already empty!\n";
        return;
    }

    // make a temporary pointer to the old head
    typename ListNode<typNode>::NodeCell *temp = head;

    head = head->next;                      // move the head of the list
    
    // if new head has content, update prev point. Else, set new initialize tail pointer
    if (head != Null)
    {
        head->prev = NULL;
    }
    else
    {
        tail = NULL;
    }

    delete temp;                            // clean up
    listSize--;                             // remove from list size
}

template <typename typNode>
void LinkedList<typNode>::getFrom()
{
    if (head == NULL)
    {
        cout << "\n\n\t\tError: List is empty\n\n";
    }
    // print functionality
}

//getter
template <typename typNode>
int LinkedList<typNode>::getListSize()
{
    return listSize;
}

//setter
template <typename typNode>
void LinkedList<typNode>::setListSize()
{
    this->listSize = listSize;
}

//friend function prototypes
template <typename typNode>
void LinkedList<typNode>::sortList(int ascending)
{
    // Find the last node
    typename ListNode<typNode>::NodeCell* high = head;
    while (high && high->next != nullptr) {
        high = high->next;
    }
    switch(ascending)
    {
        case 1: // ascending order
            quickSort(head, high);
            break;
        case 2: // descending order
            quickSortDesc(head, high);
            break;
        default:
            cout << "\n\t\tInvalid choice!" << endl;
            sortItOut();
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
void quickSortDesc(typename ListNode<typNode>::NodeCell* low, typename ListNode<typNode>::NodeCell* high, ) {
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
typename ListNode<typNode>::NodeCell* partitionDesc(typename ListNode<typNode>::NodeCell* low, typename ListNode<typNode>::NodeCell* high) {
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

template <typename typNode>
ostream& operator<<(ostream& os, const LinkedList<typNode>& LinkedList)
{
    os << "\n********************\n"

       << "\n********************\n" << endl;
    return os;
};