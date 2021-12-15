/*********************
Name: Eric Blanco
Coding 04
Purpose: Implementation of my linked list class
*********************/
#include "linkedlist.h"
#include <iostream>

//private member functions
    char dLinkedList::getCase(int id){
        char node_case = 'c'; // c stands for "case"
        if( (head->prev == NULL) && (id < head->data.id) )
            node_case = 'h'; //h is for "head" case
        else if( (id > head->data.id) && (id < head->next->data.id) )
            node_case = 'm'; //m is for "mid" or general case
        else if( (id > head->data.id) && (head->next == NULL) )
            node_case = 't'; //t is for "tail" case

        return node_case;
    }
    //add helpers
    bool dLinkedList::addHead(Node* newNode){
        //this function adds a new "head" to the linked list
        bool okay = false;

        head->prev = newNode; 
        // the prev pointer for head is now pointing to the newNode
        
        newNode->next = head; 
        // the next pointer for the newNode points to head now
        
        newNode->prev = NULL; 
        //the prev pointer for the newNode is NULL b/c it is
        // the new "head", therefore there is nothing before it in the list.
        
        head = newNode;
        // head pointer now points to newNode, since newNode is now the "head"
        // visually, this is the end result: (head) -> (newNode)
        //                                                 ^
        //new                                 (1st item in list, or "head")
        okay = true;
        return okay;
    }
    bool dLinkedList::addMiddle(Node* newNode, Node* current){
        //this function adds a node to the linked list between two other nodes
        bool okay = false;
        //Before we detach, we need to attach the new node to the list
        newNode->next = current;
        /*the new node's next pointer is linked to the current node
            Basically, if we were entering a node with id 5, and the nodes
        we have are 3, 7, and 9, we are trying to enter the node with id 5
        in between 3 and 7. In this case, 7 would be the "current" node. */
        
        newNode->prev = current->prev;
        /* the new node's prev pointer is set to the current node's prev 
        pointer.  The new node is now attached to the list. Now we begin
        to detach the link that was there before the new node came. */

        current->prev->next = newNode;
        /*basically, the previous node, the one before the current node and
        now before the new node, has its prev pointer set to point to the new
        node now, instead of pointing to current. */

        current->prev = newNode;
        /*current's prev pointer now points to the new node, instead of the 
        previous node. With this, the old link between nodes is gone.
        The list from before would now be 3, 5, 7, 9. */

        //visually: (head) -> (previous) -> (newNode) -> (current)
        //                                      ^
        //           (newNode was successfully added in between)
        okay = true;
        return okay;
    }
    bool dLinkedList::addTail(Node* newNode, Node* current){
        //this function adds a new tail to the linked list
        bool okay = false;
        newNode->next = NULL;
        /* the new node's next pointer is set to NULL because we are adding a
        tail. This means that there is nothing after the new node, so it points
        to nothing. */

        newNode->prev = current;
        // the new node's prev pointer points to the current node

        current->next = newNode;
        /* before new node came along, current was the tail of the list.
        But, since the new node is now the tail, current's next pointer
        must point to the new node. */

        //visually: (head) -> (node) -> (node) -> (current) -> (newNode)
        //                                                        ^
        //                                  (newNode is now the new tail)
        okay = true;
        return okay;
    }

    //delete helpers
    bool dLinkedList::deleteHead(Node* current){
        //this function deletes the node that is currently the "head"
        bool okay = false;
        //for example, we have list 3,5,7,9. We are trying to detach 3.
        
        head = current->next;
        /*head is set to current's next, which means that, similar to the
        add head method, where head is set to the new node, here we set
        head to the node after the current node, since we are making 
        that the new head. head now points to 5 instead of 3. */ 

        current->next->prev = NULL;
        /*current's next's prev pointer is set to NULL because current 
        will no longer be the "head," the node after current will be 
        the new "head", which means that its prev pointer must point 
        to NULL, since there is nothing in a list before the "head" */
        
        delete current;
        //before: head -> (3) -> (5) -> (7) -> (9)
        //after: head -> (5) -> (7) -> (9)    (3) is now detached and deleted
        okay = true;
        return okay;
    }
    bool dLinkedList::deleteMiddle(Node* current){
        //this function detaches a node that is between two other nodes
        bool okay = false;
        //for example, we have list 3,5,7,9. We are trying to detach 5.
        
        current->prev->next = current->next;
        /*current's prev's next pointer is set to current's next pointer.
        But, what is going on with regards to the list is that after this
        code, the node before current's next pointer is now pointing to 
        the node after current. This detaches current from being "after"
        the node before it and attaches the one after current. 3's next
        points to 7 instead of 5 now.*/

        current->next->prev = current->prev;
        /*current's next's prev pointer is set to current's prev pointer.
        What is happening though is that the node after current's prev pointer
        is now pointing to the node before current. This detaches current from
        being "before" the node after it and attaches the one before current.
        7's prev points to 3 instead of 5 now.*/
        
        delete current;
        //before: head -> (3) -> (5) -> (7) -> (9)
        //after:  head -> (3) -> (7) -> (9)       (5) is now detached and deleted.
        okay = true;
        return okay;
    }
    bool dLinkedList::deleteTail(Node* current){
        //this function deletes the "tail" in a linked list
        bool okay = false;
        
        current->prev->next = NULL;
        /*current's prev' next is set to null. What is happening in the 
        list is that since we are deleting the tail, which is current in
        this case, we have to make the node before current the new tail,
        and all tail's prev pointer's are set to null, since there is
        nothing after a tail. 7 is now the last number in the list. */
        
        delete current;
        //before: head -> (3) -> (5) -> (7) -> (9)
        //after:  head -> (3) -> (5) -> (7)  (9) is now detached and deleted 
        okay = true;
        return okay;
    }


