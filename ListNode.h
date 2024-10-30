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
        struct NodeCell
        {
            typNode value;
            NodeCell *prev;
            NodeCell *next;

            //Constructor for NodeCell 
            NodeCell (typNode val, typNode *P = nullptr, typNode *N = nullptr): value(val), prev(P),next(N)
            {
                if(P) prev->next = this;
                if(N) next->prev = this;
            } 
        };
        
        NodeCell *current; //current node pointer
        int size;
    
    public:

    //Constructor and Deconstrtuctor 
    ListNode();
    ~ListNode();

    //Iterators
    typNode nextNode();
    typNode prevNode();
    
    //Deletes the current node
    void deleteCurrent()

    //Getters
    typNode getPrev();
    typNode getNext();
    typNode getCurrent();

    //Setters
    void setCurrent(NodeCell *node);
    void setPrev(NodeCell *node);
    void setNext(NodeCell *node);

}; 
#endif //LISTNODE_H