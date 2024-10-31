#include "ListNode.h"

//Constructor 
template <typename typNode>
ListNode<typNode>::ListNode(typNode value, NodeCell *prev, NodeCell *next)
{
    this->value = value;
    this->prev = prev;
    this->next = next;
}

//Deconstructor
template <typename typNode>
ListNode<typNode>::~ListNode()
{
    while (current)
    {
        deleteCurrent();
    }
}

//Iterators
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
        return typNode; //Returns the default value if no next node
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
        return typNode(); //Returns default value if no previous node
    }
}