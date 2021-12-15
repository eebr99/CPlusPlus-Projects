// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 4
// Topic: Create a program that has a looping menu that performs as many
// calculations as the user wants that deals with finding out the time it 
// takes for sound to travel in air, water, or steel. This program should
// implement switch statements and create an enumerated type for the options.
/*
IPO Chart

INPUT
	a, for speed of sound in air
	w, for speed of sound in water
	s, for speed of sound in steel
	q, to quit the program
	user_distance, the distance the user wants to know how long it takes for
		sound to travel in the previously selected medium
PROCESSING
	use a switch statement instead of if else if
	if a, go into case 1 (air) and calculate the time it takes to travel in air
	if w, go into case 2 (water) and calculate time to travel in water
	if s, go into case 3 (steek) and calculate time to travel in steel
	if q, quit the program
	loop until the user wants to quit
OUTPUT
	display a greeting
	display the menu
	after choice selection, ask for distance traveled
	display time it takes for sound to travel in selected medium
	display menu again, until user quits
	when user quits, display a farewell message
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Material { Air = 'a', Water = 'w', Steel = 's', Quit = 'q' };
								//creation of the enum, "material" to avoid magic numbers
int main()
{
	const int AIR = 1100, WATER = 4900, STEEL = 16400;  // constants for the materials to make calculations more clear
	
	bool running{true};
  cout << "This program calculates the time it will take for sound to travel in air, water, or steel.\n"<< endl;														// creation of the loop with bool running
	while (running) 
	{
    cout<<"Options (enter one letter): a)ir w)ater s)teel q)uit: ";
    
		char option=' ';
  	cin >> option;
    
		switch (option) 
		{
			case Air: 
			{
				double user_distance;
				cout << "\nPlease enter the distance sound will travel in air: ";
				cin >> user_distance;
				while (user_distance < 0)					//validating input
				{
					cout << "ERROR: Please enter a value greater than or equal to zero: ";
					cin >> user_distance;
				} 
				cout << "Sound will travel " << user_distance << " feet in air in "
						 << user_distance / AIR << " seconds.\n" << endl;
				break;	
			}
			case Water:
			{
				double user_distance;
				cout << "\nPlease enter the distance sound will travel in water: ";
				cin >> user_distance;
				while (user_distance < 0)
				{
					cout << "ERROR: Please enter a value greater than or equal to zero: ";
					cin >> user_distance;
				}  
				cout << "Sound will travel " << user_distance << " feet in water in "
						 << user_distance / WATER << " seconds.\n" << endl;
				break;	
			}
			case Steel:
			{
				double user_distance;
				cout << "\nPlease enter the distance sound will travel in steel: ";
				cin >> user_distance;
				while (user_distance < 0)
				{
					cout << "ERROR: Please enter a value greater than or equal to zero: ";
					cin >> user_distance;
				} 
				cout << "Sound will travel " << user_distance << " feet in steel in "
						 << user_distance / STEEL << " seconds.\n" << endl;
				break;		
			}
			case Quit:
			{
				running = false;
				break;
			}
			default:
			 // invalid option entered, display an error message
    	cout << "Sorry, you did not enter a valid option. Please try again." << endl;
    	cout << "\n";
		}
	}	
	cout << "\nGoodbye!";
	
	return 0;		
}
/*
This program calculates the time it will take for sound to travel in air, water, or steel.

Options (enter one letter): a)ir w)ater s)teel q)uit: g
Sorry, you did not enter a valid option. Please try again.

Options (enter one letter): a)ir w)ater s)teel q)uit: a

Please enter the distance sound will travel in air: -9874
ERROR: Please enter a value greater than or equal to zero: 9874
Sound will travel 9874 feet in air in 8.97636 seconds.

Options (enter one letter): a)ir w)ater s)teel q)uit: w

Please enter the distance sound will travel in water: 7845
Sound will travel 7845 feet in water in 1.60102 seconds.

Options (enter one letter): a)ir w)ater s)teel q)uit: s

Please enter the distance sound will travel in steel: 123334
Sound will travel 123334 feet in steel in 7.52037 seconds.

Options (enter one letter): a)ir w)ater s)teel q)uit: q

Goodbye!
--------------------------------
Process exited after 40.58 seconds with return value 0
Press any key to continue . . .
*/
