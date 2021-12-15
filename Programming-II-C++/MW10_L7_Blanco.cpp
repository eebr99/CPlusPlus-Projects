// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 7
// Topic: This program will create and implement a class Item by generating
// at least 4 different, separate instances of class Item.
/*
IPO Chart

INPUT
 name,     a string argument which is the name of the item
 ID,       an int argument which is the ID number of the item
 quantity, an int argument which is the number of item in stock
 cost,     a double argument which is the cost of the item 
PROCESSING
 create instance of class item with name, ID, quantity, and cost variables
 accept string argument and copy into name variable
 accept int argument and copy into ID variable ONLY if >= 0
 accept int argument and copy into quantity variable if >= 0
 accept double argument and cpy into cost variable if >= $0.00
 get name, ID, quantity, and cost of item object
 get cost of single item
 get total cost of all items in inventory
OUTPUT
display name, ID, quantity, and cost of item
display cost of single item and total cost of all items in stock
*/
// Compiler directives
#include <iostream> // for cin, cout, endl
#include <string>  // needed for strings
#include <iomanip>
using namespace std;

double get_input(string prompt, string errmsg){  // get input function
	while (true){
		cout << prompt;
		double input{};
		if (cin >> input){
			return input;
		}
		else{
			cout << errmsg << endl;
			cin.clear();
			cin.ignore(4095, '\n');
		}
	}
}

class Item {
  private:
    string name;  // private member functions
    int ID;
    int quantity;
    double cost;

  public:
	//default constructor  
    Item(){  
    	name = "";
    	ID = 0;      
    	quantity = 0;
    	cost = 0.0;
		}
		
	//constructor #2
		Item(string n, int i, int q, double c){//first letter of name, ID, etc.
			name = "Item";
			ID = 1234;
			quantity = 1;
			cost = 1.0;
		}
		
		// "setter" functions
		void set_name(string n){ // n is name
			cout << "\nPlease enter the item's name: ";
			getline(cin, name);  // getting the whole line instead of just one string
		}
		void set_ID(int i){
			string prompt = "Please enter the item's ID number: "; // i is ID
			string errmsg = "Sorry, please try again.";    // string arguments to be sent to get input function
			bool running = true;
			while (running){   // loop to validate
				ID = get_input(prompt, errmsg);
				if (ID >= 0)
					running = false;
				else
					cout << errmsg << endl;
			}
		}
		void set_quantity(int q){ // q is quantity
			string prompt = "Please enter the amount of the item in stock: ";
			string errmsg = "Sorry, please try again.";  //get input arguments
			bool running = true;
			while (running){  // validation loop
				quantity = get_input(prompt, errmsg);
				if (quantity >= 0)
					running = false;
				else
					cout << errmsg << endl;
			}
		}
		void set_cost(double c){ // c is cost
			string prompt = "Please enter the cost of the item: ";
			string errmsg = "Sorry, please try again.";  
			bool running = true;
			while (running){
				cost = get_input(prompt, errmsg);
				if (cost >= 0.00)
					running = false;
				else
					cout << errmsg << endl;
			}
		}
		
		//"getter" functions
		string get_name(){
			return name;
		}
		int get_ID(){
			return ID;  // vary simple functions, just return the value of the member
		}
		int get_quantity(){
			return quantity;
		}
		double get_cost(){
			return cost;
		}
		double get_total_cost(){
			return quantity * cost;
		}
    void display(){  // display the data
    	cout << "Name: " << name << "; ID: " << ID << "; Quantity: "
    	     << quantity << "; Cost: $" << setprecision (2) << fixed
					 << cost << "; Total Cost: $" << get_total_cost() << endl;
		}
};



int main() {
  const int MAX_INVENTORY{4};  // const int to create a max inventory
  cout << "This program will create up to " << MAX_INVENTORY
       << " items and display them to the user.\n";
  
	
	Item item[5]; // creating an array of 5 Item objects to easily loop later
	string name{};
	int id{}, quant{};
	double cost{};
	//int count{};
	
	for (int count = 1; count <= MAX_INVENTORY; count++){ // loop until max

		item[count].set_name(name);
		item[count].set_ID(id);
		item[count].set_quantity(quant);
		item[count].set_cost(cost);
	
		cout << "\nAccording to your entry, there are " << item[count].get_quantity()
		<< " " << item[count].get_name() << " with ID# " << item[count].get_ID() << 
		" at $" << setprecision (2) << fixed << item[count].get_cost() << endl; 
	
		item[count].display(); 
		
		cin.clear();
		cin.ignore(4095, '\n');  // this is to clear, and keep the program running. If not
	}                          // here, one would have to press enter to continue the program and
                             // it skips the set name part
  cout << "\nThis ends the Item program. Goodbye.\n";
  // system ("pause");
	return 0;
}   // end of main


// Test output below:
/*
This program will create up to 4 items and display them to the user.

Please enter the item's name: Video Games
Please enter the item's ID number: 1236
Please enter the amount of the item in stock: 10
Please enter the cost of the item: 3.00

According to your entry, there are 10 Video Games with ID# 1236 at $3.00
Name: Video Games; ID: 1236; Quantity: 10; Cost: $3.00; Total Cost: $30.00

Please enter the item's name: Apples
Please enter the item's ID number: 8975
Please enter the amount of the item in stock: 64
Please enter the cost of the item: 1.00

According to your entry, there are 64 Apples with ID# 8975 at $1.00
Name: Apples; ID: 8975; Quantity: 64; Cost: $1.00; Total Cost: $64.00

Please enter the item's name: Trash Compactors
Please enter the item's ID number: hde
Sorry, please try again.
Please enter the item's ID number: 5469
Please enter the amount of the item in stock: e
Sorry, please try again.
Please enter the amount of the item in stock: 2
Please enter the cost of the item: -100
Sorry, please try again.
Please enter the cost of the item: 100.00

According to your entry, there are 2 Trash Compactors with ID# 5469 at $100.00
Name: Trash Compactor; ID: 5469; Quantity: 2; Cost: $100.00; Total Cost: $200.00

Please enter the item's name: Shoes
Please enter the item's ID number: 6497
Please enter the amount of the item in stock: 50
Please enter the cost of the item: 5.00

According to your entry, there are 50 Shoes with ID# 6497 at $5.00
Name: Shoes; ID: 6497; Quantity: 50; Cost: $5.00; Total Cost: $250.00

This ends the Item program. Goodbye.

--------------------------------
Process exited after 125.5 seconds with return value 0
Press any key to continue . . .
*/
