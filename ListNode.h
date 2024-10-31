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
    ListNode(typNode value, NodeCell *prev, NodeCell *next);
    ~ListNode();

    //Iterators
    typNode nextNode();
    typNode prevNode();
    
    //Deletes the current node
    void deleteCurrent();

    //Getters
    ListNode<typNode>* getPrev();
    ListNode<typNode>* getNext();
    typNode* getValue();
    ListNode<typNode>* getCurrent();

    //Setters
    void setValue(typNode value);
    void setPrev(NodeCell *node);
    void setNext(NodeCell *node);

}; 

#endif //LISTNODE_H