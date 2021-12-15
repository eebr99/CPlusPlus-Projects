/*
  Name: Eric Blanco
  COSC 1337 Spring 2020 MW10
  Exam 2, Programming portion
  When complete: Change course designator in filename from DDHH to MW10
                 Change "Lastname" to your lastname.
  Upload file: TT10_X2_Lastname.cpp to BlackBoard Assignment link.
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/* INSTRUCTIONS: (OK to remove this big comment block, but keep smaller // comments.)

  PLEASE PLACE NEW CODE NEAR COMMENT LABELS, PROVIDED FOR EACH STEP.

  Step 1. (5 points)
    In class Purse, write two Purse constructors:
       default: set all coin counts to zero; do not allow the coin counts to be uninitialed.
       2nd:     set all coin counts to non-negative initial values; use parameters for:
                  quarter, dime, nickel, penny. To save time, you can use parameters: q, d, n, p.
                IMPORTANT: prohibit negative values - if negative coin value given, use 0 instead.
    Tip: you can combine both of these into one constructor using default parameters

  Step 2. (5 points)
    In main, in one statement, declare a new Purse object called purse and initialize
    purse with: 4 quarters, 3 dimes, 2 nickels, 1 penny
    
  Step 3. (5 points)
    In class Purse, write the definition for a new public member function: total_value.
    total_value returns the total value of all quarters, dimes, nickels and pennies
    in a Purse object. For example: a purse with 4 quarters, 3 dimes,
    2 nickels and 1 penny has a total value of (4*25)+(3*10)+(2*5)+(1*1)=141 (cents)
    This is a getter / accessor, and should be marked const.
    
  Step 4. (5 points)
    In main, write code to call the total_value method on the purse object.
    Display the returned value, which is the total value of the coins in purse.
    Format the output so it displays in dollars and cents. Example: $1.41
    Hint: setprecision, fixed
    
  Step 5. (5 points)
    In class Purse, implement a mutator/setter called set() which sets the
    coin counts of all coins. Pre-validate any new coin counts; do not allow any
    coin count to be less than zero. If the ANY of the coin counts are invalid
    (negative), do not modify ANY coin counts. If the set() succeeds, return true;
    if the set() fails, return false.
    
  Step 6. (5 points)
    To avoid redundant code and insure proper validation, modify constructor(s)
    as needed to call set() instead of having redundant checking code.

  Step 7. (5 points)
    In class Purse, write a show() method that outputs the number of each
    .coin in the purse in one string, like this: "(q=4 d=3 n=2 p=1)" (no endl or "\n")
    Another option is to return a string. The caller can cout the string. This way,
    class Purse is no longer dependent upon iostream.

  Step 8. (5 points)
    In main, call set to change the values in purse to: 8 quarters, 7 dimes, 6 nickels, 5 pennies.
    In main, call show to display the contents of purse (number of each coin).

  Step 9. (5 points)
    In class Purse, write a modify() method that modifies coin counts
    using a positive (increment), negative (decrement) or zero (keep the same)
    value. For example:
      purse.modify(0, 0, 2, -3) This will: keep quarters, dimes the same;
      increase nickels by 2, and decrease pennies by 3.
    IMPORTANT! Do not allow coin counts to become less than zero! If ANY coin will
    become negative, don't make any changes.
    If modify() succeeds, return true; if modify() fails, return false

  Step 10 (10 points)
    In main, write a menu driven loop that allows the user the add or remove coins from purse.
    In a loop, display the total value, coins and options. Use s to stop (q is for quarter). For example:
      $3.05 (q=8 d=7 n=6 p=5) Modify p)enny n)ickel d)ime q)uarter s)top: p -3
      $3.02 (q=8 d=7 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: n 0
      $3.02 (q=8 d=7 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: d 2
      $3.12 (q=8 d=9 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: q -4
      $2.12 (q=4 d=9 n=6 p=2) Modify p)enny n)ickel d)ime q)uarter s)top: s
    Use the provided get_value function to get the option letter and the count.
    Your user interface should look similar to example above.
    
    Important: Use if (cin >> x) checking so invalid numeric input does not cause crash or infinite loop.
         You can use get_input code developed earlier to provide one function for getting input. Required!

  Step 11 (5 points)
    Test your code as described above in Step 10 and paste the output at the bottom.

  Step 12 (5 points, EXTRA CREDIT)
    Create an array (or a vector) of 3 coin purses. Initialize the coin purses with these amounts:
    (No user input necessary, just construct instances with these coin amounts)
    purse 1: 1 quarters;  1 dimes;  1 nickles;   1 pennies (value $0.41)
    purse 2: 4 quarters; 10 dimes; 20 nickles; 100 pennies (value $4.00)
    purse 3: 100 quarters; 100 dimes; 100 nickles; 100 pennies (value $41.00)
    Write a loop that displays the purse number and it's amount; and the total of all, to appear as follows:
      purse 1 $0.41
      purse 2 $4.00
      purse 3 $41.00
      total: $45.41
*/

class Purse
{
  private:
    int quarters, dimes, nickels, pennies;
  public:
  //  Step 1) Write two Purse constructors:
  //    default: set all coin counts to zero
  //	Purse(){
  	//	quarters = 0;
  		//dimes = 0;
  		//nickels = 0;
  		//pennies = 0;
	//	}
  //    2nd:     set all coin counts to initial values; use parameters for: penny, nickel, dime, quarter
  Purse(int q = 0, int d = 0, int n = 0, int p = 0){  // combined both into one constructor
  	//quarters = (q >= 0) ? q : 0;
  	//dimes = (d >= 0) ? d : 0;
  	//nickels = (n >= 0) ? n : 0;
  	//pennies = (q >= 0) ? q : 0;
  	set(q, d, n, p);
	}
  //    please combine both of these into one constructor
  
