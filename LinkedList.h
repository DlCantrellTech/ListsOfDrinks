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

template <typename typNode>

class LinkedList {
    private:
        typename ListNode<typNode>::NodeCell *head;
        typename ListNode<typNode>::NodeCell *tail;
        int listSize;

    public:
        //constructors
        LinkedList();
        LinkedList(typename ListNode<typNode>::NodeCell*, typename ListNode<typNode>::NodeCell*, int);

        //destructor
        ~LinkedList();

        //function prototypes
        void addTo(typNode value);
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