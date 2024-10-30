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
typNode LinkedList<typNode>::getFrom()
{
    if (head == NULL)
    {
        cout << "\n\n\t\tError: List is empty\n\n";
    }
    return head->value;
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
void LinkedList<typNode>::sortList()
{

}

template <typename typNode>
ostream& operator<<(ostream& os, const LinkedList<typNode>& LinkedList)
{
    os << "\n********************\n"
       << "\n********************\n" << endl;
    return os;
}