//constructor and destructor
dLinkedList::dLinkedList(){
    head = NULL;
}

dLinkedList::~dLinkedList(){
    clearList();
}

//public member functions
bool dLinkedList::addNode(int id, string data){
    bool okay = false;
    if (head){ //we check to see if there is something in the list
        Node* current = head; //setting current to head
        if((id >= 0) && (id != current->data.id)){ //Now we are checking for valid data
            Node* beforeCurrent = NULL;
            Node* newNode;  //We are allocating the new node
            newNode = new Node;
            while(current && id > current->data.id){ //next we are finding our position in the list
                beforeCurrent = current;
                current = current->next;            
            }
            char type;//getCase(id); //getCase causes error when running
            switch (type){  //Finally, with above helper function, we find out
            case 'h':          //what "case" we are dealing with and call the 
                //addHead(newNode);    //appropriate helper function.
                break;
            case 'm':
                //addMiddle(newNode, current);
                break;
            case 't':
                //addTail(newNode, current);
                break;
            default:
                break;
    
            }
        }    
    }else{/*addHead(newNode);*/}
    okay = true;
    return okay;
} 

bool dLinkedList::deleteNode(int id){
    //this function determines what kind of node we are dealing with
    // and deletes the appropriate node.
    bool okay = false;
    //first we check if the id exists and for position
    Node* current = head;
    Node* beforeCurrent = NULL;
    while(current && id > current->data.id){
        beforeCurrent = current;
        current = current->next;
        if(id == current->data.id){
            char type; // = getCase(id);
            switch (type){  //with above helper function, we find out
            case 'h':          //what "case" we are dealing with and call the 
                //deleteHead(current);    //appropriate helper function.
                break;
            case 'm':
                //deleteMiddle(current);
                break;
            case 't':
                //deleteTail(current);
                break;
            default:
                break;
    
            }
            //the data allocated in addNode() would be de-allocated here.
            okay = true;
        }
    }
    return okay;
}

bool dLinkedList::getNode(int id, Data *data){
    //this function will get a node and "return" it
    bool okay = false;
    //we begin at the head
    Node* current = head;
    Node* beforeCurrent = NULL;
    //then we compare the id to the current node
    while(current && id > current->data.id){
        beforeCurrent = current;
        current = current->next;
        //now we check if it is the id we want
        if(id == current->data.id){
            //we now fill the "empty" node that was passed
            data->data = current->data.data;
            data->id = current->data.id;
            okay = true;
        }else{
            data->data = " ";
            data->id = -1;
        }
    }
    return okay;
}

void dLinkedList::printList(bool printBackward){ //bool passed in
//this program will print the linked list.
    //first we begin at the head and determine if the list exists
    if(head){
        //then we use our bool printBackward in a way that determines
        //how to print the list
        
        //next we print out the head id and data
        Node* current = head;
        Node* beforeCurrent = NULL;
        std::cout << current->data.id << " " << current->data.data << std::endl;
        while(current){
            beforeCurrent = current;
            current = current->next;
        //then we traverse and print out the list as we go
            while(current = current->next){
                std::cout << current->data.id << " " << current->data.data << std::endl;

            }
        }
    
    }
}

int dLinkedList::getCount(){
//this function gets the count of nodes in the list
    int count = 0; //our counter for the number of nodes
    //we begin at the head
    if(head){
        Node* current = head;
        Node* beforeCurrent = NULL;
        //Now we traverse the list and count
        while(current){
            beforeCurrent = current;
            current = current->next;

            while(current = current->next){
                count++;
            }
        }
    }
    return count;
}

bool dLinkedList::clearList(){
// this function will clear the list by deleting the head again and again
    bool okay = false;

    //begin at the head
    if(head){
        Node* current = head;
        deleteNode(current->data.id); //head is deleted
        while(current = current->next){
            deleteNode(current->data.id); //traverse and delete heads
        }
        okay = true;
    }
    return okay;
}

bool dLinkedList::exists(int id){
//this function checks to see if a node exists
    bool okay = false;
    if(head){ //checks to see if exists
        //now checking if specific id passed through exists
        Node* current = head;
        Node* beforeCurrent = NULL;
        while(current && id > current->data.id){ //traversing
            beforeCurrent = current;
            current = current->next;

            if(id = current->data.id) //if id exists, change okay to true
                okay = true;
        }
    }
    return okay;
}