  // Step 6) avoid redundant code, call set() in constructor(s)

 // Purse();
 // Purse(int, int, int, int);
  
  // Step 3) Write total_value to return total value of coins in Purse object
  int total_value() const{
		return (quarters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1);
	} // return total cents as int // getters should be marked as const
  
  // Step 5) Implement set() which modifies the coin counts
  bool set(int q, int d, int n, int p){
  	if ( q < 0 or d < 0 or n < 0 or p < 0)
  		return false;
  	else{
  	quarters = q;
  	dimes = d;
  	nickels = n;
  	pennies = q;
  	return true;
		}
	}
  
  // Step 7) write show() method that outputs the number of each coin in the purse
  //  in one string, like this: "q=4 d=3 n=2 p=1" (don't << endl;)
  void show() const{
	cout << "q=" << quarters << " d=" << dimes << " n=" << nickels
	     << " p=" << pennies;
	}

  // Step 9) write modify() method to modify coin counts using a positive (increment),
  // negative (decrement) or zero (keep the same) value.
  bool modify(int q, int d, int n, int p){
  	quarters = quarters - q;
  	dimes = dimes - d;
  	nickels = nickels - n;
  	pennies = pennies - p;
	}
};


template <typename T> // This is provided. Use it to get values from the user.
T get_value(const string &prompt="enter value: ",
            const string &errmsg="  invalid, try again\n",
            T value_min=-numeric_limits<T>::max(), T value_max=numeric_limits<T>::max());
// Hint: char option = get_value<char>("Modify p)enny n)ickel d)ime q)uarter s)top: ");


int main() {
  cout << "COSC 1337 Exam 2 Purse" << endl;

  // Step 2) declare Purse object called purse;
  // initialize with: 4 quarters, 3 dimes, 2 nickels, 1 penny
  double dollar{100};
  Purse purse;
  purse.set(4, 3, 2, 1);
  

  // Step 4) Call the total_value method on purse; display the result formatted as: $x.xx
	cout << setprecision (2) << fixed << "$" << purse.total_value() / dollar << endl;
  // Step 8) Call set to change values in purse to: 8 quarters, 7 dimes, 6 nickels, 5 pennies.
  //         Call show to display the contents of purse
  purse.set(8, 7, 6, 5);
	purse.show();
	cout << endl << endl;
  // Step 10) write menu driven loop that allows the user the add or remove coins from purse.
	bool running{true};	// creation of the loop with bool running
	while (running) 
	{
		cout << setprecision (2) << fixed << "$" << purse.total_value() / dollar << " ";
		purse.show(); 
		char option = get_value<char>(" Modify q)uarter d)ime n)ickel p)enny s)top: ");
		switch (tolower(option))
		{
			case 'q':{
				int change = get_value<int>();
				purse.modify(change, 0, 0, 0);
				break;	
			}
			case 'd':{
				int change = get_value<int>();
				purse.modify(0, change, 0, 0);
				break;	
			}
			case 'n':{
				int change = get_value<int>();
				purse.modify(0, 0, change, 0);
				break;		
			}
			case 'p':{
				int change = get_value<int>();
				purse.modify(0, 0, 0, change);
				break;
			}
			case 's':{
				running = false;
				break;
			}
			default:
			 // invalid option entered, display an error message
    	cout << "Sorry, you did not enter a valid option. Please try again." << endl;
    	cout << "\n";
  	}

  }	
  // Step 12 EXTRA CREDIT)  Create array or vector of 3 purses with initial coin amounts, display.
  //  purse 1: 1q1d1n1p; purse 2: 4q10d20n100p; purse 3: 100q100100n100p
  // Output from Step 12 appears AFTER user exits loop that modifies coins in single purse.
  
  cout<<endl<<"Goodbye!"<<endl; // this should appear as the last line of your output
  return EXIT_SUCCESS; // Use return 0 if EXIT_SUCCESS is undefined
}

template <typename T>
T get_value(const string &prompt="enter value: ",
            const string &errmsg="  invalid, try again\n",
            T value_min=-numeric_limits<T>::max(), T value_max=numeric_limits<T>::max()) {
  T value{};
  while (true) {
    if (prompt!="") cout<<prompt;
    if (cin>>value and value>=value_min and value <=value_max)
      return value;
    else {
      cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
      if (errmsg!="") cout<<errmsg;
    }
  }
}

/*  Step 11) Paste test output here (do this after step 12 if doing extra credit)
COSC 1337 Exam 2 Purse
$1.44
q=8 d=7 n=6 p=8

$3.08 q=8 d=7 n=6 p=8 Modify q)uarter d)ime n)ickel p)enny s)top: e
Sorry, you did not enter a valid option. Please try again.

$3.08 q=8 d=7 n=6 p=8 Modify q)uarter d)ime n)ickel p)enny s)top: q
enter value: 1
$2.83 q=7 d=7 n=6 p=8 Modify q)uarter d)ime n)ickel p)enny s)top: d
enter value: 1
$2.73 q=7 d=6 n=6 p=8 Modify q)uarter d)ime n)ickel p)enny s)top: n
enter value: 1
$2.68 q=7 d=6 n=5 p=8 Modify q)uarter d)ime n)ickel p)enny s)top: p
enter value: 1
$2.67 q=7 d=6 n=5 p=7 Modify q)uarter d)ime n)ickel p)enny s)top: s

Goodbye!

--------------------------------
Process exited after 25.56 seconds with return value 0
Press any key to continue . . .

*/

