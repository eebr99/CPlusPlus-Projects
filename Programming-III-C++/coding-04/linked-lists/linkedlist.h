/*********************
Name: Eric Blanco
Coding 04
Purpose: To build the linked list class
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
class dLinkedList{

    private:
        Node *head;
        
        //private member functions
        char getCase(int);

        bool addHead(Node*);
        bool addMiddle(Node*, Node*);
        bool addTail(Node*, Node*);

        bool deleteHead(Node*);
        bool deleteMiddle(Node*);
        bool deleteTail(Node*);

    public:
        dLinkedList(); //constructor prototype
        ~dLinkedList(); //destructor prototype
        
        bool addNode(int, string);
        bool deleteNode(int);
        bool getNode(int, Data*);
        void printList(bool=false);
        int getCount();
        bool clearList();
        bool exists(int);

};

#endif //LINKEDLIST_H