#include "ListNode.h"
#include "Drink.h"
#include "Recipe.h"

//Constructor 
template <typename typNode>
ListNode<typNode>::ListNode(typNode* value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

//Deconstructor
template <typename typNode>
ListNode<typNode>::~ListNode()
{
    delete value;
}

//Iterators
/*
template <typename typNode>
typNode ListNode<typNode>::nextNode()
{
    if(current && current->next) //checks for current and next node
    {
        current = current->next; //iterates current to next
        return current->value; //Returns new current value
    }
    else
    {
        //return typNode; //Returns the default value if no next node
    }
}

template <typename typNode>
typNode ListNode<typNode>::prevNode()
{
    if(current && current->prev) //Checks for current and previous node
    {
        current = current->prev; //Iterates to previous node
        return current->value; //Returns new current value
    }
    else
    {
        //return typNode(); //Returns default value if no previous node
    }
}*/

template <typename typNode>
ListNode<typNode>* ListNode<typNode>::getNext() {
    return next;
}

template <typename typNode>
ListNode<typNode>* ListNode<typNode>::getPrev() {
    return prev;
}

//template <typename typNode>
//ListNode<typNode>& ListNode<typNode>::getValue() {
//    return *value;
//}

template <typename typNode>
void ListNode<typNode>::setNext(ListNode<typNode>* node) {
    next = node;
}

template <typename typNode>
void ListNode<typNode>::setPrev(ListNode<typNode>* node) {
    prev = node;
}

template class ListNode<Drink>;