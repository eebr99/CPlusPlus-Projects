/*********************
Name: Eric Blanco
Coding 06
Purpose: Implementation of BST class 
*********************/

#include "bintree.h"
#include <iostream>
#include <algorithm>

//private methods:
void BinTree::clear(DataNode* temproot){
    if(temproot){
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = NULL;
        temproot->right = NULL;
        //delete temproot;
        count--;
    }
}

bool BinTree::addNode(DataNode* newNode, DataNode** rootptr){
    bool okay = false;
    if(!(*rootptr)){
        *rootptr = newNode;
        okay = true;
    } else {
        if(newNode->data.id < (*rootptr)->data.id)
            okay = addNode(newNode, &(*rootptr)->left);
        else if (newNode->data.id > (*rootptr)->data.id)
            okay = addNode(newNode, &(*rootptr)->right);
    }
    return okay;
}

DataNode* BinTree::removeNode(int id, DataNode* temproot){
    if(temproot){
        if(id < temproot->data.id)
            temproot->left = removeNode(id, temproot->left);
        else if(id > temproot->data.id)
            temproot->right = removeNode(id, temproot->right);
        else{
            DataNode *temp;
            if(temproot->left == NULL){
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                count--;
            }
            else if(temproot->right == NULL){
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;
            }
            else{
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }
    return temproot;
}

bool BinTree::getNode(Data* node, int id, DataNode* temproot){
    int found = false;

    if (temproot) {
        if (temproot->data.id == id) {
            node->id = temproot->data.id;
            node->information = temproot->data.information;
            found = true;
        } else if (id < temproot->data.id) {
            found = getNode(node, id, temproot->left);
        } else {
            found = getNode(node, id, temproot->right);
        }

    }
    return found;
}

bool BinTree::contains(int id, DataNode *temproot) {
    int found = false;

    if (temproot) {
        if (temproot->data.id == id) {
            found = true;
        } else if (id < temproot->data.id) {
            found = contains(id, temproot->left);
        } else {
            found = contains(id, temproot->right);
        }

    }
    return found;
}

int BinTree::getHeight(DataNode* temproot){
    int lh=0, rh=0;
    if(!temproot){return 0;}
    else if(temproot){
        lh = getHeight(temproot->left);
        rh = getHeight(temproot->right);
    }
    return std::max(lh, rh) + 1;
}

void BinTree::displayPreOrder(DataNode* temproot){
    if (temproot) {
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;        
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }

    return;
}

void BinTree::displayPostOrder(DataNode* temproot){
    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
    }

    return;
}

void BinTree::displayInOrder(DataNode* temproot){
    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }

    return;
}

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
//*********************************************************

//constructor and destructor:
BinTree::BinTree(){
    root = NULL;
    count = 0;
}

BinTree::~BinTree(){
    clear();
}
//*********************************************************

//public methods:
bool BinTree::isEmpty(){
    bool okay = false;
    if(!root)
        okay = true;
    return okay;
}

int BinTree::getCount(){
    return count;
}

bool BinTree::getRootData(Data* node){
    bool okay = false;
    if(root){
    node->id = root->data.id;
    node->information = root->data.information;
    okay = true;
    }
    return okay;
}

void BinTree::displayTree(){
    std::cout << "\nDISPLAY TREE" << std::endl;
    std::cout << "==============================================" << std::endl;
    if(isEmpty())
        std::cout << "Tree is empty" << std::endl;
    else
        std::cout << "Tree is NOT empty" << std::endl;
    std::cout << "Height " << getHeight() << std::endl;
    std::cout << "Node count: " << getCount() << std::endl;
    std::cout << "\nPre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << "\nIn-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << "\nPost-Order Traversal" << std::endl;
    displayPostOrder();
    std::cout << "==============================================" << std::endl <<std::endl;

}

void BinTree::clear(){
    clear(root);
}

bool BinTree::addNode(int id, string data){
    bool okay = false;
    if((id > 0) && (data != "")){
        DataNode* newNode;
        newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = data;
        if(addNode(newNode, &root))
            //count++;
            okay = true;
    }
    count++;
    return okay;
}

bool BinTree::removeNode(int id){
    bool okay = false;
    int tempcount = count;
    root = removeNode(id, root);
    if(count < tempcount)
        okay = true;
    return okay;
}

bool BinTree::getNode(Data* node, int id){
    bool okay = false;
    if(id > 0){
        if(getNode(node, id, root));
            okay = true;
    }
    return okay;
}

bool BinTree::contains(int id){
    bool okay = false;
    if(id > 0){
        if(contains(id, root))
            okay = true;
    }
    return okay;
}

int BinTree::getHeight(){
    return getHeight(root);
}

void BinTree::displayPreOrder(){
    displayPreOrder(root);   
}

void BinTree::displayPostOrder(){
    displayPostOrder(root);
}

void BinTree::displayInOrder(){
    displayInOrder(root);
}
//*********************************************************