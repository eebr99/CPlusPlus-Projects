/*********************
Name: Eric Blanco
Coding 02
Purpose: To test the integer stack and its methods extensively.
**********************/
#include "main.h"

int main() {

    Stack s1;
	int num = 10;
	srand(time(NULL));
	
	//checking if the stack is empty or not
    displayEmpty(&s1); 
	//trying to peek while empty
	try{
		s1.peek();
	}catch (int e) {
		std::cout << "There is nothing to peek at." << std::endl;
	}
	
    //filling the stack, trying to overflow and see results
    for(int i=1; i<=15; i++){
		if(s1.push(num))
			std::cout << "\n" << s1.peek() << " is on top" << std::endl;
        else{
			std::cout << "\nThe stack is full, with " << s1.peek() 
		              << " on top" << std::endl;
		    }
		displayEmpty(&s1); //check if stack is empty 
		num = (rand() % 100 + 1); //num is random
	}
	
	//now stack is being emptied out
	for(int i=1; i<=15; i++){
        try{
			s1.pop();
			std::cout << "\n" << s1.peek() << " is on top" << std::endl;
		    displayEmpty(&s1); //check empty 


		}catch (int e){
		//exception is handled
		    std::cout << "\nThe error thrown is: " << e << std::endl;
			displayEmpty(&s1); //checking again
		    std::cout << "There is nothing to pop" << std::endl;
        }	
	}   
   //peeking after being emptied out
    try{
		s1.peek();
	}catch (int e) {
		std::cout << "There is nothing to peek at." << std::endl;
	}
	return 0;
}
