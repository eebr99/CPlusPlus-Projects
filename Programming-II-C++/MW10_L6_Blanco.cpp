// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 6
// Topic: This program displays the distance between two items: letters, 
// numbers, or points on a graph; all while using 3 overloaded functions
// to get the input, calculate the distance between the two items and to 
// display the result, for a total of 9 functions.
/*
IPO Chart

INPUT
	char option, for menu selection
	char letter1, letter2, for letters to be sent to int dist()
	double num1, num2, for numbers to be sent to double dist()
	double point_x1, point_y1, point_x2, point_y2, 
		for points to be sent to double dist()
PROCESSING
	define 3 groups of 3 overloaded functions for a total of 9 functions
	have program run and enter a while loop
	determine if option entered is valid, if not, loop and ask again
	if option entered is valid, enter switch, and enter corresponding case
	get input with corresponding input function and return
	use input from function in distance function to calculate distance
	use static local variable to count # times function was called
OUTPUT
	display greeting and brief overview of program
	display the option menu
	if invalid option, display error message and then option menu again
	display input prompts
	if invalid option, display error message, and try for another value
	display the distance between the selected item
	display the number of times the function was called
	display farewell message
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
// creating our functions:

// input function for letter input
char input(string prompt = "Input: ", const string &errmsg = "  Error, please enter a letter.")
{
	while(true)
	{
		cout << prompt;
		char input{};
		cin >> input;
		if(isalpha(input)) //checking to make sure input is a letter
			return input;
		else
		{
			cout << errmsg << endl; //error message, and prevents infinite loop
			cin.clear();
			cin.ignore(4095, '\n');
		}
	}
}

//input function for number input
double input(double min_num, double max_num, 
string prompt, const string &errmsg)
{
	while(true)
	{
		cout << prompt;
		double input{};
		if(cin >> input)
		{
		
			if(input > min_num and input < max_num) //validating number in range
				return input;
			else
				cout << errmsg << endl;
		}
		else
		{
			cout << errmsg << endl;
			cin.clear();
			cin.ignore(4095, '\n');
		}
	}
}

//input function for point on a graph input
void input(double &x, double &y, string prompt)
{
	bool running = true;
	while(running)
	{
		cout << prompt;	//validating correct data was entered
		if(cin >> x)
		{
			if (x > -100 and x < 100) //validating point in range
				running = false;
			else
			{
				cout<<"  Please enter a number point in range (-100 to 100)."<<endl;
  			cin.clear();
  			cin.ignore(4095, '\n');				
			}
		}
		else 
		{
  		cout<<"  Please enter a number point in range (-100 to 100)."<<endl;
  		cin.clear();
  		cin.ignore(4095, '\n');
		}
	}
}

//dist function to calculate the distance between two letters
int dist(char a, char b)
{
	char distance = abs(toupper(a) - toupper(b)); //changing chars to upper
	if(distance > 13)							//calculating distance between letters
		distance = 26 - distance;
	return distance;
}

// dist function to calculate the distance between two numbers
double dist(double d1, double d2)
{
	return abs(d1-d2); //return distance between points
}

//dist function to calculate the distance between two points
double dist(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x2-x1),2) + pow((y2-y1),2)); //return result of distance formula
}

//display function to display distance of letters and count of function call
void display(const string &msg, char ch1, char ch2) //const strings
{
	static int numCalls = 0;		//to count the function calls
	cout << " (#" << ++numCalls << ")" << msg << ch1 << " and " << ch2 
			 << " is " << dist(ch1, ch2) << endl;
}

// display function to display distance between 2 numbers and count of calls
void display(const string &msg, double d1, double d2)
{
	static int numCalls = 0; //counting function calls
	cout << " (#" << ++numCalls << ")" << msg << d1 << " and " << d2 
			 << " is " << dist(d1, d2) << endl;
}

//display function to display distance between 2 points and count of calls
void display(const string &msg, double x1, double y1, double x2, double y2)
{
	static int numCalls = 0;
	cout << " (#" << ++numCalls << ")" << msg << x1 << "," << y1 
			 << ") and (" << x2 << "," << y2 << ") is: " << dist(x1, y1, x2, y2)
			 << endl;
}
//*******************************************************************************************
//main function

int main()
{
	cout << "Hello! This program will tell you the distance between two letter, numbers, or points.\n";
	bool running{true};	//initiating loop
	while (running)
	{
		cout<<"\nOptions (enter one letter): l)etter n)umber p)oint q)uit: ";
		char option=' ';
		cin>>option;
		switch (tolower(option)) //entering switch
		{
			case 'l': //send arguments to functions with matching parameters
				{
					string prompt = " Enter a letter (a-z): ",
								 msg    = " Distance between letters ";
					
					char letter1 = input(prompt),
							 letter2 = input(prompt);
					display(msg, letter1, letter2); //displays, but also has calculation
					break;														//inside function with dist()
				}
			case 'n':
				{
					double min = -100, 
								 max = 100;
					string prompt = " Enter a number in range (-100 to 100): ",	//strings to 
								 errmsg = "  Please enter a number in the range.",	//send to
								 msg = "Units between ";													//functions
					double num1 = input(min, max, prompt, errmsg); 
					double num2 = input(min, max, prompt, errmsg);
					display(msg, num1, num2);
					break;
				}
			case 'p':
				{
					double x = 0, y = 0;
					string prompt_x1 = " Enter the first point (x): ",
								 prompt_y1 = " Enter the first point (y): ",
								 prompt_x2 = " Enter the second point (x): ",
								 prompt_y2 = " Enter the second point (y): ",
								 msg       = "Straight line distance between points (";
					input(x, y, prompt_x1);
					double x1 = x;
					input(x, y, prompt_y1);				//getting the value for each number in the
					double y1 = x;								// two points, so call function
					input(x, y, prompt_x2);
					double x2 = x;
					input(x, y, prompt_y2);
					double y2 = x;
					display(msg, x1, y1, x2, y2);
					break;
				}
			case 'q':
				running = false;	//exit loop
				break;
			
			default:
				//invalid option, display an error message
				cout << " Invalid option, try again." << endl;
		}
	}
	cout << " Goodbye! Come back soon!";
	return 0;
}
/*
Hello! This program will tell you the distance between two letter, numbers, or points.

Options (enter one letter): l)etter n)umber p)oint q)uit: o
 Invalid option, try again.

Options (enter one letter): l)etter n)umber p)oint q)uit: l
 Enter a letter (a-z): 45
  Error, please enter a letter.
 Enter a letter (a-z): a
 Enter a letter (a-z): c
 (#1) Distance between letters a and c is 2

Options (enter one letter): l)etter n)umber p)oint q)uit: n
 Enter a number in range (-100 to 100): u
  Please enter a number in the range.
 Enter a number in range (-100 to 100): -1001
  Please enter a number in the range.
 Enter a number in range (-100 to 100): 5
 Enter a number in range (-100 to 100): 9
 (#1)Units between 5 and 9 is 4

Options (enter one letter): l)etter n)umber p)oint q)uit: p
 Enter the first point (x): t
  Please enter a number point in range (-100 to 100).
 Enter the first point (x): 988
  Please enter a number point in range (-100 to 100).
 Enter the first point (x): 0
 Enter the first point (y): 4
 Enter the second point (x): 4
 Enter the second point (y): 4
 (#1)Straight line distance between points (0,4) and (4,4) is: 4

Options (enter one letter): l)etter n)umber p)oint q)uit: l
 Enter a letter (a-z): a
 Enter a letter (a-z): d
 (#2) Distance between letters a and d is 3

Options (enter one letter): l)etter n)umber p)oint q)uit: n
 Enter a number in range (-100 to 100): -20
 Enter a number in range (-100 to 100): 20
 (#2)Units between -20 and 20 is 40

Options (enter one letter): l)etter n)umber p)oint q)uit: p
 Enter the first point (x): 0
 Enter the first point (y): 9
 Enter the second point (x): 12
 Enter the second point (y): 9
 (#2)Straight line distance between points (0,9) and (12,9) is: 12

Options (enter one letter): l)etter n)umber p)oint q)uit: q
 Goodbye! Come back soon!
--------------------------------
Process exited after 126.5 seconds with return value 0
Press any key to continue . . .
*/
