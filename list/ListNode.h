//
// Created by kudry on 27.05.17.
//

#ifndef LIST_LISTNODE_H
#define LIST_LISTNODE_H

template <class T>
class ListNode {
public:

    ListNode(const T &value){
        data = value;
        next = nullptr;
    }

    ~ListNode(){};


    void setData(const T &value){
        data = value;
    }

    T &getData(){
        return data;
    }

    ListNode<T> *getNext(){
        return next;
    }

    void setNext(ListNode<T> *ptr){
        next = ptr;
    }
private:
    T data;
    ListNode<T> *next;
};


#endif //LIST_LISTNODE_H
