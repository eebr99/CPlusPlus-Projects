//Eric Blanco
#include <iostream>
#include <string>

class Node {
	private:
    char item;
    Node * next;
	public:
    Node(char item) : item(item) , next(nullptr) {}

    int getItem() const {
        return item;
    }

    void setItem(char item) {
        Node::item = item;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }
};

class LinkedChar {
	private:
		std::string s;
		int itemcount;
		Node* head;
		
	public:
		LinkedChar();
		LinkedChar(const std::string s);
		int length()const;
		int index(char ch)const;
		void append(const LinkedChar& Ic);
		bool submatch(const LinkedChar& Ic)const;
	
};
//stubbing out code

LinkedChar::LinkedChar(){}

LinkedChar::LinkedChar(std::string word){

}

int LinkedChar::length()const{return itemcount;}

int LinkedChar::index(char ch)const{
	return 0;
}

void LinkedChar::append(const LinkedChar& Ic){
}

bool LinkedChar::submatch(const LinkedChar& Ic)const{
	bool okay = false;
	return okay;
}




int main(){
	LinkedChar word;
	bool running = true;
	std::cout << "This program accepts a string and displays its length, index of a certain char, appends, and submatches.";
	std::cout << "\nEnter an option:" << std::endl;
	while(running){
		char option;
		std::cout << " n)ew l)ength i)ndex a)ppend s)ubmatch q)uit: ";
		std::cin >> option;
			switch (tolower(option))
			{
				case 'n':{
					//here we would enter the new string into the class, string here is just to test

					break;	
				}
				case 'l':{
					//here we just call the length function and display.					

					break;	
				}
				case 'i':{

          //here we call the index function, sending char find.

					break;		
				}
				case 'a':{
					//here we append the string, using this as placeholder for now

					//word.append()
					break;
				}
				case 's':{
					//call submatch
					//word.submatch()
					break;

				}
				case 'q':{
					running = false;
					std::cout << "Goodbye!";
					break;
				}
				default:
			 	// invalid option entered, display an error message
    		std::cout << "Sorry, you did not enter a valid option. Please try again." << std::endl;
    		std::cout << "\n";
  		}
  }
  return 0;
}
