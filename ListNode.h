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

    nodeList *current;
    int size;
    void out(bool);
    void setCurrent(lNode);
    void setPrev(nodeList*);
    void setNext(nodeList*);
    bool findCurrent(lNode);
    void deleteCurrent(lNode, bool)

    nodeList getPrev();
    nodeList getNext();
    nodeList getCurrent();

    nodeList setPrev();
    nodeList setNext();
    nodeList setCurrent();

}; 
#endif //LISTNODE_H