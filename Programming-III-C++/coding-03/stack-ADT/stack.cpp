/*********************
Name: Eric Blanco
Coding 02
Purpose: To create a stack of integers.
**********************/

// each cpp includes ONLY it's header directly
#include "stack.h"
/*
 * write all your stack methods here
 */
 
Stack::Stack(){//constructor
    this->top = -1;
}
 
Stack::~Stack(){ 
	/*for(int i=0; i<= STACK_SIZE; i++){
		stack[i]->id = -1;
		stack[i]->data = "";
	} */
} //destructor to clear the stack
 
bool Stack::push(int id, string data){
    bool okay = false;

    if(top < (STACK_SIZE - 1)){
		Data *myData;
		myData = new Data;
		myData->id = id;
		myData->data = data;
		stack[++top] = myData;
		okay = true; 
	}
	return okay;
}
 
bool Stack::pop(Data *data){
	bool okay = false;
	 
	if(top < 0){
		data->id = -1;
		data->data = "";
	}
	else{
		data->id = stack[top]->id;
		data->data = stack[top]->data;
		//delete Data; 
		//when i try to do above I get, "parse error before ';'"
        stack[top--];
		okay = true;
	}
	 
	return okay;
}
 
bool Stack::peek(Data *data){
 
    bool okay = false;
	 
	    if(top < 0){
		    data->id = -1;
		    data->data = "";
	    }
	    else{
		    data->id = stack[top]->id;
		    data->data = stack[top]->data;
		    //delete Data;  same problem as in pop()
            okay = true;
	    }
	 
	return okay;
}
 
bool Stack::isEmpty(){
    bool empty = false;
	
	if(top = -1)
		empty = true;
	
	return empty;
}