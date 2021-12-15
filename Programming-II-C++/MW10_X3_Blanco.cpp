/*
  COSC 1337 Exam 3 Lab portion Spring 2020
  Name:
  Filename:
    before submitting, change the file name
      from: DDHH_X3_Lastname.cpp
      to:   <your course designator>_X3_<your last name>.cpp
      where DDHH is the days, hours your course meets (example: MW10, TT17)
      -or-  DDHH is the distance learning section (example: DL5)
      
    NOTE: In devcpp, compiler options (Tools -> Compiler Options) must have: -std=c++14
    otherwise, you may get this error:
    [Warning] extended initializer lists only available with -std=c++14 or -std=gnu++14 
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Product { // This is used for step 1 and step 2; leave as is.
  string name;
  double price;
  string made_in;
  int weight;
};

/*
  Don't be alarmed by struct Product
  A struct is like a class, except that all members are public by default
  This is the same as saying:
class Product {
  public:
    string name;
    double price;
    string made_in;
    int weight;
};
*/

// Put class Item definition code for steps 1 an 2 here.
class Item {
		private:
			string name{};
			double price{};
		public:
			Item(string n, double p){
				if(sizeof(n) >= 1)
					name = n;
				else
					name = "generic";
					
				if(p >= 1)
					price = p;
				else
					price = 1.00;
			}


			void display_item(){
				cout <<  name << " " << setprecision (2) << fixed
					 << price << endl;
			}
	};
void step1() {
  // ------------------ section below is provided, do not change, it is called from main
  // The section between the lines is provided startup code for step 1. DO NOT CHANGE UNLESS COMPILER ERROR.
  // Below, a std::vector is used. It works as-is.
  // It creates an vector (similar to array) as described in the instructions. It provides
  // intial startup data for you to save time. Use this data to load your store with items.

  vector<Product> warehouse {
    {"hat", 8.00, "china", 6},
    {"t-shirt", 15.00, "usa", 14},
    {"coffee mug", 6.50, "canada", 22},
    {"candy bar", 0.79, "mexico", 3},
    {"", 34.59, "japan", 122},
    {"mixing bowl", 4.99, "brazil", 20}
  };
   
  cout<<"Step 1:\n";
  cout<<"Contents of vector warehouse, already loaded:\n";
  for (auto &item:warehouse) { // If this does not compile, see the note below
  // The section above is provided startup code. DO NOT CHANGE UNLESS COMPILER ERROR
  // If for (auto &t:warehouse) code has a compilation error, do this:
  //   1) recommended: enable C++11/14 features on your compiler with option: -std=c++11
  //   2) alternative: change to a regular for loop: for (int i=0; i<warehouse.length(); ++i), etc.
    cout<<setw(12)<<item.name<<setw(8)<<item.price<<setw(8)<<item.made_in<<setw(6)<<item.weight<<endl;
  }
  cout<<endl;  
  // --------------section above code is provided, do not change
  
  // --------------section below is needed, add your code below
  // Put your new code for step 1 here, it will be called from main:
	
	//create an array of Items called "store":
//	Item store[];
	//create a loop to display the contents of array store, probably a for loop
	for(int count = 0; count <7; count++){
		//display function
	}
	
}


void step2() {
  cout<<"Step 2:\n";
  // Put all your code for step 2 here, it will be called from main:
	Item* item_ptr = new Item("umbrella", 19.95);
	cout << "the black umbrella is at address: " << item_ptr << endl;
	item_ptr->display_item();
	delete [] item_ptr; // stop leak
	item_ptr = nullptr; // reset
}


// Step 3: The initial code for class Fraction is provided. You will add to it further down...
class Fraction {
  // A fraction can be written as: top/bot (numerator/denominator), such as: 1/3, 2/7, etc.
  // A Fraction can store a ratio exactly with no round-off error.
  // SAVE TIME - NO NEED TO WRITE ADDITIONAL SETTERS AND GETTERS
  private:
    int top=0; // numerator
    int bot=1; // denominator
  public:
    Fraction(int top=0, int bot=1) {
      if (bot != 0) { // guard against division by 0
        this->top = top;
        this->bot = bot;
      }
    }
    double get() const { // converts the "ratio" or "Fraction" into a double
      return top/static_cast<double>(bot);
    }
    
    // Put new code for step 3 here:
};
  
void step3() {
  cout<<"Step 3:\n";
  // NO NEED TO IMPLEMENT POST-FIX! Implement pre-fix: ++a, not post-fix: a++
  // This is testing code for step 3; it will be called from main.
  // After you have implemented: operator++, operator--, and operator*,
  // Uncomment the code below. It should work.
  // Fraction a=4; ++a; ++a; cout<<"a="<<a.get()<<endl; // test code, expect: 6, uncomment when ready
  // Fraction b=5; --b; --b; cout<<"b="<<b.get()<<endl; // test code, expect: 3, uncomment when ready
  // Fraction c=6, d=7, e=c*d;                          // test code, uncomment when ready
  // cout<<"e="<<e.get()<<endl<<endl;                   // test code, expect: 42, uncomment when ready
  
  // add code here to initialize Fraction evens[] with 2 4 6 8 10 and display its contents
};

