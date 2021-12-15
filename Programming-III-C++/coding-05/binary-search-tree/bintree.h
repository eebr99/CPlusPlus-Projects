/*********************
Name: Eric Blanco
Coding 06
Purpose: Building the BST class
*********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include "data.h"

class BinTree {

    private:
        DataNode *root;
        int count;

        //private methods:
        void clear(DataNode*);
        bool addNode(DataNode*, DataNode**);
        DataNode* removeNode(int, DataNode*);
        bool getNode(Data*, int, DataNode*);
        bool contains(int, DataNode*);
        int getHeight(DataNode*);
        void displayPreOrder(DataNode*);
        void displayPostOrder(DataNode*);
        void displayInOrder(DataNode*);
        DataNode* minValueNode(DataNode*);


    public:
        BinTree();
        ~BinTree();
        bool isEmpty();
        int getCount();
        bool getRootData(Data*);
        void displayTree();


        //methods that require private functions:
        void clear();
        bool addNode(int, string);
        bool removeNode(int);
        bool getNode(Data*, int);
        bool contains(int);
        int getHeight();
        void displayPreOrder();
        void displayPostOrder();
        void displayInOrder();
};






#endif /* BINTREE_BINTREE_H */

