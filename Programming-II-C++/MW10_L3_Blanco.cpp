// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 3
// Topic: Create a program for a 3rd grade math tutor that provides simple
// addition questions in the range 0 to 100 inclusive as many times as the
// user wants.
/*
IPO Chart

INPUT
	num_question, for the number of questions to be generated
	answer, to quit the program, will be a sentinel, using a negative number
		if not, it will be the answer to the question
PROCESSING
	have a loop
	generate questions using numbers in the range [0, 100]
	take user answer
	if user answer is a positive number, continue generating questions
		or until max questions is reached
	if user input is a negative number, quit the program
OUTPUT
	display a greeting and quick intro to the program
	take the number of questions wanted and display that many one by one
	keep displaying questions and taking input until max reached or sentinel is
		entered
	quit the program
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <random>
using namespace std;

int main()
{
	const int MIN = 0,			//min and max values of the numbers to be used
						MAX = 100;
					
	unsigned seed;
	seed = time(0);					// for the random numbers
	srand(seed);
	
	int num_times{}, num_question{}; //number of times loop will run, and number of questions wanted
	
	cout << "Welcome!\nToday we will be adding numbers!\n";
	cout << "(If at anytime you wish to quit, please enter -1.)" << endl;
	cout << "\nPlease enter the amount of questions you would like: ";
	cin >> num_question;
	
	for (num_times = 1; num_times <= num_question;)
		{
			int rand1 = (rand() % (MAX - MIN +1)) + MIN,			//random numbers to use for the questions
					rand2 = (rand() % (MAX - MIN +1)) + MIN,      
					answer {};
				
		double sum = rand1 + rand2; 		// the sum of both random numbers
		
		if (sum > 100)								// to validate numbers used for questions
			{
				num_times = num_times;
			}
		else if (sum <= 100 and sum >= 0) 		//with validated random numbers, continue with the actual program
			{
				cout << "\nWhat is "<< rand1 << " + " << rand2 << " ? ";
				cin >> answer;
				if (answer != -1)										// sentinel value 
				{
					cout << "You entered: " << answer << endl;
					cout << "The answer is: " << rand1 + rand2 << endl;
					num_times++;
				}
				else				//sentinel value of "-1" entered, so loop is exited
					break;
			}

		}
	
	cout << "\nGoodbye! Keep on studying!";
	return 0;
	
}
/*
Welcome!
Today we will be adding numbers!
(If at anytime you wish to quit, please enter -1.)

Please enter the amount of questions you would like: 7

What is 0 + 86 ? 86
You entered: 86
The answer is: 86

What is 36 + 3 ? 55
You entered: 55
The answer is: 39

What is 27 + 20 ? 64
You entered: 64
The answer is: 47

What is 72 + 18 ? 100
You entered: 100
The answer is: 90

What is 85 + 12 ? 97
You entered: 97
The answer is: 97

What is 30 + 10 ? -1

Goodbye! Keep on studying!
--------------------------------
Process exited after 46.75 seconds with return value 0
Press any key to continue . . .
*/




























