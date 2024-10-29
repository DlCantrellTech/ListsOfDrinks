/*  Tilte: LinkedList.cpp
 *  Author: Dalton Cantrell
 *  Date: 10/23/24
 *  Purpose: Defines LinkedList class functions
 */

#include "LinkedList.h"


// default constructor
LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    listSize = 0;
}

// constructor
LinkedList::LinkedList( head, tail, int listSize)
{
    this->head = head;
    this->tail = tail;
    this->listSize = listSize;
}

// destructor
LinkedList::~LinkedList() {
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// function prototypes
void LinkedList::addTo()
{

}

void LinkedList::removeFrom()
{

}

void LinkedList::getFrom()
{

}

//getter
int LinkedList::getListSize() {
    return listSize;
}

//setter
void LinkedList::setListSize()
{

}

//friend function prototypes
friend void LinkedList::sortList()
{

}

ostream& operator<<(ostream& os, const LinkedList& LinkedList)
{
    os << "\n********************\n"
       << "\n********************\n" << endl;
    return os;
}