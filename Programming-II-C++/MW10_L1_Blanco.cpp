// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 1
// Topic: This program displays a piece of advice, 
//calculates BMI, and check, with a handy UI
/*
IPO Chart

INPUT
	a, b, or c char to select an option
	q to exit the loop and program
	height
	weight
	cost of food
	tip percentage
PROCESSING
	Bring up user interface
	determine what character was entered and proceed
	if b, store height and weight
	calculate bmi
	if c, store cost and tip rate
	calculate check
OUTPUT
	if a, display advice
	if b, display bmi
	if c, display check
	if q, quit
	if any other character, display error message
*/
#include <iostream>  // cout, cin, endl ...
#include <iomanip>
using namespace std;

int main()
{
	cout << "Hi!\nUpon your decison, I will give you a piece of advice,";
	cout << " calculate your BMI, or calculate your check." << endl;
	cout << "\n";
	while (true) 
	{
      cout<<"Options (enter one letter): a)dvice b)mi c)heck q)uit: ";
      char option=' ';
      cin >> option;
      if (option=='a') 
	  {
          // provide advice.
          cout << "  Simply eating well and working out will do wonders for you.\n";
          cout << "\n";
      }
      else if (option=='b') 
	  {
          // compute and display the BMI
          int weight{0};
          cout << "  Please enter your weight in pounds. ";
          cin >> weight;
          
          int height{0};
          cout << "  Please enter your height in inches. ";
          cin >> height;
          
          double BMI{0};
          BMI = (static_cast<double>(weight) / (height * height)) * 703;
          cout << "  Your calculated BMI is " << BMI << endl;
          cout << "\n";
      }
      else if (option=='c') 
	  {
          // compute and display check amount
          const double TAX_RATE = 0.0825;
		  
		  double cost{0};
          cout << "  Please enter the cost of your food: ";
          cin >> cost;
          
          double tip{0};
          cout << "  Please enter the tip percent (10 = %10): ";
          cin >> tip;
          tip = tip / 100;
          
          double check{0};
          check = cost + (cost * TAX_RATE) + ((cost + (cost * TAX_RATE)) * tip);    //decided to take the tip from the cost + the tax, since I see most places doing that.
          cout << "  Your check comes out to $" << setprecision(5) << check << endl;
          cout << "\n";
          
          
      }
      else if (option=='q')
          break;
      else
          // invalid option entered, display an error message
          cout << "  Sorry, please enter either a, b, c, to proceed, or q to exit." << endl;
          cout << "\n";
          ;
  }
	cout << "  Thanks for stopping by!";
}


/*
Hi!
Upon your decison, I will give you a piece of advice, calculate your BMI, or calculate your check.

Options (enter one letter): a)dvice b)mi c)heck q)uit: a
  Simply eating well and working out will do wonders for you.


Options (enter one letter): a)dvice b)mi c)heck q)uit: b
  Please enter your weight in pounds. 100
  Please enter your height in inches. 50
  Your calculated BMI is 28.12


Options (enter one letter): a)dvice b)mi c)heck q)uit: c
  Please enter the cost of your food: 100
  Please enter the tip percent (10 = %10): 15
  Your check comes out to $124.487


Options (enter one letter): a)dvice b)mi c)heck q)uit: w
  Sorry, please enter either a, b, c, to proceed, or q to exit.

Options (enter one letter): a)dvice b)mi c)heck q)uit: q
  Thanks for stopping by!
--------------------------------
Process exited after 16.37 seconds with return value 0
Press any key to continue . . .
*/
