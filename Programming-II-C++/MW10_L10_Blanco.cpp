// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 10
// Topic: This program uses memory as shown in the memory diagram provided and
// sets the values of all variable indirectly using pointers wherever possible.
// The goal is to create pointer variables, value variables, and set them up as
// in the diagram.
#include <iostream>
#include <iomanip>
using namespace std;

class Person {
	public:
    string name{};     // name of the person
    Person *next{nullptr};    // pointer to the next person in the list
};

// Helpful macros to make it easier to output name, address, and value of a variable
// You may use these, or write your own function that does something similar
#define show_addr_value(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<"  "     \
      <<"contents of "<<setw(width)<<left<<#var<<" is: "<<var<<endl;

#define show_addr(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<&var<<endl;

int main () {
  cout << "Output from Lab10 memory diagram on pointers:\n\n";
  
  float price = 0;
  float *p_price = &price;  
  *p_price = 19.95;
  show_addr_value(price, 8);
  show_addr_value(p_price, 8);
  cout << "The contents of *p_price is: " << *p_price << endl << endl;

 // /* Output comments, formats results, use as desired.
  double PI{0}, PI_div_2{0};  // intitalze both PI
  double *p_PI = &PI;           //set pointer to address
  *p_PI = 3.141592;
  PI_div_2 = *p_PI / 2;    // using pointer instead of just the number
  show_addr_value(PI, 8);
  show_addr_value(PI_div_2, 8);
  show_addr_value(p_PI, 8);
	cout << "The contents of *p_PI is:    " << *p_PI << endl << endl;
	
	int maxSize{0};
	int *p_size = &maxSize;  //very simlilar process to above with PI
	*p_size = 5028;
	show_addr_value(maxSize, 8);
	show_addr_value(p_size, 8);
	cout << "The contents of *p_size is:  " << *p_size << endl << endl;
	
	int *p_amount{nullptr};
	p_amount = new int(1234);   //dynamic allocation of memory
	show_addr_value(p_amount, 8);
  cout << "The contents of *p_amount is: " << (dec) << *p_amount << endl;
  delete [] p_amount;  // preventing memory leaks
  cout << "After delete, the contents of p_amount is: " << p_amount << endl;
  p_amount = nullptr; // reseting
  cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << endl
	                                                                            <<endl;
	int amount{11};
	int *pArray{nullptr};  //similar to above with dynamic memory allocation
	pArray = new int[3];   // this time using an array
	show_addr_value(pArray, 8);
	for(int count = 0; count < 3; count++){  // use loop to simplfy code
		*(pArray + count) = amount;
		amount += 11;	
	}
	show_addr_value(pArray[0], 8);  // show for each 
	show_addr_value(pArray[1], 8);
	show_addr_value(pArray[2], 8);
	delete [] pArray;  // clean up code to prevent leak
	cout << "After delete [], the contents of pArray is: " << pArray << endl;
  pArray = nullptr;  //reset
	cout << "After reset to nullptr, the contents of pArray is: " << pArray << endl
                                                                      << endl;
	Person *emptyList{nullptr};  // empty list 
	emptyList = 0;
	show_addr_value(emptyList, 8);
	cout << endl;
	
	cout<<"stack allocation (uses: Person wizard):\n";
  Person Wizard;  // creating Person object;
  Wizard.name = "Gandalf";
  cout << "address of wizard is: " << &Wizard << endl;
  show_addr_value(Wizard.name, 8);
  show_addr_value(Wizard.next, 8);
  cout << endl;
  
	cout<<"heap allocation (uses: personList, Person(\"Harry\"), Person(\"Sally\"):\n";
  Person *personList{nullptr};  // trying to create a linked list
  personList = new Person[2];  // memory allocation
  show_addr_value(personList, 8);
	personList->name = "Harry";
	show_addr_value(personList->name, 8);
	personList->next = personList;
	show_addr_value(personList->next, 8);
	cout << "  <follow link to next Person on personList>\n";	
	personList->next->name = "Sally";
	show_addr_value(personList->next->name, 8);
	show_addr_value(personList->next->next, 8);
	delete [] personList; // stop leak
	personList = nullptr; // reset
 
  return 0;
} // end of main

/*
Output from Lab10 memory diagram on pointers:

address of price    is: &0x70fdf4  contents of price    is: 19.95
address of p_price  is: &0x70fde8  contents of p_price  is: 0x70fdf4
The contents of *p_price is: 19.95

address of PI       is: &0x70fde0  contents of PI       is: 3.14159
address of PI_div_2 is: &0x70fdd8  contents of PI_div_2 is: 1.5708
address of p_PI     is: &0x70fdd0  contents of p_PI     is: 0x70fde0
The contents of *p_PI is:    3.14159

address of maxSize  is: &0x70fdcc  contents of maxSize  is: 5028
address of p_size   is: &0x70fdc0  contents of p_size   is: 0x70fdcc
The contents of *p_size is:  5028

address of p_amount is: &0x70fdb8  contents of p_amount is: 0xb61860
The contents of *p_amount is: 1234
After delete, the contents of p_amount is: 0xb61860
After reset to nullptr, the contents of p_amount is: 0

address of pArray   is: &0x70fdb0  contents of pArray   is: 0xb61860
address of pArray[0] is: &0xb61860  contents of pArray[0] is: 11
address of pArray[1] is: &0xb61864  contents of pArray[1] is: 22
address of pArray[2] is: &0xb61868  contents of pArray[2] is: 33
After delete [], the contents of pArray is: 0xb61860
After reset to nullptr, the contents of pArray is: 0

address of emptyList is: &0x70fda8  contents of emptyList is: 0

stack allocation (uses: Person wizard):
address of wizard is: 0x70fd90
address of Wizard.name is: &0x70fd90  contents of Wizard.name is: Gandalf
address of Wizard.next is: &0x70fd98  contents of Wizard.next is: 0

heap allocation (uses: personList, Person("Harry"), Person("Sally"):
address of personList is: &0x70fd88  contents of personList is: 0xb61548
address of personList->name is: &0xb61548  contents of personList->name is: Harry
address of personList->next is: &0xb61550  contents of personList->next is: 0xb61548
  <follow link to next Person on personList>
address of personList->next->name is: &0xb61548  contents of personList->next->name is: Sally
address of personList->next->next is: &0xb61550  contents of personList->next->next is: 0xb61548

--------------------------------
Process exited after 0.1551 seconds with return value 0
Press any key to continue . . .
*/
