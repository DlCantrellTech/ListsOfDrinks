/*  Tilte: ListNode.h
 *  Author: Dalton Cantrell
 *  Date: 10/23/24
 *  Purpose: Declares LinkedList class
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "ListNode.h"
#include "Drink.h"
#include "Recipe.h"

using namespace std;

template <typename typNode>
class LinkedList {
    private:
        ListNode<typNode> *head;
        ListNode<typNode> *tail;
        int listSize;

    public:
        //constructors
        LinkedList();
        LinkedList(ListNode<typNode>*, ListNode<typNode>*, int);

        //destructor
        ~LinkedList();

        //function prototypes
        void addTo(typNode* value);
        void removeFrom();
        void getFrom();
        void readIn();
        //void makeNew();

        //getter
        int getListSize();

        //setter
        void setListSize();

        //friend function prototypes
        template <typename T>
        friend ostream& operator<<(ostream&, const LinkedList<T>&);
        template <typename T>
        friend void sortList(LinkedList<T>&, int);

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

        Iterator begin() {return Iterator(head);}

        Iterator end() {return Iterator(tail);}

        void remove(Iterator);
};

#endif