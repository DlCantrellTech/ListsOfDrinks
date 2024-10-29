#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class LinkedList {
    private:
        // head node pointer
        // tail node pointer
       int listSize;

    public:
        //constructor
        LinkedList();
        LinkedList(/*head pointer data type*/,/*tail pointer data type*/, int);

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