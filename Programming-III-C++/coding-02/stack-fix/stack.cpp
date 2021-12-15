/*********************
Name: Eric Blanco
Coding 02
Purpose: To create a stack of integers.
**********************/

#include "stack.h"
 

Stack::Stack(){
	top = -1;
}

bool Stack::push(int x){
	if(top >= SIZE - 1) //former bug, array count begins at 0
		return false;
	else{
		a[++top] = x;
		return true;
    }
}

int Stack::pop(){
	if(top < 0)
		throw -1;
		
    else
		return a[top--];
}

bool Stack::isEmpty(){
	if(top < 0)
		return true;
	else
		return false;
}

int Stack::peek(){
	if(top < 0)
		throw -1;
	else
		return a[top];
}	
