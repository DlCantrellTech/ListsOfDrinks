/*  Tilte: ListNode.h
 *  Author: Dalton Cantrell
 *  Date: 10/23/24
 *  Purpose: Declares LinkedList class
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <ListNode.h>

using namespace std;

template <class lNode>  // !!!! may want to shift this code around

class LinkedList {
    private:
        typename listNode<lNode>::nodeList* head; // !!!! may want to shift this code around
        typename listNode<lNode>::nodeList* tail; // !!!! may want to shift this code around
        int listSize;

    public:
        //constructor
        LinkedList();
        LinkedList(nodeList*, nodeList*, int);

        //destructor
        ~LinkedList();

        //function prototypes
        void addTo();
        void removeFrom();
        void getFrom();

        //getter
        int getListSize();

        //setter
        void setListSize();

        //friend function prototypes
        void sortList();
        friend ostream& operator<<(ostream& os, const LinkedList& linkedlist);
};

#endif