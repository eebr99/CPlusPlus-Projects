/*********************
Name: Eric Blanco
Coding 02
Purpose: Header file for stack.cpp. Creates the stack class and its necessary
prototypes.
**********************/

#ifndef CLASSES_STACK_H
#define CLASSES_STACK_H

const int SIZE = 10; //const int for the size of the array instead
                     // of a literal

class Stack {
	
	private:   
	    int top;
	    int a[SIZE]; 
	
	public:
	    // constructor
		Stack();
		
		//function prototypes
		bool push(int);
		int pop();
		bool isEmpty();
		int peek(); //renamed top() to peek(), to distinguish
		               //from the variable named top
					   
};

#endif //CLASSES_STACK_H