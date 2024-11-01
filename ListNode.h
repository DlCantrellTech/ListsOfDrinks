/*  Title: ListNode.h
 *  Author: Brody Mensonides
 *  Date: 10/30/24
 *  Purpose: Declares ListNode Class 
 */
#ifndef LISTNODE_H
#define LISTNODE_H

#include "Drink.h"
#include "Recipe.h"

using namespace std;

template <typename typNode>

class ListNode
{
    private:
        typNode* value;
        ListNode* prev;
        ListNode* next;
    
    public:

    //Constructor and Deconstrtuctor 
    ListNode(typNode* value);
    ~ListNode();

    //Iterators
    typNode nextNode();
    typNode prevNode();
    
    //Deletes the current node
    void deleteCurrent();

    //Getters
    ListNode<typNode>* getPrev();
    ListNode<typNode>* getNext();
    typNode& getValue();
    ListNode<typNode>* getCurrent();

    //Setters
    void setValue(typNode value);
    void setPrev(ListNode *node);
    void setNext(ListNode *node);

}; 

//Constructor 
template <typename typNode>
ListNode<typNode>::ListNode(typNode* value)
{
    this->value = value;
    this->prev = nullptr;
    this->next = nullptr;
}

//Deconstructor
template <typename typNode>
ListNode<typNode>::~ListNode()
{
    delete value;
}

template <typename typNode>
ListNode<typNode>* ListNode<typNode>::getNext() {
    return next;
}

template <typename typNode>
ListNode<typNode>* ListNode<typNode>::getPrev() {
    return prev;
}

template <typename typNode>
typNode& ListNode<typNode>::getValue() {
   return *value;
}

template <typename typNode>
void ListNode<typNode>::setNext(ListNode<typNode>* node) {
    next = node;
}

template <typename typNode>
void ListNode<typNode>::setPrev(ListNode<typNode>* node) {
    prev = node;
}



#endif //LISTNODE_H