// The code below is for optional extra-credit step 4, recursion
// This code may be helpful when developing your recursive functions.
void recurse(int times_to_call) {
  // a generalized recursion outline; has 5 locations to do work...
  cout << "recurse head... " << "("<<times_to_call<<") " <<endl; // ALWAYS
  if (times_to_call>1) { // decision to recursive call
    cout << "recurse before call... " << "("<<times_to_call<<") " <<endl;
    recurse(times_to_call-1); // work (problem simplification) can be done inside the parameter list!
    cout << "recurse after call... " << "("<<times_to_call<<") " <<endl;
  } else {
    cout << "recurse else option... " << "("<<times_to_call<<") " <<endl;
  }
  cout << "recurse ...tail " << "("<<times_to_call<<") " <<endl; // ALWAYS
}

// Below are working iterative versions of line, left_arrow, right_arrrow, double_arrow
void line_iterative(int n) { // Provided, do not change
  for (int i=0; i<n; ++i)
    cout<<"-";
}

// For the line drawing functions, argument n is passed in; if:
//   n < 0,  output nothing
//   n == 0, output arrows only, if any
//   n > 0,  output arrows and n dashes
// See output from provided iterative versions, recursive versions should match

void left_arrow_iterative(int n) { // Provided, do not change
  if (n>=0)
    cout<<"<";
  for (int i=0; i<n; ++i)
    cout<<"-";
}

void right_arrow_iterative(int n) { // Provided, do not change
  for (int i=0; i<n; ++i)
    cout<<"-";
  if (n>=0)
    cout<<">";
}

void double_arrow_iterative(int n) { // Provided, do not change
  if (n>=0)
    cout<<"<";
  for (int i=0; i<n; ++i)
    cout<<"-";
  if (n>=0)
    cout<<">";
}

// Put your new recursive versions for step 4 here...
void line_recursive(int n) {
   // fill this in with recursive code for line
   // Call line_recursive(int n), but NO OTHER FUNCTION

}

void left_arrow_recursive(int n) {
   // fill this in with recursive code for left_arrow
   // Call left_arrow_recursive(int n), but NO OTHER FUNCTION   

}

void right_arrow_recursive(int n) {
   // fill this in with recursive code for right_arrow
   // Call right_arrow_recursive(int n), but NO OTHER FUNCTION      

}

void double_arrow_recursive(int n) {
  // This one is a challenge. Hint: add another optional parameter with default
  // fill this in with recursive code for double_arrow
   // Call double_arrow_recursive(int n), but NO OTHER FUNCTION     

}

void step4() {
  // Below is testing code for step 4; it will be called from main. No changes needed.
  // recurse(3); // call to recurse example for experimentation, if desired
  cout<<"\nStep 4: (optional extra credit)\n";
  cout<<"Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:\n";
  // for (int n=1; n<=5; ++n) { // test provided iterative functions
  for (int n=-5; n<=5; ++n) { // test provided iterative functions
    cout<<"n="<<setw(2)<<n<<":";
    line_iterative(n); cout<<' ';
    left_arrow_iterative(n); cout<<' ';
    right_arrow_iterative(n); cout<<' ';
    double_arrow_iterative(n); cout<<endl;
  }
  cout<<"\nTest student's new recursive versions of line, left_arrow, right_arrow, double_arrow:\n";
  for (int n=-5; n<=5; ++n) { // test student's new recursive functions
    cout<<"n="<<setw(2)<<n<<":";
    line_recursive(n); cout<<' ';
    left_arrow_recursive(n); cout<<' ';
    right_arrow_recursive(n); cout<<' ';
    double_arrow_recursive(n); cout<<' '<<endl; // EXTRA CREDIT
  }
};

void step5() { // EXTRA CREDIT
  // 5 different ways to cause undefined behavior, and possibly crash a C++ program.
  // in main, step5() is commented out.
  // To verify your bad code is really bad, test it by uncommenting step5() in main.
  cout<<"Step 5: (optional extra credit)\n";
  // Put all your code for step 5 here:


};

int main() {
  // No new code goes in main. Put all new code where designated in the steps above.
  cout<<"Start...\n";
  step1();
  step2();
  step3();
  step4();
  // step5();  // EXTRA CREDIT: 5 ways to possibly crash a C++ program
  cout<<"\n...end.\n";
	return 0;
}

/* Original startup code test output:
Start...
Step 1:
Contents of vector warehouse, already loaded:
         hat       8   china     6
     t-shirt      15     usa    14
  coffee mug     6.5  canada    22
   candy bar    0.79  mexico     3
               34.59   japan   122
 mixing bowl    4.99  brazil    20

Step 2:
Step 3:

Step 4: (optional extra credit)
Test provided iterative versions of line, left_arrow, right_arrow, double_arrow:
n=-5:
n=-4:
n=-3:
n=-2:
n=-1:
n= 0: < > <>
n= 1:- <- -> <->
n= 2:-- <-- --> <-->
n= 3:--- <--- ---> <--->
n= 4:---- <---- ----> <---->
n= 5:----- <----- -----> <----->

Test student's new recursive versions of line, left_arrow, right_arrow, double_arrow:
n=-5:
n=-4:
n=-3:
n=-2:
n=-1:
n= 0:
n= 1:
n= 2:
n= 3:
n= 4:
n= 5:

...end.

--------------------------------
Process exited after 0.03929 seconds with return value 0
Press any key to continue . . .
*/


/* Paste your test output here:

*/
