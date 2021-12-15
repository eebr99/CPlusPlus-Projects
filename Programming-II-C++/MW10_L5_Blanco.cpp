// Author: Eric Blanco
// Course: COSC 1337 Spring 2020 MW10; Instructor: Thayer
// Assignment: Lab 5
// Topic: Create a program that reads in the data file people.txt and reads 
// until the end of the file, taking the population data read in and 
// displays it as a bar chart showing population growth.
/*
IPO Chart

INPUT
	inFile, as a const string, used to read in data
	population, as the number of people that year
	starNum, the count variable that controls the for loop
	year, for the year corresponding to the population
	read in all the data and store appropriately in population variable
		for each year
PROCESSING
	handle error if file is not found
	open file
	read in data
	use data to display a bar chart
OUTPUT
	display error message if file is not found, and the name of the file
	display the bar chart with appropriate and clear labels, such as the 
		year, the location, what the graph is showing, and the significance
		of each star with relation to the population
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>			// needed to use files (read, write)
using namespace std;

int main()
{
	const string IN_FILE_NAME = "people.txt"; // using a constant so file name doesn't get confused
	
	ifstream inFile(IN_FILE_NAME); 						//variable type, name, and value all in one line
																						// for reading the file
	if (inFile)				//file is being read
	{
		cout << "This program will take the population data from " << IN_FILE_NAME 
					<< " and display it in a bar graph.\n";
		
		cout << "\nFLATROCK CITY POPULATION GROWTH\n";
		cout << "(each * represents 1000 people)\n";
		
		int population, starNum, year = 1900; // variables needed for the chart
				
		while (!inFile.eof())
		{
			//int population, starNum, year = 1900;
			inFile >> population;
			population /= 1000;				//dividing population by value of star
			
			if (inFile.eof())				//if file is completely read, exit
				break;
			
			cout << "\n" << year << " ";
			
			for (starNum = 1; starNum <= population; starNum++)		//displaying stars for population
				cout << "*";			
			
			year += 20; 		//changing the year variable show passage of time			
		}
		cout << endl;
		inFile.close(); 			//closed file
	}
	else // file did not read
		cout << "Sorry, but the file: " << IN_FILE_NAME << " could not open.\n ";		
	return EXIT_SUCCESS;
}
/*
This program will take the population data from people.txt and display it in a bar graph.

FLATROCK CITY POPULATION GROWTH
(each * represents 1000 people)

1900 **
1920 ****
1940 *****
1960 *********
1980 **************
2000 ******************
2020 ********************
2040 ***********************
2060 **********************
2080 *

--------------------------------
Process exited after 0.2937 seconds with return value 0
Press any key to continue . . .
*/
