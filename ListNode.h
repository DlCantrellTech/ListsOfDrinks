/*  Title: ListNode.h
 *  Author: Brody Mensonides
 *  Date: 10/30/24
 *  Purpose: Declares ListNode Class 
 */
#ifndef LISTNODE_H
#define LISTNODE_H

using namespace std;

template <typename typNode>

class ListNode
{
    private:
        typNode* value;
        ListNode *prev;
        ListNode *next;
    
    public:

    //Constructor and Deconstrtuctor 
    ListNode(typNode*);
    ~ListNode();

    //Iterators
    typNode nextNode();
    typNode prevNode();
    
    //Deletes the current node
    void deleteCurrent();

    //Getters
    ListNode<typNode>* getPrev();
    ListNode<typNode>* getNext();
    typNode* getValue() {return value;}
    ListNode<typNode>* getCurrent();

    //Setters
    void setCurrent(ListNode*);
    void setPrev(ListNode<typNode>*);
    void setNext(ListNode<typNode>*);

}; 

#endif //LISTNODE_H