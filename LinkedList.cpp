/*  Tilte: LinkedList.cpp
 *  Author: Dalton Cantrell
 *  Date: 10/23/24
 *  Purpose: Defines LinkedList class functions
 */

#include "LinkedList.h"
#include "ListNode.h"



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
        temp = head;
        head = head->next;
        delete temp;
    }
}

// function prototypes
template <typename typNode>
void LinkedList<typNode>::addTo()
{

}

template <typename typNode>
void LinkedList<typNode>::removeFrom()
{

}

template <typename typNode>
void LinkedList<typNode>::getFrom()
{

}

//getter
template <typename typNode>
int LinkedList<typNode>::getListSize() {
    return listSize;
}

//setter
template <typename typNode>
void LinkedList<typNode>::setListSize()
{

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