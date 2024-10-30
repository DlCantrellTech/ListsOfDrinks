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

            ListNode (typNode *P,typNode *N): prev(P),next(N)
            {
                if(P) prev->next = this;
                if(N) next->prev = this;
            } 
        };
        
    public:

    listNode(lNode);

    ~listNode();

    typNode *current;
    int size;
    void out(bool);
    void setCurrent(lNode);
    void setPrev(typNode*);
    void setNext(typNode*);
    bool findCurrent(lNode);
    void deleteCurrent(lNode, bool)

    typNode getPrev();
    typNode getNext();
    typNode getCurrent();

    typNode setPrev();
    typNode setNext();
    typNode setCurrent();

}; 
#endif //LISTNODE_H