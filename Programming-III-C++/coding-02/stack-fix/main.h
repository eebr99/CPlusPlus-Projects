/*********************
Name: Eric Blanco
Coding 02
Purpose: This header file contains everything necessary to include 
in main.cpp.
**********************/

#ifndef MAIN_CLASSES_H
#define MAIN_CLASSES_H

#include <iostream>
#include <stdlib.h> //needed for rand() and srand()
#include <time.h> // needed for making "random" numbers
#include "stack.h"

//was using this method to check if the stack was empty 
//and then displaying that information in main.cpp, so I turned it into
//a function to cut back on repeated code, and  it cannot be in
//stack code, since class methods should not print
void displayEmpty(Stack *myStack){
	if(myStack->isEmpty())
		std::cout << "The stack is empty." << std::endl;
	else
		std::cout << "The stack is not empty." << std::endl;
}

#endif /* MAIN_CLASSES_H */