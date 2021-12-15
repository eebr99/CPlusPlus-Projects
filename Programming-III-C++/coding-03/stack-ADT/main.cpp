/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
	
	Data myData;

    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */
	 
    if(stack.isEmpty())
        std::cout << "Stack is empty" << std::endl;

    if (!stack.peek(&myData))
		std::cout << "There is nothing to peek" << std::endl;
	
	if(!stack.pop(&myData))
		std::cout << "There is nothing to pop" << std::endl;
    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack.
     */
    for (int i = 0; i < number_test_cases; i++) {  //loop to push stuff onto stack
		stack.push(ids[i], data[i]); // if my push was working, after every push
		                           //would run the other functions and display info
	    if(stack.isEmpty())
            std::cout << "Stack is empty" << std::endl;
		else
			std::cout << "stack is not empty" << std::endl;

        if (!stack.peek(&myData))
		    std::cout << "There is nothing to peek" << std::endl;
		else
			std::cout << "There is something to peek" << std::endl;
	
	    if(!stack.pop(&myData))
		    std::cout << "There is nothing to pop" << std::endl;
		else
			std::cout << "There is something to pop" << std::endl;
		
		std::cout << myData.id << " " << myData.data << std::endl;
	
	}
    for (int i = 0; i < number_test_cases; i++) { //loop to pop stuff out of stack
		stack.pop(&myData); //if pop was working, it would pop, then check to see if 
		                    //empty and if it can peek
		
	    if(stack.isEmpty())
            std::cout << "Stack is empty" << std::endl;
		else
			std::cout << "stack is not empty" << std::endl;

        if (!stack.peek(&myData))
		    std::cout << "There is nothing to peek" << std::endl;
		else
			std::cout << "There is something to peek" << std::endl;
        
		std::cout << myData.id << " " << myData.data << std::endl;

	}

    return 0;
}
